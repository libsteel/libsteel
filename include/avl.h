#ifndef STEEL_AVL_H_
#define STEEL_AVL_H_

#include "steel.h"

struct steel_avl_node {
  struct steel_avl_node san_children[2];
};
typedef struct steel_avl_node steel_avl_node_t;

struct steel_avl_tree {
  size_t sat_count;
  size_t sat_elem_size;
  size_t sat_link_offset;

  steel_avl_node_t sat_root;

  steel_ordered_comparator_t sat_comparator;
};
typedef steel_avl_tree steel_avl_tree_t;


void steel_avl_init(steel_avl_tree_t *sat, size_t elem_size, size_t link_offset,
                    steel_ordered_comparator_t comparator);

void steel_avl_fini(steel_avl_tree_t *sat);

#endif  // STEEL_AVL_H_
