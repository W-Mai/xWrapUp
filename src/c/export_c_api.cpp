//
// Created by W-Mai on 2023/4/14.
//
#include <algorithm>
#include <cstdlib>
#include <xWrapUp.h>

void wu_obj_register(
    wrapper_context_t *ctx,
    id_type_t type,
    obj_constructor_func cons,
    obj_destructor_func dest
) {
    auto res = (wrapper_context_t::KPS *)
        realloc(ctx->kps, (ctx->cnt + 1) * sizeof(wrapper_context_t::KPS));
    assert(res);
    ctx->kps                       = res;

    ctx->kps[ctx->cnt].constructor = cons;
    ctx->kps[ctx->cnt].destructor  = dest;
    ctx->kps[ctx->cnt].type        = type;

    ctx->cnt++;

    std::sort(
        ctx->kps,
        ctx->kps + ctx->cnt,
        [](const WrapperContext::KPS &lhs, const wrapper_context_t::KPS &rhs) {
            return lhs.type < rhs.type;
        }
    );
}

void *
wu_obj_create(const wrapper_context_t *ctx, id_type_t type, void *parent) {
    auto par = (IObjBase *) parent;

    assert(ctx);
    assert(ctx->kps);

    const auto it = std::lower_bound(
        ctx->kps,
        ctx->kps + ctx->cnt,
        type,
        [](const wrapper_context_t ::KPS &kps, const IDType &type) {
            return kps.type < type;
        }
    );

    assert(it != ctx->kps + ctx->cnt && it->type == type);

    auto constructor = it->constructor;

    return constructor(parent);
}

void *wu_obj_destroy(const wrapper_context_t *ctx, id_type_t type, void *obj) {
    auto o = (IObjBase *) obj;

    assert(ctx);
    assert(ctx->kps);

    const auto it = std::lower_bound(
        ctx->kps,
        ctx->kps + ctx->cnt,
        type,
        [](const wrapper_context_t ::KPS &kps, const IDType &type) {
            return kps.type < type;
        }
    );

    assert(it != ctx->kps + ctx->cnt && it->type == type);

    auto destructor = it->destructor;

    return destructor(obj);
}

ErrorCode wu_obj_get_attr(void *obj, id_type_t type, void *res, ...) {
    auto o = (IObjBase *) obj;

    assert(obj);
    assert(res);

    va_list ap;
    va_start(ap, res);
    auto ec = o->getAttr(type, res, ap);
    va_end(ap);
    return ec;
}

ErrorCode wu_obj_set_attr(void *obj, id_type_t type, void *res, ...) {
    auto o = (IObjBase *) obj;

    assert(obj);

    va_list ap;
    va_start(ap, res);
    auto ec = o->setAttr(type, res, ap);
    va_end(ap);
    return ec;
}

ErrorCode
wu_obj_get_attr_v(void *obj, id_type_t type, void *res, va_list vars) {
    auto o = (IObjBase *) obj;

    assert(obj);
    assert(res);

    auto ec = o->getAttr(type, res, vars);
    return ec;
}

ErrorCode
wu_obj_set_attr_v(void *obj, id_type_t type, void *res, va_list vars) {
    auto o = (IObjBase *) obj;

    assert(obj);

    auto ec = o->setAttr(type, res, vars);
    return ec;
}
