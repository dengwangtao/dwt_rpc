#include <string>
#include <iostream>

#include "dwtrpcapplication.hpp"
#include "cmdline.hpp"

#include <muduo/base/Logging.h>


DwtRpcConfig DwtRpcApplication::m_config; // 静态成员类外初始化

void DwtRpcApplication::Init(int argc, char** argv) {

    cmdline::parser parser; // 命令行参数分析器
    parser.add<std::string> ("config", 'c', "configuration file");
    parser.add<int>("loglevel", 'l', "log level (0~5)", false, 2, cmdline::range(0, 5)); // 日志等级 0~5

    parser.parse_check(argc, argv);

    std::string config_file = parser.get<std::string>("config");

    // 设置日志等级
    muduo::Logger::setLogLevel(static_cast<muduo::Logger::LogLevel>(parser.get<int>("loglevel")));

    // 加载配置文件
    m_config.loadConf(config_file);

    LOG_INFO << "rpcserver_ip: " << m_config.Get("rpcserver_ip");
    LOG_INFO << "rpcserver_port: " << m_config.Get("rpcserver_port");
    LOG_INFO << "zookeeper_ip: " << m_config.Get("zookeeper_ip");
    LOG_INFO << "zookeeper_port: " << m_config.Get("zookeeper_port");
}

DwtRpcApplication& DwtRpcApplication::getInstance() {
    static DwtRpcApplication app;

    return app;
}

const DwtRpcConfig& DwtRpcApplication::getConfig() {
    return m_config;
}