#ifndef STEEL_AVL_H_
#define STEEL_AVL_H_

#include "steel.h"

struct steel_avl_tree {
  size_t sat_count;
  size_t sat_elem_size;
  size_t sat_link_offset;

  steel_ordered_comparator_t sat_comparator;
  steel_allocator_t          sat_allocator;
  steel_deallocator_t        sat_deallocator;
};

typedef steel_avl_tree steel_avl_tree_t;


void steel_avl_create(steel_avl_tree_t *sat, size_t elem_size, size_t link_offset,
                      steel_ordered_comparator_t comparator, steel_allocator_t allocator,
                      steel_deallocator_t deallocator);

void steel_avl_destroy(steel_avl_tree_t *sat);

#endif  // STEEL_AVL_H_
