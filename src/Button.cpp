//
// Created by W-Mai on 2023/3/07.
//

#include "Objs/Button.h"

#define CURRENT_CLASS_NAME Button

DEFI_FUNC_MAP;
DEFI_ATTR_MAP;

ErrorCode Button::getAttr(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_ATTR_FUNC(get);
    if (func == nullptr) return ObjBase::getAttr(id, ret_val, vars);
    return (this->*(func))(ret_val, vars);
}

ErrorCode Button::setAttr(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_ATTR_FUNC(set);
    if (func == nullptr) return ObjBase::setAttr(id, ret_val, vars);
    return (this->*(func))(ret_val, vars);
}

ErrorCode Button::exec(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_EXEC_FUNC();
    if (func == nullptr) return ObjBase::exec(id, ret_val, vars);
    return (this->*(func))(ret_val, vars);
}
