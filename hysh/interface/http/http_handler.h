
#pragma once

#include <hysh/interface/http_channel.h>

typedef struct hy_http_response_writer {
    hy_object parent;
    
    hyresult (*write_response)(void *self,
            hy_http_client_response_reader *response);
    
} hy_http_response_writer;

typedef struct hy_http_handler {
    hy_unique_object parent;
    
    hyresult (*handle_http_request)(void *self,
            hy_http_server_request_reader *request,
            hy_http_response_writer *writer);
            
} hy_http_handler;

typedef struct hy_http_handler_factory {
    hy_object parent;
    
    hyresult (*new_http_handler)(void *self, 
            hy_http_handler **ret_handler);
            
} hy_http_handler_factory;