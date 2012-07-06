
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
            hy_http_headers *headers,
            hy_read_stream *chunked_body,
            hy_destructor body_destructor,
            
            hy_http_headers **ret_headers,
            hy_chunked_body_reader **ret_parsed_body,
            hy_destructor *ret_destructor);
    
} hy_http_chunked_request_converter;

typedef struct hy_http_chunked_body_writer {
    hy_write_stream parent;
    
    hyresult (*write_chunk_extension)(void *self, hy_http_header *header);
    
    hyresult (*write_trailer)(void *self, hy_http_header *header);

} hy_http_chunked_body_writer;

typedef struct hy_http_chunked_body_writer_converter {
    hy_object parent;
    
    hyresult (*convert_body)(void *self,
            hy_http_headers *headers,
            hy_write_stream *raw_write_stream,
            hy_destructor write_destructor,
            
            hy_http_headers **ret_headers,
            hy_http_chunked_body_writer **ret_writer,
            hy_destructor *ret_destructor);
};