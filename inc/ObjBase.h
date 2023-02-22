//
// Created by W-Mai on 2023/2/21.
//

#ifndef XWRAPUP_OBJBASE_H
#define XWRAPUP_OBJBASE_H

#include <map>

#include "enums/EObjBase.h"

#define CURRENT_CLASS_NAME ObjBase

BASE_CLASS_BEGIN({
    CLASS_OBJ_INIT_ITEM(show);
    CLASS_OBJ_INIT_ITEM(hide);
    CLASS_OBJ_INIT_ITEM(visible);
})

public:
ObjBase() = default;

template<class T, class... ARGS>
T getAttr(ARGS... args) const {
    return exec<T>(args...);
}

template<class T, class... ARGS>
void setAttr(ARGS... args) {
    exec<T>(args...);
}

template<class T, class... ARGS>
T exec(uint32_t id, ARGS... args) {
    auto func = (T(CURRENT_CLASS_NAME::*)(ARGS...)
    ) func_map[(FUNC_ENUM_NAME(CURRENT_CLASS_NAME)) id];

    return (this->*func)(args...);
}

void registerCb() {}

protected:
void show() { visibility = true; }
void hide() { visibility = false; }
bool visible() const { return visibility; }

private:
bool visibility;

BASE_CLASS_END
#undef CURRENT_CLASS_NAME// remember to clear macros
#endif                   // XWRAPUP_OBJBASE_H
