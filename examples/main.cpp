//
// Created by W-Mai on 2023/2/22.
//

#include <iostream>
#include <xWrapUp.h>

int main() {
    ObjBase objBase{};
    ObjBase::init();

    objBase.exec<void>(FE(ObjBase) show);
    std::cout << objBase.exec<bool>(FE(ObjBase) visible) << std::endl;
    objBase.exec<void>(FE(ObjBase) hide);
    std::cout << objBase.exec<bool>(FE(ObjBase) visible) << std::endl;

    return 0;
}
