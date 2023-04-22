//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_EOBJBASE_H
#define XWRAPUP_EOBJBASE_H

#include "utils/Utils.h"
#define CURRENT_CLASS_NAME IObjBase

FUNC_ENUM({
    IDGEN_START(100);

    FUNC_ENUM_ITEM(show);
    FUNC_ENUM_ITEM(hide);
    FUNC_ENUM_ITEM(visible);

    IDGEN_END();
})

ATTR_ENUM({
    IDGEN_START(150);

    ATTR_ENUM_ITEM(Width);
    ATTR_ENUM_ITEM(Height);
    ATTR_ENUM_ITEM(X);
    ATTR_ENUM_ITEM(Y);
    ATTR_ENUM_ITEM(Coords);
    ATTR_ENUM_ITEM(OriCoords);
    ATTR_ENUM_ITEM(Rect);
    ATTR_ENUM_ITEM(ScrollCoords);
    ATTR_ENUM_ITEM(ScrollLeft);
    ATTR_ENUM_ITEM(ScrollTop);
    ATTR_ENUM_ITEM(ScrollRight);
    ATTR_ENUM_ITEM(ScrollBottom);

    IDGEN_END();
})

#undef CURRENT_CLASS_NAME// remember to clear macros
#endif                   // XWRAPUP_EOBJBASE_H
