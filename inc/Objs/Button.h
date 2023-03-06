//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_BUTTON_H
#define XWRAPUP_BUTTON_H

#include "ObjBase.h"
#include "enums/EButton.h"

#define CURRENT_CLASS_NAME Button

CLASS_BEGIN(Button, OBJ_CONSTRUCTOR(), { CLASS_OBJ_INIT_ITEM_ATTR(Test); })

public:
Button() = default;

//void registerCb() {}

protected:
ErrorCode getAttr(IDType id, void *ret_val, va_list vars) override;
ErrorCode setAttr(IDType id, void *ret_val, va_list vars) override;
ErrorCode exec(IDType id, void *ret_val, va_list vars) override;

protected:
ErrorCode getTest(int *ret_val, va_list vars);
ErrorCode setTest(void *ret_val, va_list vars);

private:
bool visibility{};
int width{};

CLASS_END(Button)
#undef CURRENT_CLASS_NAME// remember to clear macros

#endif//XWRAPUP_BUTTON_H
