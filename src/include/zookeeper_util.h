#pragma once

/**
 * 封装Zookeeper客户端
*/

#include <string>
#include <zookeeper/zookeeper.h>
#include <semaphore.h>

class ZkClient {
public:
    ZkClient();
    ~ZkClient();

    void Start();
    void Create(const char* path, const char* data, int data_len, int state = 0);
    std::string GetData(const char* path);

private:
    zhandle_t* m_zhandle; // zk客户端 句柄
};