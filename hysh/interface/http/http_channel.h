
#pragma once

#include <hysh/interface/stream.h>

typedef struct hy_http_reader_callback {
    hy_object parent;
    
    hyresult (*on_malformed_http)(void *self, hyresult err,
            hy_read_stream *raw_stream,
            hy_destructor raw_stream_destructor);
    
    hyresult (*on_headers_available)(void *self,
            hy_http_headers **ret_response_headers);
    
    hyresult (*on_read_stream_available)(void *self,
            hy_read_stream **ret_body);

} hy_http_reader_callback;

typedef struct hy_http_server_request_reader_callback {
    hy_http_reader_callback parent;
    
    hyresult (*on_request_line_available)(void *self,
            hy_http_request_line **ret_request_line);

} hy_http_server_request_reader_callback;

typedef struct hy_http_client_response_reader_callback {
    hy_http_reader_callback parent;
    
    hyresult (*on_response_line_available)(void *self,
            hy_http_response_line **ret_response_line);
            
} hy_http_client_response_reader_callback;

typedef struct hy_http_server_request_reader {
    hy_object parent;
    
    hyresult (*read_request_channel)(void *self,
            hy_http_server_request_reader_callback *callback);

} hy_http_server_request_channel;

typedef struct hy_http_client_response_reader {
    hy_object parent;
    
    hyresult (*read_response_channel)(void *self,
            hy_http_client_response_reader_callback *callback);
};

typedef struct hy_http_writer {
    hy_object parent;
    
    hyresult (*write_headers)(void *self, hy_http_headers *headers);
    
    hyresult (*write_body)(void *self, hy_http_read_stream *stream);
};

typedef struct hy_http_server_response_writer {
    hy_http_writer parent;
    
    hyresult (*write_response_line)(void *self, hy_http_response_line *response_line);
} hy_http_server_response_writer;

typedef struct hy_http_client_request_writer {
    hy_http_writer parent;
    
    hyresult (*write_request_line)(void *self, hy_http_request_line *request_line);
} hy_http_client_request_writer;