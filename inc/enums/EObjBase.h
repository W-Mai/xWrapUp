//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_EOBJBASE_H
#define XWRAPUP_EOBJBASE_H

#include "Utils.h"
#define CURRENT_CLASS_NAME ObjBase

FUNC_ENUM({
    FUNC_ENUM_ITEM(getAttr),
    FUNC_ENUM_ITEM(setAttr),
    FUNC_ENUM_ITEM(registerCb),
});

#undef CURRENT_CLASS_NAME// remember to clear macros
#endif                   // XWRAPUP_EOBJBASE_H
