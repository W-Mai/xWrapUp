//
// Created by W-Mai on 2023/4/14.
//

#include "lvObj.h"

coordType lvObj::nativeGetWidth() {
    return lv_obj_get_style_width((lv_obj_t *) native(), LV_PART_MAIN);
}
coordType lvObj::nativeGetHeight() {
    return lv_obj_get_style_height((lv_obj_t *) native(), LV_PART_MAIN);
}
void lvObj::nativeSetWidth(coordType w) {
    lv_obj_set_style_width((lv_obj_t *) native(), w, LV_PART_MAIN);
}
void lvObj::nativeSetHeight(coordType h) {
    lv_obj_set_style_height((lv_obj_t *) native(), h, LV_PART_MAIN);
}
