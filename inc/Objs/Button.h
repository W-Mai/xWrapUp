//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_BUTTON_H
#define XWRAPUP_BUTTON_H

#include "enums/EButton.h"


#define CURRENT_CLASS_NAME Button

BASE_CLASS_BEGIN(Button, { CLASS_OBJ_INIT_ITEM_ATTR(Test); })

public:
Button() = default;

template<class T, class... ARGS>
T getAttr(uint32_t id, ARGS... args) {
    auto func_pack = attr_map[(ATTR_ENUM_NAME(CURRENT_CLASS_NAME)) id];
    auto func      = (T(CURRENT_CLASS_NAME::*)(ARGS...)) func_pack.get;
    return (this->*(func))(args...);
}

template<class T, class... ARGS>
void setAttr(uint32_t id, ARGS... args) {
    auto func_pack = attr_map[(ATTR_ENUM_NAME(CURRENT_CLASS_NAME)) id];
    auto func      = (T(CURRENT_CLASS_NAME::*)(ARGS...)) func_pack.set;
    return (this->*(func))(args...);
}

template<class T, class... ARGS>
T exec(uint32_t id, ARGS... args) {
    auto func = (T(CURRENT_CLASS_NAME::*)(ARGS...)
    ) func_map[(FUNC_ENUM_NAME(CURRENT_CLASS_NAME)) id];

    return (this->*func)(args...);
}

void registerCb() {}

protected:
int getTest() { return width; }
void setTest(int val) { width = val; }

private:
bool visibility;
int width;

BASE_CLASS_END
#undef CURRENT_CLASS_NAME// remember to clear macros

#endif//XWRAPUP_BUTTON_H
