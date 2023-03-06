//
// Created by W-Mai on 2023/2/22.
//

#include <iostream>
#include <xWrapUp.h>

int main() {
    ObjBase::init();
    Button::init();

    ObjBase *objBase;
    auto button = new Button();
    objBase     = button;

    bool val_bool;
    objBase->exec(FE(ObjBase) show, nullptr);
    objBase->exec(FE(ObjBase) visible, &val_bool);
    std::cout << val_bool << std::endl;
    objBase->exec(FE(ObjBase) hide, nullptr);
    objBase->exec(FE(ObjBase) visible, &val_bool);
    std::cout << val_bool << std::endl;

    objBase->setAttr(AE(Button) Test, nullptr, 20);
    int val;
    std::cout << (objBase->getAttr(AE(Button) Test, &val) == ErrorCode::Done)
              << std::endl;
    std::cout << val << std::endl;

    return 0;
}
