//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_UTILS_H
#define XWRAPUP_UTILS_H


#define BASE_CLASS_BEGIN(NAME)                                                 \
    class NAME {                                                               \
    private:                                                                   \
        static std::map<FUNC_ENUM_NAME(NAME), void (NAME::*)()> func_map;
#define BASE_CLASS_END(NAME)                                                   \
    }                                                                          \
    ;
#define CLASS_OBJ_INIT(...)                                                    \
public:                                                                        \
    static void init() { __VA_ARGS__ }
#define CLASS_OBJ_INIT_ITEM(CLASS_NAME, ITEM_NAME)                             \
    func_map[FUNC_ENUM_NAME(CLASS_NAME)::ITEM_NAME] = &ObjBase::ITEM_NAME

#define FUNC_ENUM_NAME(NAME) __CONCAT(ENUM_, NAME)
#define FUNC_ENUM(NAME, ...) enum class FUNC_ENUM_NAME(NAME) __VA_ARGS__
#define FUNC_ENUM_ITEM(NAME) NAME

#endif//XWRAPUP_UTILS_H
