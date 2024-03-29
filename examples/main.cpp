//
// Created by W-Mai on 2023/2/22.
//

#include <iostream>
#include <lvObj.h>
#include <lv_port/lv_port.h>
#include <lvgl.h>
#include <src/misc/lv_gc.h>
#include <xWrapUp.h>

LV_ROOTS

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

const static WrapperContext *context;

void wrapper_init() {
    lvObj::init();

    static wrapper_context_t ctx = {
        .kps = nullptr,
        .cnt = 0,
    };
    // register constructors
    wu_obj_register(
        &ctx,
        lvObj::ID,
        (obj_constructor_func) lvObj::constructor,
        (obj_destructor_func) lvObj::destructor
    );
    context = &ctx;
}

void app_create() {
    IObjBase *objBase;
    // use c api to create obj
    auto screen = (lvObj *) wu_obj_create(context, lvObj::ID, nullptr);
    screen->native(lv_scr_act());

    // use constructor to create obj
    auto obj  = lvObj::constructor(screen);
    auto obj2 = lvObj::constructor(screen);

    objBase   = obj;
    cout << objBase->type() << endl;
    cout << objBase->parent() << endl;

    setAttr(objBase, AE(IObjBase) Width, 200);
    setAttr(objBase, AE(IObjBase) Height, 300);
    setAttr(objBase, AE(IObjBase) X, 300);
    setAttr(objBase, AE(IObjBase) Y, 100);

    obj2->parent(objBase);
    setAttr(obj2, AE(IObjBase) Width, 100);
    setAttr(obj2, AE(IObjBase) Height, 100);
    setAttr(obj2, AE(IObjBase) X, 30);
    setAttr(obj2, AE(IObjBase) X, 10);
    // use c api to set attr
    CoordType x = 100;
    wu_obj_set_attr(obj2, AE(IObjBase) X, nullptr, VAR_PACK(x));

    auto res = getAttr<CoordType>(objBase, AE(IObjBase) Width);
    cout << res << endl;

    // use c api to destroy obj
    //    wu_obj_destroy(context, lvObj::ID, obj2);

    // use destructor to destroy obj
    //    lvObj::destructor(obj);

    // use c api to get attr for screen

    int width;
    wu_obj_get_attr(screen, AE(IObjBase) Width, &width, VAR_NONE);
    cout << width << endl;

    // scroll
    setAttr(obj, AE(IObjBase) ScrollRight, 10);
    auto rect = getAttr<RectType>(obj, AE(IObjBase) ScrollCoords);
    cout << rect.x0 << " " << rect.y0 << " " << rect.x1 << " " << rect.y1
         << endl;

    // get rect
    auto rect2 = getAttr<RectType>(obj2, AE(IObjBase) Rect);
    cout << rect2.x0 << " " << rect2.y0 << " " << rect2.x1 << " " << rect2.y1
         << endl;
}
