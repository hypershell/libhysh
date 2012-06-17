
#pragma once

extern "C" {
#include <hysh/interface/data_buffer_factory.h>
}

#include <hysh/wrapper/Object.hpp>

namespace hysh {

class DataBufferBuilderPtr :
    public DestructableObjectPtr
{
  public:
    static const hy_iid InterfaceId = hy_data_buffer_builder_iid;
    
    DataBufferBuilderPtr() :
        DestructableObjectPtr(0, 0)
    { }
    
    DataBufferBuilderPtr(hy_data_buffer_builder *ptr, hy_destructor destructor) :
        DestructableObjectPtr(&ptr->parent, destructor)
    { }
    
    hyresult EditBuffer(char **retval) {
        return Ptr()->edit_buffer(Self(), retval);
    }
    
    hyresult EditableSize(uint64_t *retval) {
        return Ptr()->editable_size(Self(), retval);
    }
    
    hyresult FreezeBuffer(uint64_t size, hy_data_buffer **retval) {
        return Ptr()->freeze_buffer(Self(), size, retval);
    }
    
    hy_data_buffer_builder* Ptr() {
        return (hy_data_buffer_builder*) DestructableObjectPtr::Ptr();
    }
    
    hy_data_buffer_builder** EditPtr() {
        return (hy_data_buffer_builder**) DestructableObjectPtr::EditPtr();
    }
    
    operator hy_data_buffer_builder*() {
        return Ptr();
    }
};

class DataBufferFactoryPtr :
    public ObjectPtr
{
  public:
    static const hy_iid InterfaceId = hy_data_buffer_factory_iid;
      
    DataBufferFactoryPtr() :
        ObjectPtr(0)
    { }
    
    DataBufferFactoryPtr(hy_data_buffer_factory *ptr) :
        ObjectPtr(&ptr->parent)
    { }
    
    hyresult NewDataBuffer(uint64_t size, hy_data_buffer_builder **retval, hy_destructor *ret_destructor) {
        return Ptr()->new_data_buffer(Self(), size, retval, ret_destructor);
    }
    
    hy_data_buffer_factory* Ptr() {
        return (hy_data_buffer_factory*) ObjectPtr::Ptr();
    }
    
    hy_data_buffer_factory** EditPtr() {
        return (hy_data_buffer_factory**) ObjectPtr::EditPtr();
    }
    
    operator hy_data_buffer_factory*() {
        return Ptr();
    }
};

}