
#pragma once

extern "C" {
#include <hysh/interface/data_buffer.h>
}

#include <hysh/wrapper/Object.hpp>

namespace hysh {

class DataBufferPtr :
    public RefcountedObjectPtr
{
  public:
    static const hy_iid InterfaceId = hy_data_buffer_iid;
    
    DataBufferPtr() :
        RefcountedObjectPtr(0)
    { }
    
    DataBufferPtr(hy_data_buffer *ptr) :
        RefcountedObjectPtr(&ptr->parent)
    { }
    
    hyresult Size(uint64_t *retval) {
        return Ptr()->size(Self(), retval);
    }
    
    hyresult Buffer(const char **retval) {
        return Ptr()->buffer(Self(), retval);
    }
    
    hy_data_buffer* Ptr() {
        return (hy_data_buffer*) RefcountedObjectPtr::Ptr();
    }
    
    hy_data_buffer** EditPtr() {
        return (hy_data_buffer**) RefcountedObjectPtr::EditPtr();
    }
    
    operator hy_data_buffer*() {
        return Ptr();
    }
};

}