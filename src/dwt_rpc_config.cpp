#include "dwt_rpc_config.h"
#include "json.hpp"

#include "dwt_logger.h"
#include <fstream>

using json = nlohmann::json;


void DwtRpcConfig::loadConf(const std::string& file_path) {
    json config;
    std::ifstream f(file_path);
    if(f.fail()) {
        DWT_LOG_ERROR("%s configuration file open error", file_path.c_str());
        exit(EXIT_FAILURE);
    }

    json data = json::parse(f);

    for(json::iterator it = data.begin(); it != data.end(); ++ it) {
        m_conf[it.key()] = it.value();
        DWT_LOG_INFO("load config %s=%s", it.key().c_str(), m_conf[it.key()].c_str());
    }
}

std::string DwtRpcConfig::Get(const std::string& key) const {
    auto f = m_conf.find(key);
    if(f != m_conf.end()) {
        return f->second;
    }
    DWT_LOG_WARN("config key: %s not found", key.c_str());
    return {};
}