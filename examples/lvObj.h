//
// Created by W-Mai on 2023/4/14.
//

#ifndef XWRAPUP_LVOBJ_H
#define XWRAPUP_LVOBJ_H

#include "lvgl.h"
#include <xWrapUp.h>

class lvObj : public IObjBase {
public:
    explicit lvObj(IObjBase *par) : IObjBase(par) {
        native(lv_obj_create(par ? (lv_obj_t *) par->native() : lv_scr_act()));
    }

    ErrorCode getWidth(int *ret_val, va_list vars);
    ErrorCode setWidth(void *ret_val, va_list vars);
    ErrorCode getHeight(int *ret_val, va_list vars);
    ErrorCode setHeight(void *ret_val, va_list vars);
};


#endif//XWRAPUP_LVOBJ_H
