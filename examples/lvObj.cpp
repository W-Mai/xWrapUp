//
// Created by W-Mai on 2023/4/14.
//

#include "lvObj.h"
ErrorCode lvObj::getWidth(int *ret_val, va_list vars) {
    auto width = lv_obj_get_style_width((lv_obj_t *) native(), LV_PART_MAIN);
    *ret_val   = width;
    return ErrorCode::OK;
}
ErrorCode lvObj::setWidth(void *ret_val, va_list vars) {
    auto res   = IObjBase::setWidth(ret_val, vars);
    auto width = va_arg(vars, int);
    lv_obj_set_style_width((lv_obj_t *) native(), width, LV_PART_MAIN);
    return res;
}
ErrorCode lvObj::getHeight(int *ret_val, va_list vars) {
    return IObjBase::getHeight(ret_val, vars);
}
ErrorCode lvObj::setHeight(void *ret_val, va_list vars) {
    return IObjBase::setHeight(ret_val, vars);
}
