//
// Created by W-Mai on 2023/2/22.
//

#include "Objs/ObjBase.h"

#define CURRENT_CLASS_NAME ObjBase

DEFI_FUNC_MAP;
DEFI_ATTR_MAP;

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
