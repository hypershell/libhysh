
#pragma once

typedef struct hy_http_subrequest_callback {
    hy_object parent;
    
    hyresult (*on_response_available)(void *self,
            hy_http_response_line *response_line,
            hy_http_headers *response_headers,
            hy_read_stream *response_body,
            hy_destructor body_destructor);
    
} hy_http_subrequest_callback;

typedef struct hy_http_subrequest_service {
    hy_object parent;
    
    hyresult (*create_subrequest)(void *self,
            hy_http_request_line *request_line,
            hy_http_headers *request_headers,
            hy_read_stream *request_body,
            hy_http_subrequest_callback *callback);
    
} hy_http_subrequest_service;