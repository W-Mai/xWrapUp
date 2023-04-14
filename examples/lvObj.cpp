//
// Created by W-Mai on 2023/4/14.
//

#include "lvObj.h"

// ********************************************************************
// *                        Native Operations                         *
// ********************************************************************

// ***************************** Getters ******************************
coordType lvObj::nativeGetWidth() {
    return lv_obj_get_style_width((lv_obj_t *) native(), LV_PART_MAIN);
}
coordType lvObj::nativeGetHeight() {
    return lv_obj_get_style_height((lv_obj_t *) native(), LV_PART_MAIN);
}
coordType lvObj::nativeGetX() {
    return lv_obj_get_style_x((lv_obj_t *) native(), LV_PART_MAIN);
}
coordType lvObj::nativeGetY() {
    return lv_obj_get_style_y((lv_obj_t *) native(), LV_PART_MAIN);
}

// ***************************** Setters ******************************
void lvObj::nativeSetWidth(coordType w) {
    lv_obj_set_style_width((lv_obj_t *) native(), w, LV_PART_MAIN);
}
void lvObj::nativeSetHeight(coordType h) {
    lv_obj_set_style_height((lv_obj_t *) native(), h, LV_PART_MAIN);
}
void lvObj::nativeSetX(coordType x) {
    lv_obj_set_style_x((lv_obj_t *) native(), x, LV_PART_MAIN);
}
void lvObj::nativeSetY(coordType y) {
    lv_obj_set_style_y((lv_obj_t *) native(), y, LV_PART_MAIN);
}
