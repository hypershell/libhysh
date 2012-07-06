
#pragma once

extern "C" {
#include <hysh/interface/data_buffer.h>
}

#include <hysh/impl_wrapper/ObjectImpl.hpp>

namespace hysh {

template <typename Impl>
class DataBufferImpl : 
    public hy_data_buffer
{
  public:
    DataBufferImpl()
    {
        InitMethodTable(static_cast<Impl*>(this), static_cast<hy_data_buffer*>(this));
    }
    
    static void InitMethodTable(Impl *self, hy_data_buffer *obj) {
        RefcountedObjectImpl<Impl>::InitMethodTable(self, &obj->parent);
        
        obj->size = Size;
        obj->buffer = Buffer;
    }
    
    static hyresult Size(void *self, uint64_t *retval) {
        return ((Impl*)self)->Size(retval);
    }

    static hyresult Buffer(void *self, const char **retval) {
        return ((Impl*)self)->Buffer(retval);
    }
};

}