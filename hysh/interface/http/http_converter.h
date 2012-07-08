
#pragma once

#include "hysh/interface/http/http_handler.h"

typedef struct hy_http_body_converter {
    hy_object parent;
    
    hyresult (*convert_http_body)(void *self,
            hy_http_headers *headers,
            hy_read_stream *original_stream,
            hy_http_headers **ret_converted_headers,
            hy_read_stream **ret_converted_stream);
    
} hy_http_body_converter;

typedef struct hy_http_to_stream_converter {
    hy_object parent;
    
    hyresult (*http_request_to_read_stream)(void *self,
        hy_http_server_request_reader *request,
        hy_read_stream **ret_read_stream);
        
    hyresult (*http_response_to_read_stream)(void *self,
        hy_http_client_response_reader *response,
        hy_read_stream **ret_read_stream);
} hy_http_to_stream_converter;

typedef struct hy_stream_to_http_request_callback {
    hy_object parent;
    
    hyresult (*on_request_conversion_available)(void *self,
            hy_http_server_request_reader *request);
    
    hyresult (*on_request_conversion_error)(void *self,
            hy_read_stream *raw_stream);
    
} hy_stream_to_http_request_callback;

typedef struct hy_stream_to_http_response_callback {
    hy_object parent;
    
    hyresult (*on_response_conversion_available)(void *self,
            hy_http_client_response_reader *response);
    
    hyresult (*on_response_conversion_error)(void *self,
            hy_read_stream *raw_stream);
} hy_stream_to_http_request_callback;

typedef struct hy_stream_to_http_converter {
    hy_object parent;
    
    hyresult (*read_stream_to_http_request)(void *self,
            hy_read_stream *raw_stream,
            hy_stream_to_http_request_callback *callback);
            
    hyresult (*read_stream_to_http_response)(void *self,
            hy_read_stream *raw_stream,
            hy_stream_to_http_response_callback *callback);
    
} hy_http_to_stream_converter;