#pragma once

#include <hysh/interface/object.h>

static const hy_iid hy_data_buffer_iid = 0x5c59a76540e84ba7;

typedef struct hy_data_buffer {
    hy_refcounted_object parent;
    
    hyresult (*buffer)(void *self, const char **retval);
    
    hyresult (*size)(void *self, uint64_t *retval);
} hy_data_buffer;