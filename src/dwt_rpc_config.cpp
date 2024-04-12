#include "dwt_rpc_config.h"
#include "json.hpp"

#include <fstream>

using json = nlohmann::json;


void DwtRpcConfig::loadConf(const std::string& file_path) {
    json config;
    std::ifstream f(file_path);
    json data = json::parse(f);

    for(json::iterator it = data.begin(); it != data.end(); ++ it) {
        m_conf[it.key()] = it.value();
    }
}

std::string DwtRpcConfig::Get(const std::string& key) const {
    auto f = m_conf.find(key);
    if(f != m_conf.end()) {
        return f->second;
    }
    return {};
}