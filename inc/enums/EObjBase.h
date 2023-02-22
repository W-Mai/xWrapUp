//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_EOBJBASE_H
#define XWRAPUP_EOBJBASE_H

#include "Utils.h"
#define CURRENT_CLASS_NAME ObjBase

FUNC_ENUM({
    FUNC_ENUM_ITEM(show),
    FUNC_ENUM_ITEM(hide),
    FUNC_ENUM_ITEM(visible),
});

ATTR_ENUM({
    ATTR_ENUM_ITEM(Width),
});

#undef CURRENT_CLASS_NAME// remember to clear macros
#endif                   // XWRAPUP_EOBJBASE_H
