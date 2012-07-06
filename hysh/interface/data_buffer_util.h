
#include <hysh/interface/data_buffer.h>

static const hy_iid hy_data_buffer_builder_iid = 0x7b61d1f5cb918b96;
static const hy_iid hy_data_buffer_factory_iid = 0x6b681a43ac6cdd8b;


typedef struct hy_data_buffer_builder {
    hy_object parent;
    
    hyresult (*write_byte)(void *self, char byte);
    
    hyresult (*write_bytes)(void *self, char *bytes, size_t size);
    
    hyresult (*edit_bytes)(void *self, char *bytes, size_t size, size_t offset);
    
    hyresult (*editable_size)(void *self, uint64_t *retval);
    
    hyresult (*freeze_buffer)(void *self, uint64_t size, hy_data_buffer **retval);
} hy_data_buffer_builder;

typedef struct hy_data_buffer_factory {
    hy_object parent;
    
    hyresult (*new_data_buffer_builder)(void *self, uint64_t size, 
        hy_data_buffer_builder **retval, hy_destructor *builder_destructor);
    
    hyresult (*new_static_data_buffer)(void *self, 
        const char *static_memory, 
        uint64_t size, 
        hy_data_buffer **retval);
        
    hyresult (*new_data_buffer_from_memory)(void *self,
        const char *buffer,
        uint64_t size,
        bool owning,
        hy_data_buffer **retval);
} hy_static_data_buffer_factory;

typedef struct hy_data_buffer_splicer {
    hyobject parent;
    
    hyresult (*splice_buffer)(void *self, hy_data_buffer *buffer, 
                            uint64_t offset, uint64_t size, 
                            hy_data_buffer **retval);
} hy_data_buffer_splicer;