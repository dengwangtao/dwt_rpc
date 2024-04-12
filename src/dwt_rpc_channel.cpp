#include "dwt_rpc_channel.h"
#include "dwt_rpc_application.h"

#include <cstdio>
#include <vector>
#include <string>
#include "rpcheader.pb.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

void DwtRpcChannel::CallMethod(
        const google::protobuf::MethodDescriptor* method,
        google::protobuf::RpcController* controller, const google::protobuf::Message* request,
        google::protobuf::Message* response, google::protobuf::Closure* done
) {

// 数据序列化 + 网络发送

    const google::protobuf::ServiceDescriptor* service_desc = method->service(); // 获取服务
    std::string service_name = service_desc->name();
    std::string method_name = method->name();

    int args_size = 0;
    std::string args_str;
    if(request->SerializeToString(&args_str)) {
        args_size = args_str.size();
    } else {
        std::cout << "request SerializeToString Error" << std::endl;
        if(controller) {
            controller->SetFailed("request SerializeToString Error");
        }
        return;
    }

    dwt::RpcHeader header;
    header.set_service_name(service_name);
    header.set_method_name(method_name);
    header.set_args_size(args_size);

    uint32_t header_size = 0;
    std::string header_str;
    if(header.SerializeToString(&header_str)) {
        header_size = header_str.size();
    } else {
        std::cout << "Header SerializeToString Error" << std::endl;
        if(controller) {
            controller->SetFailed("Header SerializeToString Error");
        }
        return;
    }

    // 网络发送
    int tot_len = 4 + header_size + args_size;
    std::vector<char> tobe_send(tot_len);

    // header_size(4字节) + header(服务名,方法名,参数长度) + 远程方法参数
    memcpy(&tobe_send[0], (char*)&header_size, sizeof(uint32_t));
    memcpy(&tobe_send[sizeof(uint32_t)], &header_str[0], header_size);
    memcpy(&tobe_send[sizeof(uint32_t) + header_size], &args_str[0], args_size);



    // 网络发送
    int cfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(cfd == -1) {
        perror("socket");
        close(cfd);
        if(controller) {
            controller->SetFailed("create socket error");
        }
        return;
    }

    uint16_t port = std::stoi(DwtRpcApplication::getConfig().Get("rpcserver_port"));
    const char* ip = DwtRpcApplication::getConfig().Get("rpcserver_ip").c_str();
    // std::cout << "Address: " << ip << ":" << port << std::endl;

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);
    
    int res = connect(cfd, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if(res == -1) {
        perror("connect");
        close(cfd);
        if(controller) {
            controller->SetFailed("connect error");
        }
        return;
    }

    res = write(cfd, &tobe_send[0], tot_len);
    if(res == -1) {
        perror("write");
        close(cfd);
        if(controller) {
            controller->SetFailed("send error");
        }
        return;
    }


    // 发送完毕, 接收响应
    std::vector<char> recv_buf(1024);
    res = read(cfd, &recv_buf[0], 1024); // 返回收到字节数长度
    if(res == -1) {
        perror("read");
        close(cfd);
        if(controller) {
            controller->SetFailed("recv error");
        }
        return;
    }

    std::string respose_str(recv_buf.begin(), recv_buf.begin() + res);
    // 反序列化

    if(!response->ParseFromString(respose_str)) {
        std::cout << "response ParseFromString Error" << std::endl;
        if(controller) {
            controller->SetFailed("response ParseFromString Error");
        }
    }

    close(cfd);
}