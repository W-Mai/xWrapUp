//
// Created by W-Mai on 2023/2/21.
//

#ifndef XWRAPUP_OBJBASE_H
#define XWRAPUP_OBJBASE_H

#include <map>

#include "enums/EObjBase.h"

#define CURRENT_CLASS_NAME ObjBase

BASE_CLASS_BEGIN
CLASS_OBJ_INIT({
    CLASS_OBJ_INIT_ITEM(getAttr);
    CLASS_OBJ_INIT_ITEM(setAttr);
    CLASS_OBJ_INIT_ITEM(execCb);
    CLASS_OBJ_INIT_ITEM(registerCb);
})

ObjBase() {}

void getAttr() {}

void setAttr() {}

void execCb() {}

void registerCb() {}

BASE_CLASS_END
#undef CURRENT_CLASS_NAME// remember to clear macros
#endif                   // XWRAPUP_OBJBASE_H
