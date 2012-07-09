
#include <hysh/interface/data_buffer.h>

typedef struct hy_read_stream_callback {
    hy_unique_object parent;
    
    hyresult (*on_read)(void *self, hy_data_buffer *buffer);
    
    hyresult (*on_write_closed)(void *self, hyresult result);

} hy_read_stream_callback;

typedef struct hy_read_stream {
    hy_unique_object parent;
    
    hyresult (*read)(void *self, 
            hy_read_stream_callback *callback);

    hyresult (*is_closed)(void *self, bool *retval);

    hyresult (*close_read)(void *self, hyresult result);
    
} hy_read_stream;

typedef struct hy_stream_writer_callback {
    hy_unique_object parent;
    
    hyresult (*on_next_write_ready)(void *self);
    
    hyresult (*on_read_closed)(void *self, hyresult res);

} hy_stream_writer_callback;

typedef struct hy_stream_writer {
    hy_unique_object parent;
    
    hyresult (*write)(void *self, hy_data_buffer *buffer,
            hy_stream_writer_callback *callback);
    
    hyresult (*close_write)(void *self, hyresult res);

} hy_stream_writer;

typedef struct hy_write_stream_callback {
    hy_unique_object parent;
    
    hyresult (*on_ready_write)(void *self, 
            hy_stream_writer *writer);
            
    hyresult (*on_read_closed)(void *self, hyresult res);
    
} hy_write_stream_callback;

typedef struct hy_write_stream {
    hy_unique_object parent;
    
    hyresult (*start_write)(void *self, hy_write_stream_callback *callback);
} hy_write_stream;

typedef struct hy_stream_factory {
    hy_object parent;
    
    hyresult (*create_io_stream)(void *self,
            hy_write_stream **ret_write_stream,
            hy_read_stream  **ret_read_stream);

} hy_stream_factory;