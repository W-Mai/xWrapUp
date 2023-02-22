//
// Created by W-Mai on 2023/2/22.
//

#include <iostream>
#include <xWrapUp.h>

int main() {
    ObjBase objBase{};
    ObjBase::init();

    objBase.exec<void>(FE(ObjBase) setAttr, 10, 20);
    int a = objBase.exec<int>(FE(ObjBase) getAttr);

    std::cout << a << std::endl;
    return 0;
}
