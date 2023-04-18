//
// Created by W-Mai on 2023/4/14.
//

#ifndef XWRAPUP_EXPORT_C_API_H
#define XWRAPUP_EXPORT_C_API_H

#include <utils/Utils.h>

#ifdef __cplusplus
extern "C" {

void wu_obj_register(
    wrapper_context_t *ctx,
    id_type_t type,
    obj_constructor_func cons,
    obj_destructor_func dest
);
void *wu_obj_create(const wrapper_context_t *ctx, id_type_t type, void *parent);
void *wu_obj_destroy(const wrapper_context_t *ctx, id_type_t type, void *obj);

// ****************************** attr ****************************************
// ┌─────┬─────┬─────┬─────┬─────┬─────┐
// │  c  │  i  │  I  │  u  │  U  │  p  │
// ├─────┼─────┼─────┼─────┼─────┼─────┤
// │coord│ i32 │ i64 │ u32 │ u64 │ ptr │
// └─────┴─────┴─────┴─────┴─────┴─────┘

ErrorCode wu_obj_get_attr(void *obj, id_type_t type, void *res);
ErrorCode
wu_obj_set_attr_c(void *obj, id_type_t type, void *res, coord_type val);
};


#endif

#endif//XWRAPUP_EXPORT_C_API_H
