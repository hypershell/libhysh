
#include <hysh/interface/data_buffer.h>

static const hy_iid hy_string_iid = 0x99cfa56585f87bde;

typedef struct hy_string {
    hy_data_buffer parent;
    
    hyresult (*str)(void *self, const char **retval);
    
    hyresult (*str_len)(void *self, size_t *retval);
} hy_string;