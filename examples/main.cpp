//
// Created by W-Mai on 2023/2/22.
//

#include <iostream>
#include <xWrapUp.h>

int main() {
    ObjBase::init();
    Button::init();

    ObjBase* objBase;
    auto button = new Button();
    objBase = button;

    objBase->exec<void>(FE(ObjBase) show);
    std::cout << objBase->exec<bool>(FE(ObjBase) visible) << std::endl;
    objBase->exec<void>(FE(ObjBase) hide);
    std::cout << objBase->exec<bool>(FE(ObjBase) visible) << std::endl;

    objBase->setAttr(AE(Button) Test, nullptr, 20);
    int val;
    std::cout << (objBase->getAttr(AE(Button) Test, &val) == ErrorCode::Done)
              << std::endl;
    std::cout << val << std::endl;

    return 0;
}
