//
// Created by W-Mai on 2023/2/22.
//

#include "iface/IObjBase.h"

#define CURRENT_CLASS_NAME IObjBase

DEFI_FUNC_MAP;
DEFI_ATTR_MAP;

ErrorCode IObjBase::getAttr(IDType id, void *ret_val, ...) {
    va_list vars;
    va_start(vars, ret_val);
    auto code = getAttr(id, ret_val, vars);
    va_end(vars);
    return code;
}

ErrorCode IObjBase::setAttr(IDType id, void *ret_val, ...) {
    va_list vars;
    va_start(vars, ret_val);
    auto code = setAttr(id, ret_val, vars);
    va_end(vars);
    return code;
}

ErrorCode IObjBase::exec(IDType id, void *ret_val, ...) {
    va_list vars;
    va_start(vars, ret_val);
    auto code = exec(id, ret_val, vars);
    va_end(vars);
    return code;
}

ErrorCode IObjBase::getAttr(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_ATTR_FUNC(get);
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode IObjBase::setAttr(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_ATTR_FUNC(set);
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode IObjBase::exec(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_EXEC_FUNC();
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode IObjBase::show(int * /*ret_val*/, va_list /*vars*/) {
    visibility = true;
    return ErrorCode::OK;
}
ErrorCode IObjBase::hide(int * /*ret_val*/, va_list /*vars*/) {
    visibility = false;
    return ErrorCode::OK;
}
ErrorCode IObjBase::visible(int *ret_val, va_list vars) const {
    *ret_val = visibility;
    return ErrorCode::OK;
}

ErrorCode IObjBase::getWidth(int *ret_val, va_list vars) {
    width    = nativeGetWidth();
    *ret_val = width;
    return ErrorCode::OK;
}
ErrorCode IObjBase::setWidth(void *ret_val, va_list vars) {
    width = va_arg(vars, int);
    nativeSetWidth(width);
    return ErrorCode::OK;
}
ErrorCode IObjBase::getHeight(int *ret_val, va_list vars) {
    height   = nativeGetHeight();
    *ret_val = height;
    return ErrorCode::OK;
}
ErrorCode IObjBase::setHeight(void *ret_val, va_list vars) {
    height = va_arg(vars, int);
    nativeSetHeight(height);
    return ErrorCode::OK;
}

/**
 * Native Operations
 */

/**
 * Native Getters
 */
coordType IObjBase::nativeGetWidth() { return 0; }
coordType IObjBase::nativeGetHeight() { return 0; }

/**
 * Native Setters
 */
void IObjBase::nativeSetWidth(coordType w) {}
void IObjBase::nativeSetHeight(coordType h) {}
