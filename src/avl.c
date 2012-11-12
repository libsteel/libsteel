#include "avl.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

void steel_avl_init(steel_avl_tree_t *sat, size_t elem_size, size_t link_offset,
                    steel_ordered_comparator_t comparator) {
  sat->sat_count = 0;
  sat->sat_elem_size = elem_size;
  sat->sat_link_offset = link_offset;

  sat->sat_root = NULL;

  sat->sat_comparator = comparator;
}

static void *steel_avl_node_to_elem(const steel_avl_tree *sat, steel_avl_node_t *san) {
  return (void *)((uintptr_t)san - sat->sat_link_offset);
}

static steel_avl_node_t *steel_avl_elem_to_node(const steel_avl_tree *sat, void *elem) {
  return (steel_avl_node_t *)((uintptr_t)elem + sat->sat_link_offset);
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

  if (node == NULL) {
    return NULL;
  }

  return steel_avl_node_to_elem(sat, node);
}

void *steel_avl_insert(const steel_avl_tree *sat, void *elem) {
  if (sat->sat_root == NULL) {
    /* the tree must be empty, make elem the new root */
    steel_avl_node_t *new_node;

    new_node = steel_avl_elem_to_node(elem);
    new_node->san_children[0] = NULL;
    new_node->san_children[1] = NULL;
    new_node->san_parent = NULL;
    new_node->san_balance = 0;

    return elem;
  }

  // XXX: deal with more complicated cases here
  assert(false);
  return NULL;
}

void steel_avl_fini(steel_avl_tree_t *sat) {
  assert(sat->sat_count == 0);
  assert(sat->root == NULL);
}
