//
// Created by W-Mai on 2023/4/14.
//

#ifndef XWRAPUP_LVOBJ_H
#define XWRAPUP_LVOBJ_H

#include <xWrapUp.h>

class lvObj : public IObjBase {
public:
    explicit lvObj(IObjBase *parent) : IObjBase(parent) {}
};


#endif//XWRAPUP_LVOBJ_H
