#include <string>
#include <iostream>

#include "dwt_rpc_application.h"
#include "cmdline.hpp"

#include <muduo/base/Logging.h>


DwtRpcConfig DwtRpcApplication::m_config; // 静态成员类外初始化

void DwtRpcApplication::Init(int argc, char** argv) {

    cmdline::parser parser; // 命令行参数分析器
    parser.add<std::string> ("config", 'c', "configuration file");
    parser.add<int>("loglevel", 'l', "log level (0~4)", false, 0, cmdline::range(0, 4)); // 日志等级 0~4

    parser.parse_check(argc, argv);

    std::string config_file = parser.get<std::string>("config");

    // 设置日志等级
    muduo::Logger::setLogLevel(static_cast<muduo::Logger::LogLevel>(2));

    // 加载配置文件
    m_config.loadConf(config_file);


    DwtLogger::Instance()->init(parser.get<int>("loglevel"), m_config.Get("log_path").c_str());        // 设置日志保存路径, 设置日志等级
}

DwtRpcApplication& DwtRpcApplication::getInstance() {
    static DwtRpcApplication app;

    return app;
}

const DwtRpcConfig& DwtRpcApplication::getConfig() {
    return m_config;
}