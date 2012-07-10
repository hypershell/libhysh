
#pragma once

#include <hysh/interface/http/http_filter_pipeline.h>

typedef struct hy_http_pre_filter_pipeline_builder {
    hy_unique_object parent;
    
    hyresult (*add_pre_filter)(void *self,
            hy_http_pre_filter_handler *pre_filter);
    
    hyresult (*freeze_pipeline)(void *self,
            hy_http_pre_filter_handler **ret_pipeline);
    
} hy_http_pre_filter_pipeline_builder;

typedef struct hy_http_post_filter_pipeline_builder {
    hy_unique_object parent;
    
    hyresult (*add_post_filter)(void *self,
            hy_http_post_filter_handler *post_filter);
    
    hyresult (*freeze_pipeline)(void *self,
            hy_http_post_filter_handler **ret_pipeline);
    
} hy_http_post_filter_pipeline_builder;

typedef struct hy_http_filter_pipeline_builder_factory {
    hy_object parent;
    
    hyresult (*create_pre_filter_pipeline_builder *self,
            hy_http_pre_filter_pipeline_builder **retval);
            
    hyresult (*create_post_filter_pipeline_builder *self,
            hy_http_post_filter_pipeline_builder **retval);
    
} hy_http_filter_pipeline_builder_factory;