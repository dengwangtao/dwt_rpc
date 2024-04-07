#include <iostream>
#include "dwtrpcapplication.hpp"
#include "user.pb.h"
#include "dwtrpcchannel.hpp"




int main(int argc, char** argv) {

    DwtRpcApplication::Init(argc, argv); // 初始化框架


    DwtRpcChannel* channel = new DwtRpcChannel();

    // 调用远程发布的方法
    dwt::UserServiceRpc_Stub stub(channel);


    dwt::LoginRequest req;
    req.set_name("dwt");
    req.set_password("password");

    dwt::LoginResponse res;

    stub.Login(nullptr, &req, &res, nullptr); // 发起请求
    
    if(res.result().errcode() == 0) {
        std::cout << "rpc call success: " << res.success() << std::endl;
    } else {
        std::cout << "rpc call failed: " << res.result().errmsg() << std::endl;
    }


    delete channel;

    return 0;
}