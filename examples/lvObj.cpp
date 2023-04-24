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
RectType lvObj::nativeGetCoords() {
    auto obj = (lv_obj_t *) native();
    return {
        lv_obj_get_x(obj),
        lv_obj_get_y(obj),
        lv_obj_get_x2(obj),
        lv_obj_get_y2(obj)};
}
RectType lvObj::nativeGetOriCoords() {
    auto obj = (lv_obj_t *) native();
    lv_area_t area;
    lv_obj_get_coords(obj, &area);
    return {area.x1, area.y1, area.x2, area.y2};
}
RectSizeType lvObj::nativeGetRect() {
    auto obj = (lv_obj_t *) native();
    return {
        lv_obj_get_x(obj),
        lv_obj_get_y(obj),
        lv_obj_get_width(obj),
        lv_obj_get_height(obj)};
}
BoxType lvObj::nativeGetScrollCoords() {
    auto obj = (lv_obj_t *) native();
    return {
        lv_obj_get_scroll_left(obj),
        lv_obj_get_scroll_top(obj),
        lv_obj_get_scroll_right(obj),
        lv_obj_get_scroll_bottom(obj)};
}
CoordType lvObj::nativeGetScrollLeft() {
    return lv_obj_get_scroll_left((lv_obj_t *) native());
}
CoordType lvObj::nativeGetScrollTop() {
    return lv_obj_get_scroll_top((lv_obj_t *) native());
}
CoordType lvObj::nativeGetScrollRight() {
    return lv_obj_get_scroll_right((lv_obj_t *) native());
}
CoordType lvObj::nativeGetScrollBottom() {
    return lv_obj_get_scroll_bottom((lv_obj_t *) native());
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
void lvObj::nativeSetCoords(RectType coords) {
    lv_area_t area = {coords.x0, coords.y0, coords.x1, coords.y1};
    auto obj       = (lv_obj_t *) native();
    lv_area_copy(&obj->coords, &area);
}
void lvObj::nativeSetScrollCoords(BoxType box) {
    auto obj = (lv_obj_t *) native();
    lv_obj_scroll_to(obj, box.left, box.top, lv_anim_enable_t::LV_ANIM_ON);
}
void lvObj::nativeSetScrollLeft(CoordType left) {
    auto obj = (lv_obj_t *) native();
    lv_obj_scroll_to_x(obj, left, lv_anim_enable_t::LV_ANIM_ON);
}
void lvObj::nativeSetScrollTop(CoordType top) {
    auto obj = (lv_obj_t *) native();
    lv_obj_scroll_to_y(obj, top, lv_anim_enable_t::LV_ANIM_ON);
}
void lvObj::nativeSetScrollRight(CoordType right) {
    auto obj = (lv_obj_t *) native();
    auto scroll_max =
        lv_obj_get_scroll_left(obj) + lv_obj_get_scroll_right(obj);
    lv_obj_scroll_to_x(obj, scroll_max - right, lv_anim_enable_t::LV_ANIM_ON);
}
void lvObj::nativeSetScrollBottom(CoordType bottom) {
    auto obj = (lv_obj_t *) native();
    auto scroll_max =
        lv_obj_get_scroll_top(obj) + lv_obj_get_scroll_bottom(obj);
    lv_obj_scroll_to_y(obj, scroll_max - bottom, lv_anim_enable_t::LV_ANIM_ON);
}
