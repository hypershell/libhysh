
#pragma once

extern "C" {
#include <hysh/interface/object.h>
}

namespace hysh {

template<typename Parent>
class ObjectImpl {
  public:
    static void Init(Parent *self, hy_object *obj) {
        obj->self = (void*) self;
        obj->query_interface = QueryInterface;
        obj->class_id = ClassId;
    }
    
    static hyresult QueryInterface(void *self, hy_iid interface, hy_object **retval) {
        return static_cast<Parent*>(self)->QueryInterface(interface, retval);
    }
    
    static hyresult ClassId(void *self, hy_cid *retval) {
        *retval = Parent::ClassId;
        return HY_OK;
    }
};

template <typename Parent>
class RefcountedObjectImpl {
  public:
    static void Init(Parent *self, hy_refcounted_object *obj) {
        ObjectImpl<Parent>::Init(self, &obj->parent);
        
        obj->add_ref = AddRef;
        obj->de_ref = DeRef;
    }
    
    static hyresult AddRef(void *self) {
        return static_cast<Parent*>(self)->AddRef();
    }
    
    static hyresult DeRef(void *self) {
        return static_cast<Parent*>(self)->DeRef();
    }
};

}