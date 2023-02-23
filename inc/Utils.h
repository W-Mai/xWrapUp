//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_UTILS_H
#define XWRAPUP_UTILS_H


#define MAP_TYPE std::map
#define FUNC_MAP_NAME func_map
#define ATTR_MAP_NAME attr_map
#define CLASS_FUNC_TYPE(NAME) NAME##_CLASS_FUNC_TYPE

#define BASE_CLASS_BEGIN(CLASS_NAME, ...)                                      \
    class CLASS_NAME;                                                          \
    using CLASS_FUNC_TYPE(CLASS_NAME) = void (CURRENT_CLASS_NAME::*)();        \
    struct CLASS_NAME##_ATTR_FUNC_PACK {                                       \
        CLASS_FUNC_TYPE(CLASS_NAME) get;                                       \
        CLASS_FUNC_TYPE(CLASS_NAME) set;                                       \
    };                                                                         \
    class CURRENT_CLASS_NAME {                                                 \
    public:                                                                    \
        static MAP_TYPE<                                                       \
            FUNC_ENUM_NAME(CURRENT_CLASS_NAME),                                \
            void (CURRENT_CLASS_NAME::*)()>                                    \
            FUNC_MAP_NAME;                                                     \
        static MAP_TYPE<                                                       \
            ATTR_ENUM_NAME(CURRENT_CLASS_NAME),                                \
            CLASS_NAME##_ATTR_FUNC_PACK>                                       \
            ATTR_MAP_NAME;                                                     \
        CLASS_OBJ_INIT(__VA_ARGS__)


#define BASE_CLASS_END                                                         \
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
        (void(CURRENT_CLASS_NAME::*)()) & ObjBase::ITEM_NAME

#define CLASS_OBJ_INIT_ITEM_ATTR(ITEM_NAME)                                    \
    ATTR_MAP_NAME[ATTR_ENUM_NAME(CURRENT_CLASS_NAME)::ITEM_NAME] = {           \
        (void(CURRENT_CLASS_NAME::*)()) & CURRENT_CLASS_NAME::get##ITEM_NAME,  \
        (void(CURRENT_CLASS_NAME::*)()) & CURRENT_CLASS_NAME::set##ITEM_NAME,  \
    }

#define FUNC_ENUM_NAME(NAME) __CONCAT(ENUM_FUNC_, NAME)
#define FUNC_ENUM(...) enum class FUNC_ENUM_NAME(CURRENT_CLASS_NAME) __VA_ARGS__
#define FUNC_ENUM_ITEM(NAME) NAME
#define FE(CLASS) (uint32_t) FUNC_ENUM_NAME(CLASS)::

#define ATTR_ENUM_NAME(NAME) __CONCAT(ENUM_ATTR_, NAME)
#define ATTR_ENUM(...) enum class ATTR_ENUM_NAME(CURRENT_CLASS_NAME) __VA_ARGS__
#define ATTR_ENUM_ITEM(NAME) NAME
#define AE(CLASS) (uint32_t) ATTR_ENUM_NAME(CLASS)::

#endif//XWRAPUP_UTILS_H
