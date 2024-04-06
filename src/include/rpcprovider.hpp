#pragma once

#include "google/protobuf/service.h"
#include <memory>
#include <muduo/net/TcpServer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/net/InetAddress.h>
#include <muduo/net/TcpConnection.h>
#include <functional>
#include <string>


// 发布服务类
class RpcProvider {

public:
    // 发布服务
    void NotifyService(::google::protobuf::Service *service);

    void Run();

private:
    void onConnection(const muduo::net::TcpConnectionPtr&);

    void onMessage(const muduo::net::TcpConnectionPtr&, muduo::net::Buffer*,muduo::Timestamp);

    // Closure的回调
    void sendRpcResponse(const muduo::net::TcpConnectionPtr&, google::protobuf::Message*);

    class MyClosure: public google::protobuf::Closure {
    public:
        void Run() override;
    };

private:
    // 事件循环
    muduo::net::EventLoop m_eventloop;

    // 服务类型信息
    struct ServiceInfo {
        google::protobuf::Service* m_service; // 服务对象
        std::unordered_map<std::string, const google::protobuf::MethodDescriptor*> m_methodMap; // 服务方法
    };

    std::unordered_map<std::string, ServiceInfo> m_serviceMap; // 注册成功的服务对象和服务方法的all信息
};