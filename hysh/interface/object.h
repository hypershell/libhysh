#pragma once

#include <hysh/interface/result.h>

typedef uint64_t hy_iid;
typedef uint64_t hy_cid;
typedef uint64_t hy_sid;

static const hy_iid hy_object_iid               = 0xddf77f236d269563;
static const hy_iid hy_refcounted_object_iid    = 0xf343e0cb78d92aa7;

typedef struct hy_object {
    void *self;
    
    hyresult (*query_interface)(void *self, hy_iid interface, struct hy_object **retval);
    
    hyresult (*class_id)(void *self, hy_cid *retval);
} hy_object;

typedef struct hy_refcounted_object {
    hy_object parent;
    
    hyresult (*add_ref)(void *self);
    
    hyresult (*de_ref)(void *self);
} hy_refcounted_object;

typedef hyresult (*hy_destructor)(void *self);