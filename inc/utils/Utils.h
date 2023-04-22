//
// Created by W-Mai on 2023/2/22.
//

#ifndef XWRAPUP_UTILS_H
#define XWRAPUP_UTILS_H
#include <IDGenerator.h>

using IDType    = IDGenerator::IDType;
using CoordType = int32_t;
using PosType   = struct {
    CoordType x;
    CoordType y;
};
using SizeType = struct {
    CoordType w;
    CoordType h;
};
using RectType = struct {
    CoordType x0;
    CoordType y0;
    CoordType x1;
    CoordType y1;
};
using RectSizeType = struct {
    CoordType x;
    CoordType y;
    CoordType w;
    CoordType h;
};
using BoxType = struct {
    CoordType left;
    CoordType top;
    CoordType right;
    CoordType bottom;
};
using id_type_t      = IDType;
using coord_type     = CoordType;
using pos_type       = PosType;
using size_type      = SizeType;
using rect_type      = RectType;
using rect_size_type = RectSizeType;
using box_type       = BoxType;

#define MAP_TYPE std::map

#define FUNC_MAP_NAME func_map
#define ATTR_MAP_NAME attr_map
#define DECL_FUNC_MAP(CLASS_NAME)                                              \
    static MAP_TYPE<IDType, CLASS_FUNC_TYPE> FUNC_MAP_NAME
#define DECL_ATTR_MAP(CLASS_NAME)                                              \
    static MAP_TYPE<IDType, ATTR_FUNC_PACK> ATTR_MAP_NAME

#define DEFI_FUNC_MAP                                                          \
    MAP_TYPE<IDType, CURRENT_CLASS_NAME::CLASS_FUNC_TYPE>                      \
        CURRENT_CLASS_NAME::FUNC_MAP_NAME
#define DEFI_ATTR_MAP                                                          \
    MAP_TYPE<IDType, CURRENT_CLASS_NAME::ATTR_FUNC_PACK>                       \
        CURRENT_CLASS_NAME::ATTR_MAP_NAME

#define OBJ_BASE_CONSTRUCTOR(CLASS)
#define OBJ_CONSTRUCTOR() : public IObjBase
#define OBJ_CONSTRUCTOR_EX(...) : __VA_ARGS__

#define CLASS_BEGIN(CLASS_NAME, HEADER_CONSTRUCTOR, ...)                       \
    class CLASS_NAME HEADER_CONSTRUCTOR {                                      \
    public:                                                                    \
        using CLASS_FUNC_TYPE  = ErrorCode (CLASS_NAME::*)(void *, va_list);   \
        const static IDType ID = CURRENT_CLASS_ID;                             \
                                                                               \
        struct ATTR_FUNC_PACK {                                                \
            CLASS_FUNC_TYPE get;                                               \
            CLASS_FUNC_TYPE set;                                               \
        };                                                                     \
        DECL_FUNC_MAP(CLASS_NAME);                                             \
        DECL_ATTR_MAP(CLASS_NAME);                                             \
        CLASS_OBJ_INIT(__VA_ARGS__)                                            \
        virtual const char *type() { return __type; }                          \
        IObjBase *parent(IObjBase *parent = nullptr) {                         \
            if (parent) {                                                      \
                __parent = parent;                                             \
                nativeSetParent(__parent->native());                           \
            }                                                                  \
            return __parent;                                                   \
        };                                                                     \
        void *native(void *nat = nullptr) {                                    \
            if (nat) __native = nat;                                           \
            return __native;                                                   \
        }                                                                      \
        CLASS_NAME() = delete;                                                 \
        static IObjBase *constructor(IObjBase *par = nullptr) {                \
            return new CLASS_NAME(par);                                        \
        }                                                                      \
        static void destructor(IObjBase *obj) { delete obj; }                  \
                                                                               \
    private:                                                                   \
        const char *__type = #CLASS_NAME;                                      \
        void *__native     = nullptr;                                          \
        IObjBase *__parent;


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
        (CLASS_FUNC_TYPE) &CURRENT_CLASS_NAME::ITEM_NAME

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
#define AE(CLASS) (IDType) ATTR_ENUM_NAME(CLASS)::

#define IDGEN_START(X) const IDType ENUM_START = IDGenerator::set((X))
#define IDGEN_END() const IDType ENUM_END = IDGenerator::get()

#define FETCH_ATTR_FUNC(TYPE)                                                  \
    ({                                                                         \
        auto __func_pack       = ATTR_MAP_NAME.find(id);                       \
        CLASS_FUNC_TYPE __func = nullptr;                                      \
        if (__func_pack != ATTR_MAP_NAME.end())                                \
            __func = __func_pack->second.TYPE;                                 \
        __func;                                                                \
    })

#define FETCH_EXEC_FUNC()                                                      \
    ({                                                                         \
        auto __func_iter       = FUNC_MAP_NAME.find(id);                       \
        CLASS_FUNC_TYPE __func = nullptr;                                      \
        if (__func_iter != FUNC_MAP_NAME.end()) __func = __func_iter->second;  \
        __func;                                                                \
    });

enum class ErrorCode {
    Done  = 0,// Don't Care
    OK    = 1,// Right
    Error = 2,// Failed
};

using ObjConstructorFunc   = void *(*) (void *par);
using ObjDestructorFunc    = void *(*) (void *obj);
using obj_constructor_func = ObjConstructorFunc;
using obj_destructor_func  = ObjDestructorFunc;
typedef struct WrapperContext {
    struct KPS {
        IDType type;
        ObjConstructorFunc constructor;
        ObjDestructorFunc destructor;
    } *kps;

    CoordType cnt;
} wrapper_context_t;
#endif//XWRAPUP_UTILS_H
