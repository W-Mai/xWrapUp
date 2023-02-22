//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_EOBJBASE_H
#define XWRAPUP_EOBJBASE_H

#include "Utils.h"

FUNC_ENUM(
    ObjBase,
    {
        FUNC_ENUM_ITEM(getAttr),
        FUNC_ENUM_ITEM(setAttr),
        FUNC_ENUM_ITEM(execCb),
        FUNC_ENUM_ITEM(registerCb),
    }
);

#endif//XWRAPUP_EOBJBASE_H
