#include "dwt_rpc_controller.h"

DwtRpcController::DwtRpcController() {
    m_errText = "";
    m_failed = false;
}

void DwtRpcController::Reset() {
    m_errText = "";
    m_failed = false;
}

bool DwtRpcController::Failed() const {
    return m_failed;
}

std::string DwtRpcController::ErrorText() const {
    return m_errText;
}

void DwtRpcController::SetFailed(const std::string& reason) {
    m_failed = true;
    m_errText = reason;
}


// TODO: 下面三个方法未实现

void DwtRpcController::StartCancel() {

}

bool DwtRpcController::IsCanceled() const {
    return false;
}

void DwtRpcController::NotifyOnCancel(google::protobuf::Closure* callback) {

}