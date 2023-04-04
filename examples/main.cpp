//
// Created by W-Mai on 2023/2/22.
//

#include <iostream>
#include <xWrapUp.h>

template<class T, class... ARGS>
T exec(ObjBase *obj, IDType id, ARGS... args) {
    T rtn{};
    obj->exec(id, &rtn, args...);
    return rtn;
}

int main() {
    ObjBase::init();
    Button::init();

    ObjBase *objBase;
    auto button  = new Button();
    objBase      = button;

    bool visible = false;
    objBase->exec(FE(ObjBase) show, nullptr);
    visible = exec<bool>(objBase, FE(ObjBase) visible);
    std::cout << "visible: " << visible << std::endl;
    exec<void *>(objBase, FE(ObjBase) hide);
    visible = exec<bool>(objBase, FE(ObjBase) visible);
    std::cout << "visible: " << visible << std::endl;

    objBase->setAttr(AE(Button) Test, nullptr, 20);
    int val;
    std::cout << (objBase->getAttr(AE(Button) Test, &val) == ErrorCode::Done)
              << std::endl;
    std::cout << val << std::endl;

    std::cout << objBase->type() << std::endl;

    return 0;
}
