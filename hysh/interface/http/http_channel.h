
#pragma once

#include <hysh/interface/stream.h>

static const hy_iid hy_http_reader_callback_iid =                   0x6214102b6ce550c8;
static const hy_iid hy_http_server_request_reader_callback_iid =    0x9733c12acf2b88f8;
static const hy_iid hy_http_client_response_reader_callback_iid =   0x1caccd00c2748d57;
static const hy_iid hy_http_server_request_reader_iid =     0x6e57ef0d8699cdc1;
static const hy_iid hy_http_client_response_reader_iid =    0x9bcda9cae12a377f;
static const hy_iid hy_http_writer_iid =                    0x8ae2be701c938ee9;
static const hy_iid hy_http_client_request_writer_iid =     0xe9c80dda9ffd5958;
static const hy_iid hy_http_server_response_writer_iid =    0xe7a101576a0bf5dc;
static const hy_iid hy_http_channel_factory_iid =           0xeccb8b4bf80abec4;

typedef struct hy_http_reader_callback {
    hy_unique_object parent;
    
    hyresult (*on_headers_available)(void *self,
            hy_http_headers *headers);
    
    hyresult (*on_read_stream_available)(void *self,
            hy_read_stream *body,
            hy_destructor body_destructor);

} hy_http_reader_callback;

typedef struct hy_http_server_request_reader_callback {
    hy_http_reader_callback parent;
    
    hyresult (*on_http_request_available)(void *self,
            hy_http_request_line *request_line,
            hy_http_headers *request_headers,
            hy_read_stream *request_body);

} hy_http_server_request_reader_callback;

typedef struct hy_http_client_response_reader_callback {
    hy_http_reader_callback parent;
    
    hyresult (*on_http_response_available)(void *self,
            hy_http_response_line *response_line,
            hy_http_headers *response_headers,
            hy_read_stream *response_body);
            
} hy_http_client_response_reader_callback;

typedef struct hy_http_server_request_reader {
    hy_unique_object parent;
    
    hyresult (*read_request_channel)(void *self,
            hy_http_server_request_reader_callback *callback);

} hy_http_server_request_reader;

typedef struct hy_http_client_response_reader {
    hy_unique_object parent;
    
    hyresult (*read_response_channel)(void *self,
            hy_http_client_response_reader_callback *callback);
    
} hy_http_client_response_reader;

typedef struct hy_http_writer {
    hy_unique_object parent;
    
    hyresult (*write_headers)(void *self, hy_http_headers *headers);
    
    hyresult (*write_body)(void *self, 
            hy_http_read_stream *body);
    
} hy_http_writer;

typedef struct hy_http_client_request_writer {
    hy_http_writer parent;

    hyresult (*write_http_request)(void *self,
            hy_http_request_line *request_line,
            hy_http_headers *request_headers,
            hy_read_stream *request_body);

} hy_http_client_request_writer;

typedef struct hy_http_server_response_writer {
    hy_http_writer parent;
    
    hyresult (*write_http_response)(void *self,
            hy_http_response_line *response_line,
            hy_http_headers *response_headers,
            hy_read_stream *response_body);
    
} hy_http_server_response_writer;

typedef struct hy_http_channel_factory {
    hy_object parent;
    
    hyresult (*create_http_request_channel)(void *self,
            hy_http_client_request_writer *writer,
            hy_http_server_request_reader *reader);
    
    hyresult (*create_http_response_channel)(void *self,
            hy_http_server_response_writer *writer,
            hy_http_client_response_reader *reader);
    
} hy_http_channel_factory;