#pragma once

#include "google/protobuf/service.h"
#include <memory>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>


// 发布服务类
class RpcProvider {

public:
    // 发布服务
    void NotifyService(::google::protobuf::Service *service);

    void Run();

private:
    void onConnection(const muduo::net::TcpConnectionPtr&);

    void onMessage(const muduo::net::TcpConnectionPtr&, muduo::net::Buffer*,muduo::Timestamp);

private:
    // 事件循环
    muduo::net::EventLoop m_eventloop;
};