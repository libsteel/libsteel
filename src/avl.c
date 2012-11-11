#include "avl.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

void steel_avl_init(steel_avl_tree_t *sat, size_t elem_size, size_t link_offset,
                    steel_ordered_comparator_t comparator, steel_allocator_t allocator,
                    steel_deallocator_t deallocator) {
  sat->sat_count = 0;
  sat->sat_elem_size = elem_size;
  sat->sat_link_offset = link_offset;

  sat->sat_root = NULL;

  sat->sat_comparator = comparator;
  sat->sat_allocator = allocator;
  sat->sat_deallocator = deallocator;
}

void *steel_avl_node_to_elem(const steel_avl_tree *sat, steel_avl_node_t *san) {
  return (void *)((uintptr_t)san - sat->sat_link_offset);
}

void *steel_avl_search(const steel_avl_tree *sat, const void *key) {
  steel_avl_node_t *node;

  node = sat->sat_root;
  while (node != NULL) {
    int cmp;

    cmp = sat->sat_comparator(key, steel_avl_node_to_elem(sat, node));
    if (cmp < 0) {
      node = sat->sat_comparator[0];
    } else if (cmp > 0) {
      node = sat->sat_comparator[1];
    } else {
      break;
    }
  }
  return steel_avl_node_to_elem(sat, node);
}

void steel_avl_fini(steel_avl_tree_t *sat) {
  assert(sat->sat_count == 0);
  assert(sat->root == NULL);
}
