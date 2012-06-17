
#pragma once

#include <hysh/wrapper/Allocator.hpp>

namespace hysh {

template <typename Parent>
class DestructorImpl
{
  public:
    DestructorImpl() :
        mUninitialized(false)
    { }
    
    hyresult SetAllocator(AllocatorPtr alloc) {
        mAlloc = alloc;
        
        return HY_OK;
    }
    
    hyresult GetAllocator(hy_allocator **retval) {
        *retval = mAlloc;
        
        return HY_OK;
    }
    
    hyresult Destruct() {
        hyresult res = HY_OK;
        AllocatorPtr alloc = mAlloc;
        Parent *self = static_cast<Parent*>(this);
        
        res = self->Uninit();
        mUninitialized = true;
        
        self->~Parent();
        
        if(alloc) {
            res = alloc.Deallocate(self);
        }
        
        return res;
    }
    
    ~DestructorImpl() {
        if(!mUninitialized) {
            static_cast<Parent*>(this)->Uninit();
        }
    }
    
  private:
    bool mUninitialized;
    AllocatorPtr mAlloc;
};

}