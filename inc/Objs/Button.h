//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_BUTTON_H
#define XWRAPUP_BUTTON_H

#include "enums/EButton.h"

#define CURRENT_CLASS_NAME Button

CLASS_BEGIN(Button, OBJ_CONSTRUCTOR(), { CLASS_OBJ_INIT_ITEM_ATTR(Test); })

public:
Button() = default;

template<class T, class... ARGS>
T getAttr(IDType id, ARGS... args) {
    auto func_pack = attr_map[id];
    auto func      = (T(CURRENT_CLASS_NAME::*)(ARGS...)) func_pack.get;
    return (this->*(func))(args...);
}

template<class T, class... ARGS>
void setAttr(IDType id, ARGS... args) {
    auto func_pack = attr_map[id];
    auto func      = (T(CURRENT_CLASS_NAME::*)(ARGS...)) func_pack.set;
    return (this->*(func))(args...);
}

template<class T, class... ARGS>
T exec(IDType id, ARGS... args) {
    auto func = (T(CURRENT_CLASS_NAME::*)(ARGS...)) func_map[id];

    return (this->*func)(args...);
}

void registerCb() {}

protected:
int getTest() { return width; }
void setTest(int val) { width = val; }

private:
bool visibility;
int width;

CLASS_END(Button)
#undef CURRENT_CLASS_NAME// remember to clear macros

#endif//XWRAPUP_BUTTON_H
