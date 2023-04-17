//
// Created by W-Mai on 2023/4/14.
//

#ifndef XWRAPUP_EXPORT_C_API_H
#define XWRAPUP_EXPORT_C_API_H

#include <utils/Utils.h>

void wu_obj_register(
    wrapper_context_t *ctx, id_type_t type, obj_constructor_func cons
);
void *wu_obj_create(const wrapper_context_t *ctx, id_type_t type, void *parent);


#endif//XWRAPUP_EXPORT_C_API_H
