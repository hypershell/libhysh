
#include <hysh/interface/data_buffer.h>
#include <hysh/interface/string.h>

static const hy_iid hy_unicode_string_iid           = 0x119be7e9557e9819;
static const hy_iid hy_unicode_string_iterator_iid  = 0x646a0b42eec803b6;

typedef struct hy_unicode_string_iterator {
    hy_refcounted_object parent;
    
    hyresult (*current_codepoint)(void *self, char32_t *retval);
    
    hyresult (*next)(void *self);
    
    hyresult (*has_next)(void *self, bool *retval);
    
} hy_unicode_string_iterator;

typedef struct hy_unicode_string {
    hy_data_buffer parent;
    
    hyresult (*unicode_encoding)(void *self, hy_string **retval);
    
} hy_unicode_string;

typedef struct hy_utf8_string {
    hy_unicode_string parent;
    
    hyresult (*raw_size)(void *self, size_t *retval);
    
    hyresult (*utf8_string)(void *self, const char **retval);
    
} hy_utf8_string;

typedef struct hy_utf16_string {
    hy_unicode_string parent;
    
    hyresult (*raw_size)(void *self, size_t *retval);
    
    hyresult (*utf16_string)(void *self, const char16_t **retval);

} hy_utf16_string;

typedef struct hy_utf32_string {
    hy_unicode_string parent;
    
    hyresult (*raw_size)(void *self, size_t *retval);
    
    hyresult (*utf32_string)(void *self, const char32_t **retval);
    
} hy_utf32_string;

typedef struct hy_unicode_codepoint_comparator {
    hy_object parent;
    
    hyresult (*has_same_codepoint)(void *self, 
            hy_unicode_string *string1,
            hy_unicode_string *string2,
            bool *retval);
    
    hyresult (*less_than_codepoint)(void *self,
            hy_unicode_string *string1,
            hy_unicode_string *string2,
            bool *retval);
    
} hy_unicode_codepoint_comparator;