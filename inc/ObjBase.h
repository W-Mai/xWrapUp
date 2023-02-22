//
// Created by W-Mai on 2023/2/21.
//

#ifndef XWRAPUP_OBJBASE_H
#define XWRAPUP_OBJBASE_H

#include <map>

#include "enums/EObjBase.h"

BASE_CLASS_BEGIN(ObjBase)
CLASS_OBJ_INIT({
    CLASS_OBJ_INIT_ITEM(ObjBase, getAttr);
    CLASS_OBJ_INIT_ITEM(ObjBase, setAttr);
    CLASS_OBJ_INIT_ITEM(ObjBase, execCb);
    CLASS_OBJ_INIT_ITEM(ObjBase, registerCb);
})

ObjBase() {}


void getAttr() {}

void setAttr() {}

void execCb() {}

void registerCb() {}
BASE_CLASS_END(ObjBase)

#endif//XWRAPUP_OBJBASE_H
