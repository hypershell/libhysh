
#include <stdlib.h>
#include <hysh/impl/default_allocator.h>

static hy_allocator default_allocator;

hyresult get_hy_default_allocator_cid(void *self, hy_cid *retval) {
    return hy_default_allocator_cid;
}

hyresult hy_default_allocate(void *self, size_t size, void **retval) {
    *retval = malloc(size);
    return (*retval) ? HY_OK : HY_FAIL;
}

hyresult hy_default_deallocate(void *self, void *ptr) {
    free(ptr);
    return HY_OK;
}

hyresult hy_default_allocator_query_interface(void *self, hy_iid iid, hy_object **retval) {
    if(iid == hy_allocator_iid) {
        *retval = (hy_object*) &default_allocator;
        return HY_OK;
    } else {
        *retval = NULL;
        return HY_FAIL;
    }
}

static hy_allocator default_allocator = {
    { // hy_deallocator
        { // hy_object
            &default_allocator,
            hy_default_allocator_query_interface
        },
        hy_default_deallocate
    },
    hy_default_allocate
};

hyresult hy_default_allocator(hy_allocator **retval) {
    *retval = &default_allocator;
    return HY_OK;
}