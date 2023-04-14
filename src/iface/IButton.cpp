//
// Created by W-Mai on 2023/3/07.
//

#include <iface/IButton.h>

#define CURRENT_CLASS_NAME IButton

DEFI_FUNC_MAP;
DEFI_ATTR_MAP;

ErrorCode IButton::getAttr(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_ATTR_FUNC(get);
    if (func == nullptr) return IObjBase::getAttr(id, ret_val, vars);
    return (this->*(func))(ret_val, vars);
}

ErrorCode IButton::setAttr(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_ATTR_FUNC(set);
    if (func == nullptr) return IObjBase::setAttr(id, ret_val, vars);
    return (this->*(func))(ret_val, vars);
}

ErrorCode IButton::exec(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_EXEC_FUNC();
    if (func == nullptr) return IObjBase::exec(id, ret_val, vars);
    return (this->*(func))(ret_val, vars);
}

ErrorCode IButton::getTest(int *ret_val, va_list vars) {
    *ret_val = width;
    return ErrorCode::OK;
}

ErrorCode IButton::setTest(void *ret_val, va_list vars) {
    width = va_arg(vars, int);
    return ErrorCode::OK;
}
