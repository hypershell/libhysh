
#pragma once

#include <hysh/interface/http_channel.h>

typedef struct hy_http_response_writer {
    hy_object parent;
    
    hyresult (*write_response)(void *self, 
            hy_http_response_line *response_line,
            hy_http_header *response_header,
            hy_read_stream *response_body,
            hy_destructor body_destructor);
    
} hy_http_response_writer;

typedef struct hy_http_handler {
    hy_object parent;
    
    hyresult (*handle_http_request)(void *self,
            hy_http_request_line *request_line,
            hy_http_headers *request_headers,
            
            hy_read_stream *request_body,
            hy_destructor request_body_destructor,
            hy_http_response_writer *writer);
            
} hy_http_handler;

typedef struct hy_http_handler_factory {
    hy_object parent;
    
    hyresult (*new_http_handler)(void *self, 
            hy_http_handler **ret_handler,
            hy_destructor *ret_destructor);
            
} hy_http_handler_factory;