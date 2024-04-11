#include <iostream>
#include "dwtrpcapplication.hpp"
#include "user.pb.h"
#include "info.pb.h"



int main(int argc, char** argv) {

    DwtRpcApplication::Init(argc, argv); // 初始化框架


    DwtRpcChannel* channel = new DwtRpcChannel();

    // 调用远程发布的方法
    dwt::UserServiceRpc_Stub stub(channel);

    // 登录测试
    {
        dwt::LoginRequest req;
        req.set_name("dwt");
        req.set_password("password");

        dwt::LoginResponse res;

        DwtRpcController controller;

        stub.Login(&controller, &req, &res, nullptr); // 发起请求
        
        if(!controller.Failed() && res.result().errcode() == 0) {
            std::cout << "rpc call success: " << res.success() << std::endl;
        } else {
            std::cout << "rpc call failed: " << res.result().errmsg() << std::endl;
        }
    }



    // 注册测试
    {
        dwt::RegisterRequest req;
        dwt::RegisterResponse res;

        req.set_name("reg_name");
        req.set_name("reg_password");

        DwtRpcController controller;
        stub.Register(&controller, &req, &res, nullptr);

        if(!controller.Failed() && res.result().errcode() == 0) {
            std::cout << "register success: id = " << res.id() << std::endl;
        } else {
            std::cout << "rpc call register failed: " << res.result().errmsg() << std::endl;
        }
    }


    dwt::InfoServiceRpc_Stub stub2(channel); // info服务

    {
        dwt::InfoRequest req;
        dwt::InfoResponse res;

        req.set_uid(123456);
        req.set_type(8);

        DwtRpcController controller;
        stub2.GetInfo(&controller, &req, &res, nullptr);

        if(!controller.Failed() && res.success()) {
            std::cout << "receive " << res.size() << " data =====" << std::endl;
            for(int i = 0; i < res.info_size(); ++ i) {
                std::cout << "\t" << res.info(i) << std::endl;
            }
        }
    }


    delete channel;

    return 0;
}