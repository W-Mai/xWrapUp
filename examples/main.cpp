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
    lvObj screen(nullptr);
    screen.native(lv_scr_act());

    IObjBase *objBase;
    lvObj obj(&screen);

    objBase = &obj;
    cout << objBase->type() << endl;
    uint32_t res;
    objBase->setAttr(AE(IObjBase) Width, nullptr, 200);
    objBase->setAttr(AE(IObjBase) Height, nullptr, 300);
    objBase->getAttr(AE(IObjBase) Width, &res);

    cout << res << endl;

    cout << objBase->parent() << endl;

    lvObj obj2(&obj);
}
