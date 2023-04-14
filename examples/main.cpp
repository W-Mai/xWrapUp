//
// Created by W-Mai on 2023/2/22.
//

#include "lvObj.h"
#include "lv_port/lv_port.h"
#include "lvgl/lvgl.h"
#include <iostream>
#include <src/misc/lv_gc.h>
#include <xWrapUp.h>

LV_ROOTS

template<class T, class... ARGS>
T exec(IObjBase *obj, IDType id, ARGS... args) {
    T rtn{};
    obj->exec(id, &rtn, args...);
    return rtn;
}
template<class... ARGS>
ErrorCode setAttr(IObjBase *obj, IDType id, ARGS... args) {
    return obj->setAttr(id, nullptr, args...);
}
template<class T, class... ARGS>
T getAttr(IObjBase *obj, IDType id, ARGS... args) {
    T rtn{};
    obj->getAttr(id, &rtn, args...);
    return rtn;
}

void wrapper_init();
void app_create();

int main() {
    wrapper_init();

#if LV_USE_LOG
    lv_log_register_print_cb([](lv_log_level_t level, const char *str) {
        printf("%s", str);
    });
#endif

    lv_init();


    if (lv_port_init() < 0) {
        LV_LOG_USER("hal init failed");
        return -1;
    }

    app_create();

    while (true) {
        uint32_t idle = lv_timer_handler();
        lv_port_sleep(idle ? idle : 1);
    }

    return 0;
}


using namespace std;
void wrapper_init() { lvObj::init(); }

void app_create() {
    IObjBase *objBase;

    lvObj screen(nullptr);
    screen.native(lv_scr_act());

    lvObj obj(&screen);
    lvObj obj2(&obj);

    objBase = &obj;
    cout << objBase->type() << endl;
    cout << objBase->parent() << endl;

    setAttr(objBase, AE(IObjBase) Width, 200);
    setAttr(objBase, AE(IObjBase) Height, 300);
    setAttr(objBase, AE(IObjBase) X, 300);
    setAttr(objBase, AE(IObjBase) Y, 100);

    setAttr(&obj2, AE(IObjBase) Width, 100);
    setAttr(&obj2, AE(IObjBase) Height, 100);
    setAttr(&obj2, AE(IObjBase) X, 30);
    setAttr(&obj2, AE(IObjBase) X, 10);

    auto res = getAttr<coordType>(objBase, AE(IObjBase) Width);
    cout << res << endl;
}
