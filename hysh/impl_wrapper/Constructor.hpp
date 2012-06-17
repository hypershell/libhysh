
#pragma once

#include <hysh/wrapper/Allocator.hpp>

namespace hysh {

template <typename Class>
hyresult Construct(AllocatorPtr alloc, Class **retval) {
    hyresult res;
    Class *ptr;
    *retval = 0;
    
    res = alloc.Allocate<Class>(&ptr);
    RETURN_IF_FAIL(res);
    
    ptr = new(ptr) Class();
    if(!ptr) {
        return HY_CONSTRUCTOR_ERROR;
    }
    
    res = ptr->SetAllocator(alloc);
    RETURN_IF_FAIL(res);
    
    *retval = ptr;
    return HY_OK;
}

}