#include "avl.h"

#include <assert.h>
#include <stddef.h>
#include <stdint.h>

static void *steel_avl_node_to_elem(const steel_avl_tree_t *sat, steel_avl_node_t *san) {
  return (void *)((uintptr_t)san - sat->sat_link_offset);
}

static steel_avl_node_t *steel_avl_elem_to_node(const steel_avl_tree_t *sat, void *elem) {
  return (steel_avl_node_t *)((uintptr_t)elem + sat->sat_link_offset);
}

static void steel_avl_swap_parent(const steel_avl_tree_t *sat, steel_avl_node_t *old, steel_avl_node_t *new) {
  if (old->san_parent == NULL) {
    sat->sat_root = new;
  } else if (old->san_parent->san_children[0] == old) {
    old->san_parent->san_children[0] = new;
  } else if (old->san_parent->san_children[1] == old) {
    old->san_parent->san_children[1] = new;
  }
  if (new != NULL) {
    new->san_parent = old->san_parent;
  }
}

static void steel_avl_rotate_left(const steel_avl_tree_t *sat, steel_avl_node_t *san) {
  steel_avl_node_t *right;

  right = san->san_children[1];
  steel_avl_swap_parent(sat, san, right);
  san->san_children[1] = right->san_children[0];
  if (right->san_children[0] != NULL) {
    right->san_children[0]->san_parent = san;
  }
  right->san_children[0] = san;
  san->san_parent = right;
}

static void steel_avl_rotate_right(const steel_avl_tree_t *sat, steel_avl_node_t *san) {
  steel_avl_node_t *left;

  left = san->san_children[0];
  steel_avl_swap_parent(sat, san, left);
  san->san_children[0] = left->san_children[1];
  if (left->san_children[1] != NULL) {
    left->san_children[1]->san_parent = san;
  }
  left->san_children[1] = san;
  san->san_parent = left;
}

void steel_avl_init(steel_avl_tree_t *sat, size_t elem_size, size_t link_offset,
                    steel_ordered_comparator_t comparator) {
  sat->sat_count = 0;
  sat->sat_elem_size = elem_size;
  sat->sat_link_offset = link_offset;

  sat->sat_root = NULL;

  sat->sat_comparator = comparator;
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
  steel_avl_node_t *unbalanced_node;
  steel_avl_node_t **next_nodep;
  int cmp;

  new_node = steel_avl_node_to_elem(sat, elem);
  if (sat->sat_root == NULL) {
    /* the tree must be empty, make elem the new root */
    steel_avl_elem_init(new_node);
    sat->sat_root = new_node;
    return elem;
  }

  unbalanced_node = NULL;

  node = sat->sat_root;
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
      *next_nodep = new_node;
      break;
    }

    if (*next_nodep->balance != 0) {
      unbalanced_node = *next_nodep;
    }

    node = *next_nodep;
  }

  /* fix-up balance factors */
  node = unbalanced_node;
  while (node != NULL && node != new_node) {
    cmp = sat->sat_comparator(elem, steel_avl_node_to_elem(sat, node));
    if (cmp < 0) {
      node->balance -= 1;
      node = node->san_children[0];
    } else {
      node->balance += 1;
      node = node->san_children[1];
    }
  }

  /* rebalance the tree via rotations */
  node = unbalanced_node;
  if (node != NULL) {
    left = node->san_children[0];
    right = node->san_children[1];
    if (node->san_balance == -2) {
      if (node->san_balance == -1) {
        steel_avl_rotate_left(sat, node);
      } else if (node->san_balance == 1) {
        steel_avl_rotate_right(sat, right);
        steel_avl_rotate_left(sat, node);
      }
    } else if (node->san_balance == 2) {
      if (node->san_balance == 1) {
        steel_avl_rotate_right(sat, node);
      } else if (node->san_balance == -1) {
        steel_avl_rotate_left(sat, left);
        steel_avl_rotate_right(sat, node);
      }
    }
  }

  return elem;
}

void steel_avl_fini(steel_avl_tree_t *sat) {
  assert(sat->sat_count == 0);
  assert(sat->root == NULL);
}
