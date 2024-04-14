#include "zookeeper_util.h"

#include "dwt_rpc_application.h"
#include "dwt_logger.h"


// 全局观察者
void globalWatcher(zhandle_t* handle, int type, int state, const char* path, void* watcherCtx) {
    
    if(type == ZOO_SESSION_EVENT) {
        if(state == ZOO_CONNECTED_STATE) {
            
            sem_t *sem = (sem_t*)zoo_get_context(handle);

            sem_post(sem);
        }
    }

}

ZkClient::ZkClient():m_zhandle(nullptr) {
    // 构造函数
}

ZkClient::~ZkClient() {
    // 析构, 关闭zk
    if(m_zhandle) {
        zookeeper_close(m_zhandle);
    }
}

void ZkClient::Start() {
    std::string host = DwtRpcApplication::getInstance().getConfig().Get("zookeeper_ip");
    std::string port = DwtRpcApplication::getInstance().getConfig().Get("zookeeper_port");
    std::string conn_str = host + ":" + port;

    m_zhandle = zookeeper_init(conn_str.c_str(), globalWatcher, 30000, nullptr, nullptr, 0); // 超时时间30s

    if(m_zhandle == nullptr) {
        DWT_LOG_ERROR("zookeeper_init error!");
        exit(EXIT_FAILURE);
    }

    sem_t sem;
    sem_init(&sem, 0, 0); // 线程间不共享, 初始值为0
    zoo_set_context(m_zhandle, &sem);

    sem_wait(&sem);     // 等待信号量可用 (等待连接成功)

    DWT_LOG_INFO("zookeeper_init success");
}


void ZkClient::Create(const char* path, const char* data, int data_len, int state) {
    // state ZOO_EPHEMERAL ZOO_SEQUENCE

    char path_buf[128] = {0};
    int buf_len = sizeof(path_buf);

    // 判断znode节点是否存在
    int flag = zoo_exists(m_zhandle, path, 0, nullptr);

    if(ZNONODE == flag) {
        flag = zoo_create(m_zhandle, path, data, data_len, &ZOO_OPEN_ACL_UNSAFE, state, path_buf, buf_len);

        if(flag == ZOK) {
            DWT_LOG_INFO("znode create successfuly: path = %s", path);
        } else {
            DWT_LOG_INFO("znode create failed: path = %s, flag = %d", path, flag);
            exit(EXIT_FAILURE);
        }
    }

}


std::string ZkClient::GetData(const char* path) {

    char buf[64] = {0};
    int buf_len = sizeof(buf);

    int flag = zoo_get(m_zhandle, path, 0, buf, &buf_len, nullptr);

    if(flag != ZOK) {
        DWT_LOG_ERROR("get znode error: %s", path);
        return "";
    } else {
        return buf;
    }
}