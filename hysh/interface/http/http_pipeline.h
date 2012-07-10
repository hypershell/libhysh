
#pragma once

static const hy_iid hy_http_pipeline_node_iid =     0xe8d4b11b7fca8bd4;
static const hy_iid hy_http_pipeline_builder_iid =  0xf8934e683f8466f5;
static const hy_iid hy_http_pipeline_builder_factory_iid =  0xef2838fe80f1064a;
static const hy_iid hy_http_filtered_pipeline_factory_iid = 0x49244c967dd3f5c7;
static const hy_iid hy_http_handler_to_pipeline_node_converter_iid = 0xbb4f06c9e343de65;
static const hy_iid hy_http_pipeline_node_to_handler_converter_iid = 0x6214102b6ce550c8;

typedef struct hy_http_pipeline_node {
    hy_unique_object parent;
    
    hyresult (*pipe_request)(void *self,
            hy_http_header *extra_headers,
            hy_read_stream *body,
            hy_http_subrequest_callback *callback);
    
} hy_http_pipeline_node;

typedef struct hy_http_pipeline_builder {
    hy_unique_object parent;
    
    hyresult (*add_pipeline_node)(void *self,
            hy_http_pipeline_node *pipeline_node);
    
    hyresult (*freeze_pipeline)(void *self,
            hy_http_pipeline_node **retval);
    
} hy_http_pipeline_builder;

typedef struct hy_http_pipeline_builder_factory {
    hy_object parent;
    
    hyresult (*create_pipeline_builder)(void *self,
            hy_http_pipeline_builder **retval);
    
} hy_http_pipeline_builder_factory;

typedef struct hy_http_filtered_pipeline_factory {
    hy_object parent;
    
    hyresult (*create_filtered_pipeline)(void *self,
            hy_http_pre_filter_handler *pre_filter,
            hy_http_pipeline_node *pipeline_node,
            hy_http_post_filter_handler *post_filter,
            hy_http_pipeline_node **ret_filtered_node);
    
} hy_http_filtered_pipeline_factory;