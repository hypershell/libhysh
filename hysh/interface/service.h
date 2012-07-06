
#pragma once

typedef struct hy_service_retrieval {
    hy_object parent;
    
    hyresult (*retrieve_server)(void *self,
            hy_sid service_id,
            hy_object **ret_service,
            hy_iid *ret_iid);
} hy_service_retrieval;

typedef struct hy_service_registrar {
    hy_object parent;
    
    hyresult (*register_service)(void *self,
            hy_sid service_id,
            hy_iid interface_id,
            hy_object *service,
            hy_destructor service_destructor);
};