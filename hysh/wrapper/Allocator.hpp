
#pragma once

extern "C" {
#include <hysh/interface/allocator.h>
}

#include <hysh/wrapper/Object.hpp>

namespace hysh {

class DeallocatorPtr :
    public ObjectPtr
{
  public:
    static const hy_iid InterfaceId = hy_deallocator_iid;
    
    DeallocatorPtr() :
        ObjectPtr(0)
    { }
    
    DeallocatorPtr(hy_deallocator *ptr) :
        ObjectPtr(&ptr->parent)
    { }
    
    hyresult Deallocate(void *ptr) {
        return Ptr()->deallocate(Self(), ptr);
    }
    
    hy_deallocator* Ptr() {
        return (hy_deallocator*) ObjectPtr::Ptr();
    }
    
    hy_deallocator** EditPtr() {
        return (hy_deallocator**) ObjectPtr::EditPtr();
    }
    
    operator hy_deallocator*() {
        return Ptr();
    }
};

class AllocatorPtr : 
    public DeallocatorPtr
{
  public:
    static const hy_iid InterfaceId = hy_allocator_iid;
    
    AllocatorPtr() :
        DeallocatorPtr(0)
    { }
    
    AllocatorPtr(hy_allocator *ptr) :
        DeallocatorPtr(&ptr->parent)
    { }
    
    hyresult Allocate(size_t size, void **retval) {
        return Ptr()->allocate(Self(), size, retval);
    }
    
    template <typename Class>
    hyresult Allocate(Class **retval) {
        return Allocate(sizeof(Class), (void**) retval);
    }
    
    hy_allocator* Ptr() {
        return (hy_allocator*) DeallocatorPtr::Ptr();
    }
    
    hy_allocator** EditPtr() {
        return (hy_allocator**) DeallocatorPtr::EditPtr();
    }
    
    operator hy_allocator*() {
        return Ptr();
    }
};

}