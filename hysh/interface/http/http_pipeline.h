
#pragma once

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

typedef struct hy_http_handler_to_pipeline_node_converter {
    hy_object parent;
    
    hyresult (*create_pipeline_node_from_handler)(void *self,
            hy_http_handler *request_handler,
            hy_http_request_line *request_line,
            hy_http_headers *request_headers,
            hy_http_pipeline_node **retval);
    
} hy_http_handler_to_pipeline_node_converter;

typedef struct hy_http_pipeline_node_to_handler_converter {
    hy_object parent;

    hyresult (*http_pipeline_node_to_handler)(void *self,
            hy_http_pipeline_node *node,
            hy_http_handler **ret_handler);
    
    hyresult (*http_pipeline_node_to_pre_filter)(void *self,
            hy_http_pipeline_node *node,
            hy_http_pre_filter_handler **retval);
    
    hyresult (*http_pipeline_node_to_post_filter)(void *self,
            hy_http_pipeline_node *node,
            hy_http_post_filter_handler **retval);
    
} hy_http_pipeline_node_to_filter_converter;