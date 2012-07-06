
#pragma once

#include <hysh/interface/object.h>

typedef struct hy_tracer {
    hy_object parent;
    
    hyresult (*log)(void *self, uint32_t log_level,
                    hyresult res, const char *message,
                    const char *filename, uint32_t line_num,
                    hyresult *ret_tagged_result);
                    
    hyresult (*tag_result)(void *self, hyresult raw_result, 
                    hyresult *ret_tagged_result);
                    
    hyresult (*link_results)(void *self, hyresult old_result,
                    hyresult new_result, 
                    hyresult *ret_tagged_result);
};