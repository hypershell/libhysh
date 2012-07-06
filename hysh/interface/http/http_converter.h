
#pragma once

#include "hysh/interface/http/http_handler.h"

typedef struct hy_http_body_converter {
    hy_object parent;
    
    hyresult (*convert_http_body)(void *self,
            hy_http_headers *headers,
            hy_read_stream *original_stream,
            hy_destructor *stream_destructor,
            
            hy_http_headers **ret_converted_headers,
            hy_read_stream **ret_stream,
            hy_destructor *ret_stream_destructor);
} hy_http_body_converter;