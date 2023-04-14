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

    coordType nativeGetWidth() override;
    coordType nativeGetHeight() override;

    void nativeSetWidth(coordType w) override;
    void nativeSetHeight(coordType h) override;
};


#endif//XWRAPUP_LVOBJ_H
