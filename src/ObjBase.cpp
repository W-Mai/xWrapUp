//
// Created by W-Mai on 2023/2/22.
//

#include "Objs/ObjBase.h"

#define CURRENT_CLASS_NAME ObjBase

DEFI_FUNC_MAP;
DEFI_ATTR_MAP;

ErrorCode ObjBase::getAttr(IDType id, void *ret_val, ...) {
    va_list vars;
    va_start(vars, ret_val);
    auto code = getAttr(id, ret_val, vars);
    va_end(vars);
    return code;
}

ErrorCode ObjBase::setAttr(IDType id, void *ret_val, ...) {
    va_list vars;
    va_start(vars, ret_val);
    auto code = setAttr(id, ret_val, vars);
    va_end(vars);
    return code;
}

ErrorCode ObjBase::exec(IDType id, void *ret_val, ...) {
    va_list vars;
    va_start(vars, ret_val);
    auto code = exec(id, ret_val, vars);
    va_end(vars);
    return code;
}

ErrorCode ObjBase::getAttr(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_ATTR_FUNC(get);
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode ObjBase::setAttr(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_ATTR_FUNC(set);
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode ObjBase::exec(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_EXEC_FUNC();
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode ObjBase::show(int * /*ret_val*/, va_list /*vars*/) {
    visibility = true;
    return ErrorCode::OK;
}
ErrorCode ObjBase::hide(int * /*ret_val*/, va_list /*vars*/) {
    visibility = false;
    return ErrorCode::OK;
}
ErrorCode ObjBase::visible(int *ret_val, va_list vars) const {
    *ret_val = visibility;
    return ErrorCode::OK;
}

ErrorCode ObjBase::getWidth(int *ret_val, va_list vars) {
    *ret_val = width;
    return ErrorCode::OK;
}
ErrorCode ObjBase::setWidth(void *ret_val, va_list vars) {
    width = va_arg(vars, int);
    return ErrorCode::OK;
}
ErrorCode ObjBase::getHeight(int *ret_val, va_list vars) {
    *ret_val = height;
    return ErrorCode::OK;
}
ErrorCode ObjBase::setHeight(void *ret_val, va_list vars) {
    height = va_arg(vars, int);
    return ErrorCode::OK;
}