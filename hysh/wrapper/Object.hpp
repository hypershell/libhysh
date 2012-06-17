
#pragma once

extern "C" {
#include <hysh/interface/object.h>
}

#define NULL_GUARD \
        if(IsNull()) { return HY_NULL_PTR; }

namespace hysh {

class ObjectPtr
{
  public:
    static const hy_iid InterfaceId = hy_object_iid;
    
    ObjectPtr() :
        mPtr(0)
    { }
    
    ObjectPtr(hy_object *ptr) :
        mPtr(ptr)
    { }
    
    template <typename Interface>
    hyresult QueryInterface(Interface **retval) {
        NULL_GUARD;
        
        hy_object *newobj;
        hy_iid iid = Interface::InterfaceID;
        
        hyresult res = Ptr()->query_interface(Self(), iid, &newobj);
        
        *retval = static_cast<Interface*>(newobj);
        return res;
    }
    
    hyresult ClassId(hy_cid *retval) {        
        NULL_GUARD;
        
        return Ptr()->class_id(Self(), retval);
    }
    
    void* Self() {
        return Ptr()->self;
    }
    
    hy_object* Ptr() {
        return mPtr;
    }
    
    hy_object** EditPtr() {
        return &mPtr;
    }
    
    bool IsNull() {
        return mPtr == 0;
    }
    
    operator hy_object*() {
        return Ptr();
    }
    
    operator bool() {
        return !IsNull();
    }
    
  private:
    hy_object *mPtr;
};

class RefcountedObjectPtr :
    public ObjectPtr
{
  public:
    static const hy_iid InterfaceId = hy_refcounted_object_iid;
    
    RefcountedObjectPtr() :
        ObjectPtr(0)
    { }
    
    RefcountedObjectPtr(hy_refcounted_object *ptr) :
        ObjectPtr(&ptr->parent)
    { 
        AddRef();
    }
    
    hyresult AddRef() {
        return Ptr()->add_ref(Self());
    }
    
    hyresult DeRef() {
        return Ptr()->de_ref(Self());
    }
    
    hy_refcounted_object* Ptr() {
        return (hy_refcounted_object*) ObjectPtr::Ptr();
    }
    
    hy_refcounted_object** EditPtr() {
        return (hy_refcounted_object**) ObjectPtr::EditPtr();
    }

    operator hy_refcounted_object*() {
        return Ptr();
    }

    ~RefcountedObjectPtr() {
        DeRef();
    }
};

class DestructableObjectPtr :
    public ObjectPtr
{
  public:
    DestructableObjectPtr() :
        ObjectPtr(0), mDestructor(0)
    { }
    
    DestructableObjectPtr(hy_object *ptr, hy_destructor destructor) :
        ObjectPtr(ptr), mDestructor(destructor)
    { }
    
    hy_destructor Destructor() {
        return mDestructor;
    }
    
    hy_destructor* EditDestructor() {
        return &mDestructor;
    }
    
    ~DestructableObjectPtr() {
        if(mDestructor) {
            mDestructor(Ptr());
        }
    }
    
  private:
    hy_destructor mDestructor;
};

}