
#pragma once

typedef struct hy_http_subrequest_callback {
    hy_object parent;
    
    hyresult (*on_response_available)(void *self,
            hy_http_client_response_reader *response);
    
} hy_http_subrequest_callback;

typedef struct hy_http_subrequest_service {
    hy_object parent;
    
    hyresult (*create_subrequest)(void *self,
            hy_http_server_request_reader *request,
            hy_http_subrequest_callback *callback);
    
} hy_http_subrequest_service;