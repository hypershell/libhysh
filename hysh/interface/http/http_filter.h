
#pragma once

typedef struct hy_http_post_filter_handler_callback {
    hy_unique_object parent;
    
    hyresult (*on_not_modified)(void *self);
    
    hyresult (*on_filter_error)(void *self, hyresult err);
    
    hyresult (*on_filtered_response_available)(void *self,
            hy_http_client_response_reader *response);
    
} hy_http_post_filter_handler_callback;

typedef struct hy_http_pre_filter_handler_callback {
    hy_http_post_filter_handler_callback parent;

    hyresult (*on_filtered_request_available)(void *self,
            hy_http_server_request_reader *request);

} hy_http_pre_filter_handler_callback;

typedef struct hy_http_pre_filter_handler {
    hy_unique_object parent;
    
    hyresult (*filter_http_request)(void *self,
            hy_http_server_request_reader *request);
    
} hy_http_pre_filter_handler;

typedef struct hy_http_post_filter_handler {
    hy_unique_object parent;
    
    hyresult (*filter_http_response)(void *self,
            hy_http_client_response_reader *response);
    
} hy_http_post_filter_handler;

typedef struct hy_http_pre_filter_handler_factory {
    hy_object parent;
    
    hyresult (*create_pre_filter)(void *self,
            hy_http_request_line *filter_request_line,
            hy_http_headers *filter_request_headers,
            hy_http_pre_filter_handler **retval);
    
} hy_http_pre_filter_handler_factory;

typedef struct hy_http_post_filter_handler_factory {
    hyresult (*create_post_filter)(void *self,
            hy_http_request_line *filter_request_line,
            hy_http_headers *filter_request_header,
            hy_http_post_filter_handler **retval);
    
} hy_http_post_filter_handler_factory;

typedef struct hy_http_filtered_handler_factory {
    hy_object parent;
    
    hyresult (*create_filtered_handler)(void *self,
            hy_http_pre_filter_handler *pre_filter,
            hy_http_handler *handler,
            hy_http_post_filter_handler *post_filter,
            hy_http_handler **ret_filtered_handler);
    
} hy_http_filtered_handler_factory;