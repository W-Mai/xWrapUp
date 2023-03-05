//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_UTILS_H
#define XWRAPUP_UTILS_H
#include "IDGenerator.h"

using IDType = IDGenerator::IDType;

#define MAP_TYPE std::map
#define FUNC_MAP_NAME func_map
#define ATTR_MAP_NAME attr_map
#define DECL_FUNC_MAP(CLASS_NAME)                                              \
    static MAP_TYPE<IDType, CLASS_FUNC_TYPE> FUNC_MAP_NAME
#define DECL_ATTR_MAP(CLASS_NAME)                                              \
    static MAP_TYPE<IDType, ATTR_FUNC_PACK> ATTR_MAP_NAME

#define DEFI_FUNC_MAP                                                          \
    MAP_TYPE<IDType, void (CURRENT_CLASS_NAME::*)()>                           \
        CURRENT_CLASS_NAME::FUNC_MAP_NAME

#define DEFI_ATTR_MAP                                                          \
    MAP_TYPE<IDType, CURRENT_CLASS_NAME::ATTR_FUNC_PACK>                       \
        CURRENT_CLASS_NAME::ATTR_MAP_NAME

#define OBJ_BASE_CONSTRUCTOR(CLASS)
#define OBJ_CONSTRUCTOR() : public ObjBase
#define OBJ_CONSTRUCTOR_EX(...) : __VA_ARGS__

#define CLASS_BEGIN(CLASS_NAME, HEADER_CONSTRUCTOR, ...)                       \
    class CLASS_NAME HEADER_CONSTRUCTOR {                                      \
    public:                                                                    \
        using CLASS_FUNC_TYPE = void (CLASS_NAME::*)();                        \
        struct ATTR_FUNC_PACK {                                                \
            CLASS_FUNC_TYPE get;                                               \
            CLASS_FUNC_TYPE set;                                               \
        };                                                                     \
        DECL_FUNC_MAP(CLASS_NAME);                                             \
        DECL_ATTR_MAP(CLASS_NAME);                                             \
        CLASS_OBJ_INIT(__VA_ARGS__)                                            \
    private:

#define CLASS_END(CLASS_NAME)                                                  \
    }                                                                          \
    ;

#define CLASS_OBJ_INIT(...)                                                    \
public:                                                                        \
    static void init() {                                                       \
        if (!FUNC_MAP_NAME.empty()) return;                                    \
        __VA_ARGS__                                                            \
    }

#define CLASS_OBJ_INIT_ITEM(ITEM_NAME)                                         \
    FUNC_MAP_NAME[FUNC_ENUM_NAME(CURRENT_CLASS_NAME)::ITEM_NAME] =             \
        (CLASS_FUNC_TYPE) &ObjBase::ITEM_NAME

#define CLASS_OBJ_INIT_ITEM_ATTR(ITEM_NAME)                                    \
    ATTR_MAP_NAME[ATTR_ENUM_NAME(CURRENT_CLASS_NAME)::ITEM_NAME] = {           \
        .get = (CLASS_FUNC_TYPE) &CURRENT_CLASS_NAME::get##ITEM_NAME,          \
        .set = (CLASS_FUNC_TYPE) &CURRENT_CLASS_NAME::set##ITEM_NAME,          \
    }

#define FUNC_ENUM_NAME(NAME) __CONCAT(ENUM_FUNC_, NAME)
#define FUNC_ENUM(...) namespace FUNC_ENUM_NAME(CURRENT_CLASS_NAME) __VA_ARGS__
#define FUNC_ENUM_ITEM(NAME) const IDType NAME = IDGenerator::get()
#define FE(CLASS) (uint32_t) FUNC_ENUM_NAME(CLASS)::

#define ATTR_ENUM_NAME(NAME) __CONCAT(ENUM_ATTR_, NAME)
#define ATTR_ENUM(...) namespace ATTR_ENUM_NAME(CURRENT_CLASS_NAME) __VA_ARGS__
#define ATTR_ENUM_ITEM(NAME) const IDType NAME = IDGenerator::get()
#define AE(CLASS) (uint32_t) ATTR_ENUM_NAME(CLASS)::

#define IDGEN_START(X) const IDType _ = IDGenerator::set((X))

#define FETCH_ATTR_GET_FUNC()                                                  \
    ({                                                                         \
        auto func_pack = ATTR_MAP_NAME.find(id);                               \
        if (func_pack == ATTR_MAP_NAME.end()) return T();                      \
        (T(CURRENT_CLASS_NAME::*)(ARGS...)) func_pack->second.get;             \
    });

#define FETCH_ATTR_SET_FUNC()                                                  \
    ({                                                                         \
        auto func_pack = ATTR_MAP_NAME.find(id);                               \
        if (func_pack == ATTR_MAP_NAME.end()) return;                          \
        (T(CURRENT_CLASS_NAME::*)(ARGS...)) func_pack->second.set;             \
    })

#define FETCH_EXEC_FUNC()                                                      \
    ({                                                                         \
        auto func_iter = FUNC_MAP_NAME.find(id);                               \
        if (func_iter == FUNC_MAP_NAME.end()) return T();                      \
        (T(CURRENT_CLASS_NAME::*)(ARGS...)) func_iter->second;                 \
    });

#endif//XWRAPUP_UTILS_H
