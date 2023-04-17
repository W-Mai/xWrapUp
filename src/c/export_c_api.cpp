//
// Created by W-Mai on 2023/4/14.
//
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

ErrorCode wu_obj_get_attr(void *obj, id_type_t type, void *res) {
    auto o = (IObjBase *) obj;

    assert(obj);
    assert(res);

    return o->getAttr(type, res);
}

ErrorCode
wu_obj_set_attr_c(void *obj, id_type_t type, void *res, coord_type val) {
    auto o = (IObjBase *) obj;

    assert(obj);

    return o->setAttr(type, res, val);
}
