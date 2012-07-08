
#pragma once

typedef struct http_line {
    hy_refcounted_object parent;
    
    hyresult (*to_string)(void *self, hy_string **retval);
    
    hyresult (*major_version)(void *self, uint32_t *retval);
    
    hyresult (*minor_version)(void *self, uint32_t *retval);
    
} http_line;

typedef struct hy_http_request_line {
    hy_http_line parent;
    
    hyresult (*request_method)(void *self, hy_string **retval);
    
    hyresult (*request_path)(void *self, hy_string **retval);
    
} hy_http_request_line;

typedef struct hy_http_response_line {
    hy_http_line parent;
    
    hyresult (*status_code)(void *self, uint32_t *retval);
    
    hyresult (*status_message)(void *self, hy_string **retval);
    
} hy_http_response_line;

typedef struct hy_http_header {
    hy_refcounted_object parent;
    
    hyresult (*field_name)(void *self, hy_string **retval);
    
    hyresult (*field_value)(void *self, hy_string **retval);
    
} hy_http_header;

typedef struct hy_http_headers {
    hy_refcounted_object parent;
    
    hyresult (*to_list)(void *self, hy_list **retval);
    
    hyresult (*get_header)(void *self, 
            hy_string *name, hy_http_header **retval);
    
} hy_http_headers;