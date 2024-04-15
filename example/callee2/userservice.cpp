#include <iostream>
#include <string>

#include "info.pb.h"

#include "dwt_rpc_application.h"



class InfoService: public dwt::InfoServiceRpc {
    std::vector<std::string> GetInfo(int uid, int type) {
        std::vector<std::string> res;
        std::string tmp = std::to_string(uid) + "__";
        for(int i = 0; i < 5; ++ i) {
            tmp += std::to_string(type);
            res.push_back(tmp);
        }
        return res;
    }
public:
    void GetInfo(
        ::google::protobuf::RpcController* controller,
        const ::dwt::InfoRequest* request,
        ::dwt::InfoResponse* response,
        ::google::protobuf::Closure* done
    ) override {

        int uid = request->uid();
        int type = request->type();

        auto res = this->GetInfo(uid, type);

        response->set_success(true);
        response->set_size(res.size());
        for(std::string& s : res) {
            *(response->add_info()) = std::move(s); // 移动
        }

        done->Run();
    }
};

int main(int argc, char** argv) {

    // 框架初始化
    DwtRpcApplication::Init(argc, argv);

    // 将服务发布到rpc节点
    DwtRpcProvider provider;

    provider.NotifyService(new InfoService());

    provider.Run();

    return 0;
}