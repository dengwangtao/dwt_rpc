#pragma once

#include "dwt_rpc_config.h"

// 统一包含头文件
#include "dwt_rpc_provider.h"
#include "dwt_rpc_channel.h"
#include "dwt_rpc_controller.h"
#include "dwt_logger.h"

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