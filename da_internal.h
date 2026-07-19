#ifndef DYNAMIC_ARRAYS_H_
#define DYNAMIC_ARRAYS_H_

#include <stddef.h>

typedef struct {
        size_t capacity;
        size_t count;
        size_t item_size;
} da_header_t;

typedef struct {
        void *data;
} da_t;

void *da_init(size_t item_size, size_t capacity);
da_t *da_free(void *da);
#define da_append(da, val)

#endif // !DYNAMIC_ARRAYS_H_
