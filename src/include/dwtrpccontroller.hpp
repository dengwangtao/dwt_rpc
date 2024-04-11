#pragma once

#include <google/protobuf/service.h>
#include <string>

class DwtRpcController: public google::protobuf::RpcController {

public:
    DwtRpcController();

    void Reset();

    bool Failed() const;

    std::string ErrorText() const;

    void SetFailed(const std::string& reason);

    void StartCancel();

    bool IsCanceled() const;

    void NotifyOnCancel(google::protobuf::Closure* callback);

private:
    bool m_failed;          // 是否失败
    std::string m_errText;  // 错误信息
};