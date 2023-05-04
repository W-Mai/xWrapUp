//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_IBUTTON_H
#define XWRAPUP_IBUTTON_H

#include "IObjBase.h"
#include "enums/EButton.h"

#define CURRENT_CLASS_NAME IButton
#define CURRENT_CLASS_ID 10

CLASS_BEGIN(IButton, OBJ_CONSTRUCTOR(), { CLASS_OBJ_INIT_ITEM_ATTR(Test); })

public:
explicit IButton(IObjBase *parent) : IObjBase(parent) {}
//void registerCb() {}

ErrorCode getAttr(IDType id, void *ret_val, VAR_LIST(vars)) override;
ErrorCode setAttr(IDType id, void *ret_val, VAR_LIST(vars)) override;
ErrorCode exec(IDType id, void *ret_val, VAR_LIST(vars)) override;

protected:
ErrorCode getTest(int *ret_val, VAR_LIST(vars));
ErrorCode setTest(void *ret_val, VAR_LIST(vars));

private:
bool visibility{};
int width{};

CLASS_END(IButton)
#undef CURRENT_CLASS_NAME// remember to clear macros
#undef CURRENT_CLASS_ID
#endif//XWRAPUP_IBUTTON_H
