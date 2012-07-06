
#pragma once

#include <hysh/interface/http_channel.h>

typedef struct hy_http_channel_factory {
    hy_object parent;
    
    hyresult (*create_http_response_channel)(void *self,
            hy_http_server_response_writer **ret_writer,
            hy_destructor *ret_writer_destructor,
            hy_http_client_response_reader **ret_reader,
            hy_destructor *ret_reader_destructor);
            
    hyresult (*create_http_request_channel)(void *self,
            hy_http_client_request_writer **ret_writer,
            hy_destructor *ret_writer_destructor,
            hy_http_server_request_reader **ret_reader,
            hy_destructor *ret_reader_destructor);
};

typedef struct hy_http_subrequest_service {
    
};