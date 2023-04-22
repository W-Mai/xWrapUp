//
// Created by W-Mai on 2023/2/22.
//

#include <iface/IObjBase.h>

#define CURRENT_CLASS_NAME IObjBase

DEFI_FUNC_MAP;
DEFI_ATTR_MAP;

ErrorCode IObjBase::getAttr(IDType id, void *ret_val, ...) {
    va_list vars;
    va_start(vars, ret_val);
    auto code = getAttr(id, ret_val, vars);
    va_end(vars);
    return code;
}

ErrorCode IObjBase::setAttr(IDType id, void *ret_val, ...) {
    va_list vars;
    va_start(vars, ret_val);
    auto code = setAttr(id, ret_val, vars);
    va_end(vars);
    return code;
}

ErrorCode IObjBase::exec(IDType id, void *ret_val, ...) {
    va_list vars;
    va_start(vars, ret_val);
    auto code = exec(id, ret_val, vars);
    va_end(vars);
    return code;
}

ErrorCode IObjBase::getAttr(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_ATTR_FUNC(get);
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode IObjBase::setAttr(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_ATTR_FUNC(set);
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode IObjBase::exec(IDType id, void *ret_val, va_list vars) {
    auto func = FETCH_EXEC_FUNC();
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode IObjBase::show(int * /*ret_val*/, va_list /*vars*/) {
    visibility = true;
    return ErrorCode::OK;
}
ErrorCode IObjBase::hide(int * /*ret_val*/, va_list /*vars*/) {
    visibility = false;
    return ErrorCode::OK;
}
ErrorCode IObjBase::visible(int *ret_val, va_list vars) const {
    *ret_val = visibility;
    return ErrorCode::OK;
}

ErrorCode IObjBase::getWidth(CoordType *ret_val, va_list vars) {
    width    = nativeGetWidth();
    *ret_val = width;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getHeight(CoordType *ret_val, va_list vars) {
    height   = nativeGetHeight();
    *ret_val = height;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getX(CoordType *ret_val, va_list vars) {
    *ret_val = nativeGetX();
    x        = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getY(CoordType *ret_val, va_list vars) {
    *ret_val = nativeGetY();
    y        = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getCoords(RectType *ret_val, va_list vars) {
    *ret_val = nativeGetCoords();
    return ErrorCode::Done;
}
ErrorCode IObjBase::getOriCoords(RectType *ret_val, va_list vars) {
    *ret_val = nativeGetOriCoords();
    return ErrorCode::Done;
}
ErrorCode IObjBase::getRect(RectSizeType *ret_val, va_list vars) {
    *ret_val = nativeGetRect();
    return ErrorCode::Done;
}
ErrorCode IObjBase::getScrollCoords(BoxType *ret_val, va_list vars) {
    *ret_val = nativeGetScrollCoords();
    return ErrorCode::Done;
}
ErrorCode IObjBase::getScrollLeft(CoordType *ret_val, va_list vars) {
    *ret_val = nativeGetScrollLeft();
    return ErrorCode::Done;
}
ErrorCode IObjBase::getScrollTop(CoordType *ret_val, va_list vars) {
    *ret_val = nativeGetScrollTop();
    return ErrorCode::Done;
}
ErrorCode IObjBase::getScrollRight(CoordType *ret_val, va_list vars) {
    *ret_val = nativeGetScrollRight();
    return ErrorCode::Done;
}
ErrorCode IObjBase::getScrollBottom(CoordType *ret_val, va_list vars) {
    *ret_val = nativeGetScrollBottom();
    return ErrorCode::Done;
}
ErrorCode IObjBase::setWidth(void *ret_val, va_list vars) {
    width = va_arg(vars, int);
    nativeSetWidth(width);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setHeight(void *ret_val, va_list vars) {
    height = va_arg(vars, int);
    nativeSetHeight(height);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setX(void *ret_val, va_list vars) {
    x = va_arg(vars, int);
    nativeSetX(x);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setY(void *ret_val, va_list vars) {
    y = va_arg(vars, int);
    nativeSetY(y);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setCoords(void *ret_val, va_list vars) {
    
    return ErrorCode::Done;
}
ErrorCode IObjBase::setOriCoords(void *ret_val, va_list vars) {
    return ErrorCode::Done;
}
ErrorCode IObjBase::setRect(void *ret_val, va_list vars) {
    return ErrorCode::Done;
}
ErrorCode IObjBase::setScrollCoords(void *ret_val, va_list vars) {
    return ErrorCode::Done;
}
ErrorCode IObjBase::setScrollLeft(void *ret_val, va_list vars) {
    return ErrorCode::Done;
}
ErrorCode IObjBase::setScrollTop(void *ret_val, va_list vars) {
    return ErrorCode::Done;
}
ErrorCode IObjBase::setScrollRight(void *ret_val, va_list vars) {
    return ErrorCode::Done;
}
ErrorCode IObjBase::setScrollBottom(void *ret_val, va_list vars) {
    return ErrorCode::Done;
}


// ********************************************************************
// *                        Native Operations                         *
// ********************************************************************

// ***************************** Getters ******************************
void *IObjBase::nativeGetParent() { return nullptr; }
CoordType IObjBase::nativeGetWidth() { return 0; }
CoordType IObjBase::nativeGetHeight() { return 0; }
CoordType IObjBase::nativeGetX() { return 0; }
CoordType IObjBase::nativeGetY() { return 0; }
RectType IObjBase::nativeGetCoords() { return {}; }
RectType IObjBase::nativeGetOriCoords() { return {}; }
RectSizeType IObjBase::nativeGetRect() { return {}; }
BoxType IObjBase::nativeGetScrollCoords() { return {}; }
CoordType IObjBase::nativeGetScrollLeft() { return 0; }
CoordType IObjBase::nativeGetScrollTop() { return 0; }
CoordType IObjBase::nativeGetScrollRight() { return 0; }
CoordType IObjBase::nativeGetScrollBottom() { return 0; }
// ***************************** Setters ******************************
void IObjBase::nativeSetParent(void * /*p*/) {}
void IObjBase::nativeSetWidth(CoordType /*w*/) {}
void IObjBase::nativeSetHeight(CoordType /*h*/) {}
void IObjBase::nativeSetX(CoordType /*x*/) {}
void IObjBase::nativeSetY(CoordType /*y*/) {}
void IObjBase::nativeSetCoords(RectType /*coords*/) {}
void IObjBase::nativeSetScrollCoords(BoxType /*box*/) {}
void IObjBase::nativeSetScrollLeft(CoordType /*x*/) {}
void IObjBase::nativeSetScrollTop(CoordType /*y*/) {}
void IObjBase::nativeSetScrollRight(CoordType /*x*/) {}
void IObjBase::nativeSetScrollBottom(CoordType /*y*/) {}
