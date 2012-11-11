#ifndef STEEL_STEEL_H_
#define STEEL_STEEL_H_

#include <stddef.h>

typedef int (*steel_ordered_comparator_t)(const void *vp_lhs, const void *vp_rhs);

typedef void *(*steel_allocator_t)(size_t nbytes);
typedef void (*steel_deallocator_t)(void *ptr, size_t *nbytes);

#endif  // STEEL_STEEL_H_
