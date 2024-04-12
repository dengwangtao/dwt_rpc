#pragma once

#include <google/protobuf/service.h>
#include <google/protobuf/message.h>
#include <google/protobuf/descriptor.h>


// 继承 RpcChannel, 重写CallMethod方法
class DwtRpcChannel: public google::protobuf::RpcChannel {
public:
    
    // 重写方法
    void CallMethod(
        const google::protobuf::MethodDescriptor* method,
        google::protobuf::RpcController* controller, const google::protobuf::Message* request,
        google::protobuf::Message* response, google::protobuf::Closure* done) override;

private:


};