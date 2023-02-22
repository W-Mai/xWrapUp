//
// Created by W-Mai on 2023/2/21.
//

#ifndef XWRAPUP_OBJBASE_H
#define XWRAPUP_OBJBASE_H

#include <map>

#include "enums/EObjBase.h"

#define CURRENT_CLASS_NAME ObjBase

BASE_CLASS_BEGIN({
    CLASS_OBJ_INIT_ITEM(getAttr);
    CLASS_OBJ_INIT_ITEM(setAttr);
    CLASS_OBJ_INIT_ITEM(registerCb);
})

ObjBase() = default;

int a;

int getAttr() const { return a; }

void setAttr(int v, int v2) { a = v + v2; }

template<class T, class... ARGS>
T exec(uint32_t id, ARGS... args) {
    auto func = (T(CURRENT_CLASS_NAME::*)(ARGS...)
    ) func_map[(FUNC_ENUM_NAME(CURRENT_CLASS_NAME)) id];

    return (this->*func)(args...);
}

void registerCb() {}

BASE_CLASS_END
#undef CURRENT_CLASS_NAME// remember to clear macros
#endif                   // XWRAPUP_OBJBASE_H
