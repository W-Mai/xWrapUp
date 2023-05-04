//
// Created by W-Mai on 2023/2/21.
//

#ifndef XWRAPUP_IOBJBASE_H
#define XWRAPUP_IOBJBASE_H

#include <map>

#include "enums/EObjBase.h"

#define CURRENT_CLASS_NAME IObjBase
#define CURRENT_CLASS_ID 1

CLASS_BEGIN(IObjBase, OBJ_BASE_CONSTRUCTOR(), {
    CLASS_OBJ_INIT_ITEM(show);
    CLASS_OBJ_INIT_ITEM(hide);
    CLASS_OBJ_INIT_ITEM(visible);

    CLASS_OBJ_INIT_ITEM_ATTR(Width);
    CLASS_OBJ_INIT_ITEM_ATTR(Height);
    CLASS_OBJ_INIT_ITEM_ATTR(X);
    CLASS_OBJ_INIT_ITEM_ATTR(Y);
    CLASS_OBJ_INIT_ITEM_ATTR(Coords);
    CLASS_OBJ_INIT_ITEM_ATTR(OriCoords);
    CLASS_OBJ_INIT_ITEM_ATTR(Rect);
    CLASS_OBJ_INIT_ITEM_ATTR(ScrollCoords);
    CLASS_OBJ_INIT_ITEM_ATTR(ScrollLeft);
    CLASS_OBJ_INIT_ITEM_ATTR(ScrollTop);
    CLASS_OBJ_INIT_ITEM_ATTR(ScrollRight);
    CLASS_OBJ_INIT_ITEM_ATTR(ScrollBottom);
})

public:
explicit IObjBase(IObjBase *parent) : __parent(parent) {}

virtual ErrorCode getAttr(IDType id, void *ret_val, VAR_ARGS);
virtual ErrorCode setAttr(IDType id, void *ret_val, VAR_ARGS);
virtual ErrorCode exec(IDType id, void *ret_val, VAR_ARGS);

//void registerCb() {}

virtual ErrorCode getAttr(IDType id, void *ret_val, VAR_LIST(vars));
virtual ErrorCode setAttr(IDType id, void *ret_val, VAR_LIST(vars));
virtual ErrorCode exec(IDType id, void *ret_val, VAR_LIST(vars));

protected:
ErrorCode show(int * /*ret_val*/, VAR_LIST(vars));
ErrorCode hide(int * /*ret_val*/, VAR_LIST(vars));
ErrorCode visible(int *ret_val, VAR_LIST(vars)) const;

ErrorCode getWidth(CoordType *ret_val, VAR_LIST(vars));
ErrorCode getHeight(CoordType *ret_val, VAR_LIST(vars));
ErrorCode getX(CoordType *ret_val, VAR_LIST(vars));
ErrorCode getY(CoordType *ret_val, VAR_LIST(vars));
ErrorCode getCoords(RectType *ret_val, VAR_LIST(vars));
ErrorCode getOriCoords(RectType *ret_val, VAR_LIST(vars));
ErrorCode getRect(RectSizeType *ret_val, VAR_LIST(vars));
ErrorCode getScrollCoords(BoxType *ret_val, VAR_LIST(vars));
ErrorCode getScrollLeft(CoordType *ret_val, VAR_LIST(vars));
ErrorCode getScrollTop(CoordType *ret_val, VAR_LIST(vars));
ErrorCode getScrollRight(CoordType *ret_val, VAR_LIST(vars));
ErrorCode getScrollBottom(CoordType *ret_val, VAR_LIST(vars));

ErrorCode setWidth(void *ret_val, VAR_LIST(vars));
ErrorCode setHeight(void *ret_val, VAR_LIST(vars));
ErrorCode setX(void *ret_val, VAR_LIST(vars));
ErrorCode setY(void *ret_val, VAR_LIST(vars));
ErrorCode setCoords(void *ret_val, VAR_LIST(vars));
ErrorCode setOriCoords(void *ret_val, VAR_LIST(vars));
ErrorCode setRect(void *ret_val, VAR_LIST(vars));
ErrorCode setScrollCoords(void *ret_val, VAR_LIST(vars));
ErrorCode setScrollLeft(void *ret_val, VAR_LIST(vars));
ErrorCode setScrollTop(void *ret_val, VAR_LIST(vars));
ErrorCode setScrollRight(void *ret_val, VAR_LIST(vars));
ErrorCode setScrollBottom(void *ret_val, VAR_LIST(vars));

// ********************************************************************
// *                        Native Operations                         *
// ********************************************************************
protected:
// ***************************** Getters ******************************
virtual void *nativeGetParent();
virtual CoordType nativeGetWidth();
virtual CoordType nativeGetHeight();
virtual CoordType nativeGetX();
virtual CoordType nativeGetY();
virtual RectType nativeGetCoords();
virtual RectType nativeGetOriCoords();
virtual RectSizeType nativeGetRect();
virtual BoxType nativeGetScrollCoords();
virtual CoordType nativeGetScrollLeft();
virtual CoordType nativeGetScrollTop();
virtual CoordType nativeGetScrollRight();
virtual CoordType nativeGetScrollBottom();
// ***************************** Setters ******************************
virtual void nativeSetParent(void *par);
virtual void nativeSetWidth(CoordType w);
virtual void nativeSetHeight(CoordType h);
virtual void nativeSetX(CoordType x);
virtual void nativeSetY(CoordType y);
virtual void nativeSetCoords(RectType coords);
virtual void nativeSetScrollCoords(BoxType box);
virtual void nativeSetScrollLeft(CoordType left);
virtual void nativeSetScrollTop(CoordType top);
virtual void nativeSetScrollRight(CoordType right);
virtual void nativeSetScrollBottom(CoordType bottom);

private:
bool visibility{};
RectSizeType Rect{};
RectType Coords{};
RectType OriCoords{};
BoxType ScrollCoords{};

CLASS_END(IObjBase)
#undef CURRENT_CLASS_NAME// remember to clear macros
#undef CURRENT_CLASS_ID
#endif// XWRAPUP_IOBJBASE_H
