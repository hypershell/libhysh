
#pragma once

#include <stdlib.h>
#include <hysh/interface/object.h>

static const hy_iid hy_deallocator_iid  = 0x1e628c75ab8a4a5e;
static const hy_iid hy_allocator_iid    = 0x9ccc3668dd6e5b83;

typedef struct hy_deallocator {
    hy_object parent;
    
    hyresult (*deallocate)(void *self, void *ptr);
} hy_deallocator;

typedef struct hy_allocator {
    hy_deallocator parent;

    hyresult (*allocate)(void *self, size_t size, void **retval);
} hy_allocator;