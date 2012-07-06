
#pragma once

#include <hysh/interface/http_channel.h>

typedef struct hy_http_handler_listener {
    hy_object parent;
    
    hyresult (*on_http_client_response_available)(void *self,
            hy_http_client_response_reader *response,
            hy_destructor response_destructor);
            
    hyresult (*on_empty_response_available)(void *self,
            uint32_t status_code, hyresult result);
} hy_http_handler_listener;

typedef struct hy_http_handler {
    hy_object parent;
    
    hyresult (*handle_http_request)(void *self,
            hy_http_server_request_channel *request_channel,
            hy_destructor request_channel_destructor,
            hy_http_handler_listener);
            
} hy_http_handler;

typedef struct hy_http_handler_factory {
    hy_object parent;
    
    hyresult (*new_http_handler)(void *self, 
            hy_http_handler **ret_handler,
            hy_destructor *ret_destructor);
            
} hy_http_handler_factory;