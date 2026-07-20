#ifndef DYNAMIC_ARRAYS_H_
#define DYNAMIC_ARRAYS_H_

#include <stddef.h>
#include <stdlib.h>

typedef struct {
        size_t capacity;
        size_t count;
} da_header_t;

#define DA_INIT_CAPACITY 32

void da_free(void *da);

#define da_append(da, val)                                                     \
        do {                                                                   \
                if (!da) {                                                     \
                        da_header_t *new =                                     \
                            malloc(sizeof(da_header_t) +                       \
                                   DA_INIT_CAPACITY * sizeof(val));            \
                        new[0].capacity = DA_INIT_CAPACITY;                    \
                        new[0].count = 0;                                      \
                        da = (void *)(new + 1);                                \
                }                                                              \
                                                                               \
                da_header_t *hdr = (da_header_t *)da - 1;                      \
                                                                               \
                if (hdr->count >= hdr->capacity) {                             \
                        hdr->capacity *= 2;                                    \
                        hdr = realloc(hdr, sizeof(da_header_t) +               \
                                               (hdr->capacity * sizeof(val))); \
                        da = (void *)(hdr + 1);                                \
                }                                                              \
                                                                               \
                da[hdr->count++] = val;                                        \
        } while (0)

#define da_len(da) (((da_header_t *)da - 1)->count)
#define da_cap(da) (((da_header_t *)da - 1)->capacity)

#ifdef DYNAMIC_ARRAYS_IMPLEMENTATION

#include <assert.h>

void da_free(void *da)
{
        free((da_header_t *)da - 1);
        // assert(0 && "da_free() not implemented.\n");
}

#endif // !DYNAMIC_ARRAYS_IMPLEMENTATION

#endif // !DYNAMIC_ARRAYS_H_
