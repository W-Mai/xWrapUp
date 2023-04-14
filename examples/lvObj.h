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
        native(lv_obj_create(par ? (lv_obj_t *) par->native() : nullptr));
    }

protected:
    void *nativeGetParent() override;
    coordType nativeGetWidth() override;
    coordType nativeGetHeight() override;
    coordType nativeGetX() override;
    coordType nativeGetY() override;

    void nativeSetParent(void *par) override;
    void nativeSetWidth(coordType w) override;
    void nativeSetHeight(coordType h) override;
    void nativeSetX(coordType x) override;
    void nativeSetY(coordType y) override;
};


#endif//XWRAPUP_LVOBJ_H
