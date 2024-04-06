#include <iostream>
#include "test.pb.h"


int main() {

    dwt::LoginRequest req;

    req.set_name("邓汪涛");
    req.set_password("123456");

    std::string dump = req.SerializeAsString();

    std::cout << dump << std::endl;

    dwt::LoginRequest req2;

    req2.ParseFromString(dump);

    std::cout << "name: " << req2.name() << std::endl;
    std::cout << "password: " << req2.password() << std::endl;


    return 0;
}