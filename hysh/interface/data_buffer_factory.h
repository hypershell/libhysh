
#include <hysh/interface/data_buffer.h>

static const hy_iid hy_data_buffer_builder_iid = 0x7b61d1f5cb918b96;
static const hy_iid hy_data_buffer_factory_iid = 0x6b681a43ac6cdd8b;


typedef struct hy_data_buffer_builder {
    hy_object parent;
    
    hyresult (*edit_buffer)(void *self, char **retval);
    
    hyresult (*editable_size)(void *self, uint64_t *retval);
    
    hyresult (*freeze_buffer)(void *self, uint64_t size, hy_data_buffer **retval);
} hy_data_buffer_builder;

typedef struct hy_data_buffer_factory {
    hy_object parent;
    
    hyresult (*new_data_buffer)(void *self, uint64_t size, 
        hy_data_buffer_builder **retval, hy_destructor *ret_destructor);
} hy_data_buffer_factory;