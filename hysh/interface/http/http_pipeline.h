
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
    
    hyresult (*add_prefilter)(void *self,
            hy_http_pre_filter_handler *pre_filter);
    
    hyresult (*add_pipeline_node)(void *self,
            hy_http_pipeline_node *pipeline_node);
            
    hyresult (*add_post_filter)(void *self,
            hy_http_post_filter_handler *post_filter);
            
    hyresult (*freeze_pipeline)(void *self,
            hy_http_pipeline_node **retval);
} hy_http_pipeline_builder;

typedef struct hy_http_request_to_pipeline_node_converter {
    hy_object parent;
    
    hyresult (*http_request_to_pipeline_node)(void *self,
            hy_http_request_line *request_line,
            hy_http_headers *request_headers,
            hy_http_pipeline_node **retval);
    
} hy_http_pipeline_node_converter;

typedef struct hy_http_pipeline_node_to_filter_converter {
    hy_object parent;
    
    hyresult (*http_pipeline_node_to_pre_filter)(void *self,
            hy_http_pipeline_node *node,
            hy_http_pre_filter **retval);
    
    hyresult (*http_pipeline_node_to_pre_filter)(void *self,
            hy_http_pipeline_node *node,
            hy_http_pre_filter **retval);
    
} hy_http_pipeline_node_to_filter_converter;