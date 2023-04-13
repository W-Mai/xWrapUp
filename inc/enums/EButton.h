//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_EBUTTON_H
#define XWRAPUP_EBUTTON_H

#include "utils/Utils.h"
#define CURRENT_CLASS_NAME IButton

FUNC_ENUM({ IDGEN_START(200); })

ATTR_ENUM({
    IDGEN_START(250);
    ATTR_ENUM_ITEM(Test);
})

#undef CURRENT_CLASS_NAME// remember to clear macros

#endif//XWRAPUP_EBUTTON_H
