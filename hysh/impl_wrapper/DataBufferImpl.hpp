
#pragma once

extern "C" {
#include <hysh/interface/data_buffer.h>
}

#include <hysh/impl_wrapper/ObjectImpl.hpp>

namespace hysh {

template <typename Parent>
class DataBufferImpl {
  public:
    static void Init(Parent *self, hy_data_buffer *obj) {
        RefcountedObjectImpl<Parent>::Init(self, &obj->parent);
        
        obj->size = Size;
        obj->buffer = Buffer;
    }
    
    static hyresult Size(void *self, uint64_t *retval) {
        return static_cast<Parent*>(self)->Size(retval);
    }

    static hyresult Buffer(void *self, const char **retval) {
        return static_cast<Parent*>(self)->Buffer(retval);
    }
};

}