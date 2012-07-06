
#pragma once

typedef struct hy_unique_list {
    hy_object parent;
    
    hyresult (*element_type)(void *self, hy_iid *retval);
    
    hyresult (*pop_next)(void *self, 
        hy_object **ret_object,
        hy_destructor *ret_destructor,
        hy_iid *ret_iid);
        
    hyresult (*has_next)(void *self, bool *retval);
};

typedef struct hy_list {
    hy_ref_counted_object parent;
    
    hyresult (*element_type)(void *self, hy_iid *retval);
    
    hyresult (*next)(void *self, hy_list **retval);
    
    hyresult (*has_next)(void *self, bool *retval);
    
    hyresult (*value)(void *self, 
            hy_object **retval,
            hy_iid *ret_iid);
} hy_list;

typedef struct hy_refcounted_list_builder {
    hy_object parent;
    
    hyresult (*append_end)(void *self, 
        hy_refcounted_object *value, 
        hy_iid iid);
    
    hyresult (*freeze_list)(void *self, hy_list **retval);
} hy_refcounted_list_builder;

typedef struct hy_non_refcounted_list_builder {
    hy_object parent;
    
    hyresult (*append_end)(void *self, hy_object *value);
    
    hyresult (*freeze_list)(void *self, hy_list **retval);
} hy_refcounted_list_builder;

typedef struct hy_list_factory {
    
};