//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_BUTTON_H
#define XWRAPUP_BUTTON_H

#include "ObjBase.h"
#include "enums/EButton.h"

#define CURRENT_CLASS_NAME Button

CLASS_BEGIN(Button, OBJ_CONSTRUCTOR(), { CLASS_OBJ_INIT_ITEM_ATTR(Test); })

public:
Button() = default;

ErrorCode getAttr(IDType id, void *ret_val, ...) {
    auto func = FETCH_ATTR_GET_FUNC();
    va_list vars;
    va_start(vars, ret_val);
    auto code = (this->*(func))(ret_val, vars);
    va_end(vars);
    return code;
}

ErrorCode setAttr(IDType id, void *ret_val, ...) {
    auto func = FETCH_ATTR_SET_FUNC();
    va_list vars;
    va_start(vars, ret_val);
    auto code = (this->*(func))(ret_val, vars);
    va_end(vars);
    return code;
}

template<class T, class... ARGS>
T exec(IDType id, ARGS... args) {
    auto func = FETCH_EXEC_FUNC();
    return (this->*func)(args...);
}

void registerCb() {}

protected:
ErrorCode getTest(int *ret_val, va_list vars) {
    *ret_val = width;
    return ErrorCode::OK;
}
ErrorCode setTest(void *ret_val, va_list vars) {
    width = va_arg(vars, int);
    return ErrorCode::OK;
}

private:
bool visibility;
int width;

CLASS_END(Button)
#undef CURRENT_CLASS_NAME// remember to clear macros

#endif//XWRAPUP_BUTTON_H
