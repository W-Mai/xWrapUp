//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_UTILS_H
#define XWRAPUP_UTILS_H

#define MAP_TYPE std::map
#define FUNC_MAP_NAME func_map

#define BASE_CLASS_BEGIN                                                       \
    class CURRENT_CLASS_NAME {                                                 \
    private:                                                                   \
        static MAP_TYPE<                                                       \
            FUNC_ENUM_NAME(CURRENT_CLASS_NAME),                                \
            void (CURRENT_CLASS_NAME::*)()>                                    \
            FUNC_MAP_NAME;

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
    func_map[FUNC_ENUM_NAME(CURRENT_CLASS_NAME)::ITEM_NAME] =                  \
        &ObjBase::ITEM_NAME

#define FUNC_ENUM_NAME(NAME) __CONCAT(ENUM_, NAME)
#define FUNC_ENUM(...) enum class FUNC_ENUM_NAME(CURRENT_CLASS_NAME) __VA_ARGS__
#define FUNC_ENUM_ITEM(NAME) NAME

#endif//XWRAPUP_UTILS_H
