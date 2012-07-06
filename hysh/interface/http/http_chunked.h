


typedef struct hy_http_chunked_body_callback {
    hy_read_stream_listener parent;
    
    hyresult (*on_chunk_extension_available)(void *self, hy_http_header **retval);
    
    hyresult (*on_trailer_available)(void *self, hy_http_header **retval);
    
} hy_http_chunked_body_callback;

typedef struct hy_chunked_body_reader {
    hy_read_stream parent;
    
    hyresult (*read_chunk)(void *self, 
            hy_http_chunked_body_callback *callback, 
            hy_destructor callback_destructor);
    
} hy_chunked_body_reader;

typedef struct hy_http_chunked_request_converter {
    hy_object parent;
    
    hyresult (*convert_chunked_body)(void *self,
            hy_read_stream *body,
            hy_destructory body_destructor,
            hy_chunked_body_reader **retval,
            hy_destructor *ret_destructor);
    
} hy_http_chunked_request_converter;

typedef struct hy_http_chunked_body_writer {
    hy_write_stream parent;
    
    hyresult (*write_chunk_extension)(void *self, hy_http_header *header);
    
    hyresult (*write_trailer)(void *self, hy_http_header *header);

} hy_http_chunked_body_writer;