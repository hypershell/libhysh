
#pragma once

#include <hysh/interface/http_channel.h>

static const hy_iid hy_http_handler_iid =           0xdf8b4636e53f5c7c;
static const hy_iid hy_http_handler_callback_iid =  0xca58912430b43c4d;
static const hy_iid hy_http_handler_factory =       0x1fa0bf6a3849f6ab;

static const hy_sid hy_http_subrequest_handler_factory_sid = 0xe8d4b11b7fca8bd4;

typedef struct hy_http_handler_callback {
    hy_object parent;
    
    hyresult (*on_http_response_reader_available)(void *self,
            hy_http_client_response_reader *response);
    
} hy_http_handler_callback;

typedef struct hy_http_handler {
    hy_unique_object parent;
    
    hyresult (*handle_http_request)(void *self,
            hy_http_server_request_reader *request,
            hy_http_handler_callback *callback);
            
} hy_http_handler;

typedef struct hy_http_handler_factory {
    hy_object parent;
    
    hyresult (*create_http_handler)(void *self, 
            hy_http_handler **ret_handler);
    
} hy_http_handler_factory;