//
// Created by W-Mai on 2023/4/14.
//

#ifndef XWRAPUP_TEMPLATES_H
#define XWRAPUP_TEMPLATES_H

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

#endif//XWRAPUP_TEMPLATES_H
