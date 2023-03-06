//
// Created by W-Mai on 2023/2/21.
//

#ifndef XWRAPUP_OBJBASE_H
#define XWRAPUP_OBJBASE_H

#include <map>

#include "enums/EObjBase.h"

#define CURRENT_CLASS_NAME ObjBase

CLASS_BEGIN(ObjBase, OBJ_BASE_CONSTRUCTOR(), {
    CLASS_OBJ_INIT_ITEM(show);
    CLASS_OBJ_INIT_ITEM(hide);
    CLASS_OBJ_INIT_ITEM(visible);

    CLASS_OBJ_INIT_ITEM_ATTR(Width);
})

public:
ObjBase() = default;

virtual ErrorCode getAttr(IDType id, void *ret_val, ...) {
    auto func = FETCH_ATTR_GET_FUNC();
    va_list vars;
    va_start(vars, ret_val);
    auto code = (this->*(func))(ret_val, vars);
    va_end(vars);
    return code;
}

virtual ErrorCode setAttr(IDType id, void *ret_val, ...) {
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
void show() { visibility = true; }
void hide() { visibility = false; }
bool visible() const { return visibility; }

ErrorCode getWidth(int *ret_val, va_list vars) {
    *ret_val = width;
    return ErrorCode::OK;
}
ErrorCode setWidth(void *ret_val, va_list vars) {
    width = va_arg(vars, int);
    return ErrorCode::OK;
}

private:
bool visibility;
int width;

CLASS_END(ObjBase)
#undef CURRENT_CLASS_NAME// remember to clear macros
#endif                   // XWRAPUP_OBJBASE_H
