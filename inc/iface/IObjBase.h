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
})

public:
explicit IObjBase(IObjBase *parent) : __parent(parent) {}

virtual ErrorCode getAttr(IDType id, void *ret_val, ...);
virtual ErrorCode setAttr(IDType id, void *ret_val, ...);
virtual ErrorCode exec(IDType id, void *ret_val, ...);

//void registerCb() {}

virtual ErrorCode getAttr(IDType id, void *ret_val, va_list vars);
virtual ErrorCode setAttr(IDType id, void *ret_val, va_list vars);
virtual ErrorCode exec(IDType id, void *ret_val, va_list vars);

protected:
ErrorCode show(int * /*ret_val*/, va_list /*vars*/);
ErrorCode hide(int * /*ret_val*/, va_list /*vars*/);
ErrorCode visible(int *ret_val, va_list vars) const;

ErrorCode getWidth(int *ret_val, va_list vars);
ErrorCode getHeight(int *ret_val, va_list vars);
ErrorCode getX(int *ret_val, va_list vars);
ErrorCode getY(int *ret_val, va_list vars);

ErrorCode setWidth(void *ret_val, va_list vars);
ErrorCode setHeight(void *ret_val, va_list vars);
ErrorCode setX(void *ret_val, va_list vars);
ErrorCode setY(void *ret_val, va_list vars);

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
// ***************************** Setters ******************************
virtual void nativeSetParent(void *par);
virtual void nativeSetWidth(CoordType w);
virtual void nativeSetHeight(CoordType h);
virtual void nativeSetX(CoordType x);
virtual void nativeSetY(CoordType y);

private:
bool visibility{};
CoordType width{};
CoordType height{};
CoordType x{};
CoordType y{};

CLASS_END(IObjBase)
#undef CURRENT_CLASS_NAME// remember to clear macros
#undef CURRENT_CLASS_ID
#endif// XWRAPUP_IOBJBASE_H
