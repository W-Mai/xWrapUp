//
// Created by W-Mai on 2023/2/22.
//

#include <iface/IObjBase.h>

#define CURRENT_CLASS_NAME IObjBase

DEFI_FUNC_MAP;
DEFI_ATTR_MAP;

ErrorCode IObjBase::getAttr(IDType id, void *ret_val, VAR_ARGS) {
    VAR_START(vars, ret_val);
    auto code = getAttr(id, ret_val, vars);
    VAR_END(vars);
    return code;
}

ErrorCode IObjBase::setAttr(IDType id, void *ret_val, VAR_ARGS) {
    VAR_START(vars, ret_val);
    auto code = setAttr(id, ret_val, vars);
    VAR_END(vars);
    return code;
}

ErrorCode IObjBase::exec(IDType id, void *ret_val, VAR_ARGS) {
    VAR_START(vars, ret_val);
    auto code = exec(id, ret_val, vars);
    VAR_END(vars);
    return code;
}

ErrorCode IObjBase::getAttr(IDType id, void *ret_val, VAR_LIST(vars)) {
    auto func = FETCH_ATTR_FUNC(get);
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode IObjBase::setAttr(IDType id, void *ret_val, VAR_LIST(vars)) {
    auto func = FETCH_ATTR_FUNC(set);
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode IObjBase::exec(IDType id, void *ret_val, VAR_LIST(vars)) {
    auto func = FETCH_EXEC_FUNC();
    if (func == nullptr) return ErrorCode::Error;
    return (this->*(func))(ret_val, vars);
}

ErrorCode IObjBase::show(int * /*ret_val*/, VAR_LIST(vars)) {
    visibility = true;
    return ErrorCode::OK;
}
ErrorCode IObjBase::hide(int * /*ret_val*/, VAR_LIST(vars)) {
    visibility = false;
    return ErrorCode::OK;
}
ErrorCode IObjBase::visible(int *ret_val, VAR_LIST(vars)) const {
    *ret_val = visibility;
    return ErrorCode::OK;
}

ErrorCode IObjBase::getWidth(CoordType *ret_val, VAR_LIST(vars)) {
    Rect.w   = nativeGetWidth();
    *ret_val = Rect.w;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getHeight(CoordType *ret_val, VAR_LIST(vars)) {
    Rect.h   = nativeGetHeight();
    *ret_val = Rect.h;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getX(CoordType *ret_val, VAR_LIST(vars)) {
    *ret_val = nativeGetX();
    Rect.x   = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getY(CoordType *ret_val, VAR_LIST(vars)) {
    *ret_val = nativeGetY();
    Rect.y   = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getCoords(RectType *ret_val, VAR_LIST(vars)) {
    *ret_val = nativeGetCoords();
    Coords   = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getOriCoords(RectType *ret_val, VAR_LIST(vars)) {
    *ret_val  = nativeGetOriCoords();
    OriCoords = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getRect(RectSizeType *ret_val, VAR_LIST(vars)) {
    *ret_val = nativeGetRect();
    Rect     = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getScrollCoords(BoxType *ret_val, VAR_LIST(vars)) {
    *ret_val     = nativeGetScrollCoords();
    ScrollCoords = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getScrollLeft(CoordType *ret_val, VAR_LIST(vars)) {
    *ret_val          = nativeGetScrollLeft();
    ScrollCoords.left = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getScrollTop(CoordType *ret_val, VAR_LIST(vars)) {
    *ret_val         = nativeGetScrollTop();
    ScrollCoords.top = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getScrollRight(CoordType *ret_val, VAR_LIST(vars)) {
    *ret_val           = nativeGetScrollRight();
    ScrollCoords.right = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::getScrollBottom(CoordType *ret_val, VAR_LIST(vars)) {
    *ret_val            = nativeGetScrollBottom();
    ScrollCoords.bottom = *ret_val;
    return ErrorCode::OK;
}
ErrorCode IObjBase::setWidth(void *ret_val, VAR_LIST(vars)) {
    Rect.w = VAR_GET(vars, int);
    nativeSetWidth(Rect.w);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setHeight(void *ret_val, VAR_LIST(vars)) {
    Rect.h = VAR_GET(vars, int);
    nativeSetHeight(Rect.h);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setX(void *ret_val, VAR_LIST(vars)) {
    Rect.x = VAR_GET(vars, int);
    nativeSetX(Rect.x);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setY(void *ret_val, VAR_LIST(vars)) {
    Rect.y = VAR_GET(vars, int);
    nativeSetY(Rect.y);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setCoords(void *ret_val, VAR_LIST(vars)) {
    Coords = VAR_GET(vars, RectType);
    nativeSetCoords(Coords);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setOriCoords(void * /*ret_val*/, VAR_LIST(vars)) {
    return ErrorCode::Error;
}
ErrorCode IObjBase::setRect(void * /*ret_val*/, VAR_LIST(vars)) {
    return ErrorCode::Error;
}
ErrorCode IObjBase::setScrollCoords(void *ret_val, VAR_LIST(vars)) {
    ScrollCoords = VAR_GET(vars, BoxType);
    nativeSetScrollCoords(ScrollCoords);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setScrollLeft(void *ret_val, VAR_LIST(vars)) {
    ScrollCoords.left = VAR_GET(vars, CoordType);
    nativeSetScrollLeft(ScrollCoords.left);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setScrollTop(void *ret_val, VAR_LIST(vars)) {
    ScrollCoords.top = VAR_GET(vars, CoordType);
    nativeSetScrollTop(ScrollCoords.top);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setScrollRight(void *ret_val, VAR_LIST(vars)) {
    ScrollCoords.right = VAR_GET(vars, CoordType);
    nativeSetScrollRight(ScrollCoords.right);
    return ErrorCode::OK;
}
ErrorCode IObjBase::setScrollBottom(void *ret_val, VAR_LIST(vars)) {
    ScrollCoords.bottom = VAR_GET(vars, CoordType);
    nativeSetScrollBottom(ScrollCoords.bottom);
    return ErrorCode::OK;
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
void IObjBase::nativeSetScrollLeft(CoordType /*left*/) {}
void IObjBase::nativeSetScrollTop(CoordType /*top*/) {}
void IObjBase::nativeSetScrollRight(CoordType /*right*/) {}
void IObjBase::nativeSetScrollBottom(CoordType /*bottom*/) {}
