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

template<class T, class... ARGS>
T getAttr(IDType id, ARGS... args) {
    auto func = FETCH_ATTR_GET_FUNC();
    return (this->*(func))(args...);
}

template<class T, class... ARGS>
void setAttr(IDType id, ARGS... args) {
    auto func = FETCH_ATTR_SET_FUNC();
    return (this->*(func))(args...);
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

int getWidth() { return width; }
void setWidth(int val) { width = val; }

private:
bool visibility;
int width;

CLASS_END(ObjBase)
#undef CURRENT_CLASS_NAME// remember to clear macros
#endif                   // XWRAPUP_OBJBASE_H
