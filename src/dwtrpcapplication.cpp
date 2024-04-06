#include <string>
#include <iostream>

#include "dwtrpcapplication.hpp"

#include "cmdline.hpp"

DwtRpcConfig DwtRpcApplication::m_config; // 静态成员类外初始化

void DwtRpcApplication::Init(int argc, char** argv) {
    cmdline::parser parser; // 命令行参数分析器
    parser.add<std::string> ("config", 'f', "configuration file");

    parser.parse_check(argc, argv);

    std::string config_file = parser.get<std::string>("config");

    // std::cout << config_file << std::endl;

    // 加载配置文件
    m_config.loadConf(config_file);

    std::cout << m_config.Get("rpcserver_port") << std::endl;
}

DwtRpcApplication& DwtRpcApplication::getInstance() {
    static DwtRpcApplication app;

    return app;
}

const DwtRpcConfig& DwtRpcApplication::getConfig() {
    return m_config;
}