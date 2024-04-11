#include <iostream>
#include <string>

#include "user.pb.h"
#include "info.pb.h"

#include "dwtrpcapplication.hpp"



// rpc 服务提供者
class UserService : public dwt::UserServiceRpc {

public:

    ~UserService() {

    }

    bool Login(const std::string& name, const std::string& password) {
        std::cout << "doLogin " << std::endl;
        std::cout << "name: " << name << ", passord: " << password << std::endl;
        return true;
    }

    void Login(
        ::google::protobuf::RpcController* controller,
        const ::dwt::LoginRequest* request,
        ::dwt::LoginResponse* response,
        ::google::protobuf::Closure* done
    ) override {

        bool success = this->Login(request->name(), request->password());
        response->set_success(success);
        response->mutable_result()->set_errcode(1);
        response->mutable_result()->set_errmsg("login error");

        done->Run();
    }



    int Register(const std::string& name, const std::string& password) {
        std::cout << "do Register " << std::endl;
        std::cout << "name: " << name << ", passord: " << password << std::endl;
        return rand() % 500 + 1;
    }

    void Register (::google::protobuf::RpcController* controller,
        const ::dwt::RegisterRequest* request,
        ::dwt::RegisterResponse* response,
        ::google::protobuf::Closure* done
    ) override {
        int uid = this->Register(request->name(), request->password());
        response->set_id(uid);
        response->set_success(uid > 0);
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("success");

        done->Run();
    }

};



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
    provider.NotifyService(new UserService());

    provider.NotifyService(new InfoService());

    provider.Run();

    return 0;
}