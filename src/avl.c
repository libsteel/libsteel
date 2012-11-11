#include "avl.h"

void steel_avl_create(steel_avl_tree_t *sat, size_t elem_size, size_t link_offset,
                      steel_ordered_comparator_t comparator, steel_allocator_t allocator,
                      steel_deallocator_t deallocator) {
  sat->sat_count = 0;
  sat->sat_elem_size = elem_size;
  sat->sat_link_offset = link_offset;

  sat->sat_comparator = comparator;
  sat->sat_allocator = allocator;
  sat->sat_deallocator = deallocator;
}

void steel_avl_destroy(steel_avl_tree_t *sat) {
	(void) sat;
}
