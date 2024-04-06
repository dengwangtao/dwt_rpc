#include "rpcprovider.hpp"
#include "dwtrpcapplication.hpp"
#include <functional>

void RpcProvider::NotifyService(::google::protobuf::Service *service) {

}


void RpcProvider::Run() {
    
    muduo::net::InetAddress addr(
        DwtRpcApplication::getConfig().Get("rpcserver_ip"),             // IP
        std::stoi(DwtRpcApplication::getConfig().Get("rpcserver_port")) // Port
    );
    // tcpserver
    muduo::net::TcpServer server(&m_eventloop, addr, "dwt_rpc");

    // 绑定连接回调
    server.setConnectionCallback(
        std::bind(&RpcProvider::onConnection, this, std::placeholders::_1)
    );


    server.setMessageCallback(
        std::bind(
            &RpcProvider::onMessage, this, std::placeholders::_1,
            std::placeholders::_2, std::placeholders::_3)
    );

    server.setThreadNum(4);
    
    server.start();     // 启动
    m_eventloop.loop(); // 启动事件循环

    // one loop per thread
}


void RpcProvider::onConnection(const muduo::net::TcpConnectionPtr& conn) {

}

void RpcProvider::onMessage(const muduo::net::TcpConnectionPtr& conn,
        muduo::net::Buffer* buffer,muduo::Timestamp time) {

}