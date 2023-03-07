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

virtual ErrorCode getAttr(IDType id, void *ret_val, ...);
virtual ErrorCode setAttr(IDType id, void *ret_val, ...);
virtual ErrorCode exec(IDType id, void *ret_val, ...);

//void registerCb() {}

protected:
virtual ErrorCode getAttr(IDType id, void *ret_val, va_list vars);
virtual ErrorCode setAttr(IDType id, void *ret_val, va_list vars);
virtual ErrorCode exec(IDType id, void *ret_val, va_list vars);

protected:
ErrorCode show(int * /*ret_val*/, va_list /*vars*/);
ErrorCode hide(int * /*ret_val*/, va_list /*vars*/);
ErrorCode visible(int *ret_val, va_list vars) const;

ErrorCode getWidth(int *ret_val, va_list vars);
ErrorCode setWidth(void *ret_val, va_list vars);

private:
bool visibility{};
int width{};

CLASS_END(ObjBase)
#undef CURRENT_CLASS_NAME// remember to clear macros
#endif                   // XWRAPUP_OBJBASE_H
