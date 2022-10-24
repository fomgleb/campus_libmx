#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (size == 0) {
        free(ptr);
        return NULL;
    } else if (ptr == NULL) {
        return malloc(size);
    }

    void *new_ptr = malloc(size);
    mx_memcpy(new_ptr, ptr, size);
    free(ptr);
    
    return new_ptr;
}

