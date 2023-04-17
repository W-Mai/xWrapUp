//
// Created by W-Mai on 2023/4/14.
//

#ifndef XWRAPUP_LVOBJ_H
#define XWRAPUP_LVOBJ_H

#include <lvgl.h>
#include <xWrapUp.h>

class lvObj : public IObjBase {
public:
    explicit lvObj(IObjBase *par) : IObjBase(par) {
        native(lv_obj_create(par ? (lv_obj_t *) par->native() : nullptr));
    }
    static IObjBase *constructor(IObjBase *par = nullptr) {
        return new lvObj(par);
    }

protected:
    void *nativeGetParent() override;
    CoordType nativeGetWidth() override;
    CoordType nativeGetHeight() override;
    CoordType nativeGetX() override;
    CoordType nativeGetY() override;

    void nativeSetParent(void *par) override;
    void nativeSetWidth(CoordType w) override;
    void nativeSetHeight(CoordType h) override;
    void nativeSetX(CoordType x) override;
    void nativeSetY(CoordType y) override;
};


#endif//XWRAPUP_LVOBJ_H
