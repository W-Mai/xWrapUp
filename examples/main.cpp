//
// Created by W-Mai on 2023/2/22.
//

#include "lvObj.h"
#include <iostream>
#include <xWrapUp.h>

template<class T, class... ARGS>
T exec(IObjBase *obj, IDType id, ARGS... args) {
    T rtn{};
    obj->exec(id, &rtn, args...);
    return rtn;
}

using namespace std;

int main() {
    lvObj::init();
    IObjBase *objBase;
    lvObj obj(objBase);

    objBase = &obj;
    cout << objBase->type() << endl;
    uint32_t res;
    objBase->setAttr(AE(IObjBase) Width, nullptr, 20);
    objBase->getAttr(AE(IObjBase) Width, &res);

    cout << res << endl;

    cout << objBase->parent() << endl;

    return 0;
}
