//
// Created by W-Mai on 2023/4/14.
//

#ifndef XWRAPUP_TEMPLATES_H
#define XWRAPUP_TEMPLATES_H
#include <tuple>

template<class T, class... ARGS>
T exec(IObjBase *obj, IDType id, ARGS... args) {
    T rtn{};
    obj->exec(id, &rtn, args...);
    return rtn;
}

template<class... ARGS>
ErrorCode setAttr(IObjBase *obj, IDType id, ARGS... args) {
#ifdef XWU_USE_STD_ARGS
    return obj->setAttr(id, nullptr, args...);
#else
    auto first_arg = std::get<0>(std::make_tuple(args...));
    return obj->setAttr(id, nullptr, (ParamPack &) first_arg);
#endif
}
template<class T, class... ARGS>
T getAttr(IObjBase *obj, IDType id, ARGS... args) {
    T rtn{};
#ifdef XWU_USE_STD_ARGS
    obj->getAttr(id, &rtn, args...);
#else
    obj->getAttr(id, &rtn, (ParamPack &) rtn);
#endif
    return rtn;
}

#endif//XWRAPUP_TEMPLATES_H
