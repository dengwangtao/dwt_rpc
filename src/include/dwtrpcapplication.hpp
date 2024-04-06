#pragma once

#include "dwtrpcconfig.hpp"

class DwtRpcApplication {

public:

    static void Init(int argc, char** argv);

    static DwtRpcApplication& getInstance();

    static const DwtRpcConfig& getConfig();

private:
    DwtRpcApplication(){}
    DwtRpcApplication(const DwtRpcApplication&) = delete;
    DwtRpcApplication& operator=(const DwtRpcApplication&) = delete;
    DwtRpcApplication(DwtRpcApplication&&) = delete;
    DwtRpcApplication& operator=(DwtRpcApplication&&) = delete;


    static DwtRpcConfig m_config; // 读取配置文件类

};