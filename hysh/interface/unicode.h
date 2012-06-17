
#include <hysh/interface/data_buffer.h>
#include <hysh/interface/string.h>

static const hy_iid hy_unicode_string_iid           = 0x119be7e9557e9819;
static const hy_iid hy_unicode_string_iterator_iid  = 0x646a0b42eec803b6;

typedef struct hy_unicode_string_iterator {
    hy_refcounted_object parent;
    
    hyresult (*to_unicode_string)(void *self, hy_unicode_string **retval);
    
    hyresult (*current)(void *self, char32_t *retval);
    
    hyresult (*next)(void *self);
    
    hyresult (*has_next)(void *self, bool *retval);
};

typedef struct hy_unicode_string {
    hy_data_buffer parent;
    
    hyresult (*encoding)(void *self, hy_string **retval);
} hy_unicode_string;