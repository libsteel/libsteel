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
      node = node->san_children[0];
    } else if (cmp > 0) {
      node = node->san_children[1];
    } else {
      return steel_avl_node_to_elem(sat, node);
    }
  }

  return NULL;
}

void steel_avl_node_init(const steel_avl_tree *sat, steel_avl_node_t *san) {
    san->san_children[0] = NULL;
    san->san_children[1] = NULL;
    san->san_parent = NULL;
    san->san_balance = 0;
}

void *steel_avl_insert(const steel_avl_tree *sat, void *elem) {
  steel_avl_node_t *node;
  steel_avl_node_t *new_node;
  steel_avl_node_t **next_nodep;
  int cmp;

  if (sat->sat_root == NULL) {
    /* the tree must be empty, make elem the new root */
    steel_avl_elem_init(steel_avl_elem_to_node(elem));
    return elem;
  }

  node = sat->sat_root;
  new_node = steel_avl_node_to_elem(sat, elem);
  next_nodep = NULL;
  for (;;) {
    cmp = sat->sat_comparator(elem, steel_avl_node_to_elem(sat, node));
    if (cmp < 0) {
      next_nodep = &san->san_children[0];
    } else if (cmp > 0) {
      next_nodep = &san->san_children[1];
    } else {
      return elem;
    }

    if (*next_nodep == NULL) {
      steel_avl_node_init(new_node);
      if (cmp < 0) {
        *next_nodep = new_node;
      } else {
        *next_nodep = new_node;
      }
      break;
    }

    if (*next_nodep->balance != 0) {
      unbalanced_node_parent = node;
      unbalanced_node = *next_nodep;
    }

    node = *next_nodep;
  }

  // TODO: rebalance!

  return NULL;
}

void steel_avl_fini(steel_avl_tree_t *sat) {
  assert(sat->sat_count == 0);
  assert(sat->root == NULL);
}
