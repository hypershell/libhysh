
#pragma once

typedef struct hy_http_post_filter_handler_callback {
    hy_object parent;
    
    hyresult (*on_not_modified)(void *self);
            
    hyresult (*on_filtered_response_available)(void *self,
            hy_http_client_response_reader *response);
    
} hy_http_post_filter_handler_callback;

typedef struct hy_http_pre_filter_handler_callback {
    hy_http_post_filter_handler_callback parent;

    hyresult (*on_filtered_request)(void *self,
            hy_http_server_request_reader *request);

} hy_http_pre_filter_handler_callback;

typedef struct hy_http_pre_filter_handler {
    hy_object parent;
    
    hyresult (*filter_http_request)(void *self,
            hy_http_server_request_reader *request);
    
} hy_http_pre_filter_handler;

typedef struct hy_http_post_filter_handler {
    hy_object parent;
    
    hyresult (*filter_http_response)(void *self,
            hy_http_client_response_reader *response);
    
} hy_http_post_filter_handler;