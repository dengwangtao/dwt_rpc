#include <iostream>
#include <string>

#include "user.pb.h"

#include "dwt_rpc_application.h"



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

int main(int argc, char** argv) {

    // 框架初始化
    DwtRpcApplication::Init(argc, argv);

    // 将服务发布到rpc节点
    DwtRpcProvider provider;
    provider.NotifyService(new UserService());

    provider.Run();

    return 0;
}