//
// Created by W-Mai on 2023/5/3.
//

#ifndef XWRAPUP_PARAMPACK_H
#define XWRAPUP_PARAMPACK_H

#include <cinttypes>

using ParamPack = struct {};

#ifdef XWU_USE_STD_ARGS
#define VAR_ARGS ...
#define VAR_START(ARG_NAME, LAST_VAR)                                          \
    va_list ARG_NAME;                                                          \
    va_start(ARG_NAME, LAST_VAR)
#define VAR_GET(ARG_NAME, TYPE) va_arg(ARG_NAME, TYPE)
#define VAR_END(ARG_NAME) va_end(ARG_NAME)
#else
#define VAR_ARGS ParamPack &pp
#define VAR_START(ARG_NAME, LAST_VAR) ParamPackOperator ARG_NAME(pp)
#define VAR_GET(ARG_NAME, TYPE) ARG_NAME.get<TYPE>()
#define VAR_END(ARG_NAME)
#endif

class ParamPackOperator {
private:
    uint8_t *Cur;

public:
    explicit ParamPackOperator(ParamPack &pp) {
        Cur = reinterpret_cast<uint8_t *>(&pp);
    }

    template<class T>
    T &get() {
        auto old = Cur;
        Cur += sizeof(T);
        return reinterpret_cast<T &>(*old);
    }
};

#endif//XWRAPUP_PARAMPACK_H
