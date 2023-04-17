//
// Created by W-Mai on 2023/4/14.
//

#include <lvObj.h>

// ********************************************************************
// *                        Native Operations                         *
// ********************************************************************

// ***************************** Getters ******************************
void *lvObj::nativeGetParent() {
    return lv_obj_get_parent((lv_obj_t *) native());
}
CoordType lvObj::nativeGetWidth() {
    return lv_obj_get_style_width((lv_obj_t *) native(), LV_PART_MAIN);
}
CoordType lvObj::nativeGetHeight() {
    return lv_obj_get_style_height((lv_obj_t *) native(), LV_PART_MAIN);
}
CoordType lvObj::nativeGetX() {
    return lv_obj_get_style_x((lv_obj_t *) native(), LV_PART_MAIN);
}
CoordType lvObj::nativeGetY() {
    return lv_obj_get_style_y((lv_obj_t *) native(), LV_PART_MAIN);
}

// ***************************** Setters ******************************
void lvObj::nativeSetParent(void *par) {
    lv_obj_set_parent((lv_obj_t *) native(), (lv_obj_t *) par);
}
void lvObj::nativeSetWidth(CoordType w) {
    lv_obj_set_style_width((lv_obj_t *) native(), w, LV_PART_MAIN);
}
void lvObj::nativeSetHeight(CoordType h) {
    lv_obj_set_style_height((lv_obj_t *) native(), h, LV_PART_MAIN);
}
void lvObj::nativeSetX(CoordType x) {
    lv_obj_set_style_x((lv_obj_t *) native(), x, LV_PART_MAIN);
}
void lvObj::nativeSetY(CoordType y) {
    lv_obj_set_style_y((lv_obj_t *) native(), y, LV_PART_MAIN);
}
