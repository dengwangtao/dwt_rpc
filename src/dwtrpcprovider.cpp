#include "dwtrpcprovider.hpp"
#include "dwtrpcapplication.hpp"
#include "rpcheader.pb.h"

#include <google/protobuf/descriptor.h>
#include <muduo/base/Logging.h>


void DwtRpcProvider::NotifyService(::google::protobuf::Service *service) {

    // 发布远程调用方法. 反射

    ServiceInfo service_info;

    const google::protobuf::ServiceDescriptor* desc = service->GetDescriptor();
    std::string service_name = desc->name(); // 获取服务名


    int method_cnt = desc->method_count(); // 获取方法数量

    for(int i = 0; i < method_cnt; ++ i) {
        const google::protobuf::MethodDescriptor* m_desc = desc->method(i);
        std::string method_name = m_desc->name();
        service_info.m_methodMap[method_name] = m_desc;
    }

    service_info.m_service = service;
    m_serviceMap[service_name] = service_info;
}


void DwtRpcProvider::Run() {
    
    muduo::net::InetAddress addr(
        DwtRpcApplication::getConfig().Get("rpcserver_ip"),             // IP
        std::stoi(DwtRpcApplication::getConfig().Get("rpcserver_port")) // Port
    );
    // tcpserver
    muduo::net::TcpServer server(&m_eventloop, addr, "dwt_rpc");

    // 绑定连接回调
    server.setConnectionCallback(
        std::bind(&DwtRpcProvider::onConnection, this, std::placeholders::_1)
    );


    server.setMessageCallback(
        std::bind(
            &DwtRpcProvider::onMessage, this, std::placeholders::_1,
            std::placeholders::_2, std::placeholders::_3)
    );

    server.setThreadNum(4);
    
    server.start();     // 启动
    m_eventloop.loop(); // 启动事件循环

    // one loop per thread
}


void DwtRpcProvider::onConnection(const muduo::net::TcpConnectionPtr& conn) {
    if(!conn->connected()) {
        conn->shutdown(); // 断开连接
    }
}

void DwtRpcProvider::onMessage(
    const muduo::net::TcpConnectionPtr& conn,
    muduo::net::Buffer* buffer,muduo::Timestamp time
) {

    std::string buf = buffer->retrieveAllAsString(); // 拿到所有数据
    // 前四个字节表示 header的长度

    uint32_t header_size = 0;
    // buf.copy(reinterpret_cast<char*>(&header_size), sizeof(uint32_t), 0);
    memcpy((char*)&header_size, &buf[0], sizeof(uint32_t));

    // 头部信息
    dwt::RpcHeader rpcheader;
    std::string service_name; // 服务名
    std::string method_name;  // 方法名
    int args_size; // 参数长度

    std::string args_str; // 调用方法的参数

    if( rpcheader.ParseFromString(buf.substr(sizeof(uint32_t), header_size)) ) {// 从第4字节开始, 拷贝头部
        service_name = rpcheader.service_name();
        method_name = rpcheader.method_name();
        args_size = rpcheader.args_size();

        args_str = buf.substr(sizeof(uint32_t) + header_size, args_size);

    } else {
        // 头部格式化失败
        LOG_ERROR << "header format error";
        return;
    }

    LOG_INFO << "=========================";
    LOG_INFO << "header_size: "  << header_size;
    LOG_INFO << "service_name: "  << service_name;
    LOG_INFO << "method_name: "  << method_name;
    LOG_INFO << "args_size: "  << args_size;
    LOG_INFO << "header_size: "  << header_size;
    // LOG_INFO << "args_str: "  << args_str;
    LOG_INFO << "=========================\n";

    
    if(!m_serviceMap.count(service_name)) {
        LOG_ERROR << "service: " << service_name  << "not found";
        return;
    }
    ServiceInfo& service_info = m_serviceMap[service_name];
    google::protobuf::Service* service = service_info.m_service; // 获取service对象

    if(!service_info.m_methodMap.count(method_name)) {
        LOG_ERROR << "[" << service_name << "] method: " << method_name << "not found";
        return;
    }

    const google::protobuf::MethodDescriptor* method = service_info.m_methodMap[method_name]; // 获取method对象

    google::protobuf::Message* request = service->GetRequestPrototype(method).New(); // 获取request对象
    google::protobuf::Message* response = service->GetResponsePrototype(method).New(); // 获取response对象


    if( !request->ParseFromString(args_str) ) {
        LOG_ERROR << "request parse error. content: " << args_str;
        return;
    }

    // auto done = 
    //     google::protobuf::NewCallback
    //         <DwtRpcProvider, const muduo::net::TcpConnectionPtr&, google::protobuf::Message*>
    //         (this, &DwtRpcProvider::sendRpcResponse, conn, response);

    auto done = MyClosure(conn, response);

    service->CallMethod(method, nullptr, request, response, &done);
}

void DwtRpcProvider::sendRpcResponse(const muduo::net::TcpConnectionPtr& conn, google::protobuf::Message* response) {
    std::string reponse_str;

    if(response->SerializeToString(&reponse_str)) {
        conn->send(reponse_str);
    } else {
        LOG_ERROR << "Serialize Error: " << reponse_str;
    }

    conn->shutdown();
}


DwtRpcProvider::MyClosure::MyClosure(const muduo::net::TcpConnectionPtr& conn, google::protobuf::Message* response)
    :conn(conn), response(response) {}

void DwtRpcProvider::MyClosure::Run() {
    std::string reponse_str;

    if(response->SerializeToString(&reponse_str)) {
        conn->send(reponse_str);                // 将数据发送
    } else {
        LOG_ERROR << "Serialize Error: " << reponse_str;
    }

    conn->shutdown();   // 关闭连接
}