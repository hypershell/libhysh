
#pragma once

typedef struct hy_module {
    hy_object parent;
    
    hyresult (*module_name)(void *self, hy_string **ret_name);
    
    hyresult (*dependencies)(void *self, );
} hy_module;