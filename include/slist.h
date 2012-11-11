#ifndef STEEL_SINGLY_LINKED_LIST_H
#define STEEL_SINGLY_LINKED_LIST_H

#include "steel.h"

typedef struct steel_slist_node{
  struct steel_slist_node *next;
};
typedef struct steel_slist_node steel_slist_node_t;

typedef struct steel_slist{
  size_t ssl_elem_size;
  size_t ssl_link_offset

  steel_slist_node_t *head;
  steel_slist_node_t *tail;
};
typedef struct steel_slist steel_slist_t;

void steel_slist_init(steel_slist_t *slist, size_t elem_size, size_t link_offset);

void steel_slist_fini(steel_slist_t *slist);

void steel_slist_insert_head(steel_slist_t *slist, void *elem);

void steel_slist_insert_tail(steel_slist_t *slist, void *elem);

void steel_slist_insert_after(steel_slist_t *slist, void *elem);

void *steel_slit_remove_head(steel_slist_t *slist);

void *steel_slist_remove_tail(steel_slist_t *slist);

void *steel_slist_remove(steel_slist_t *slist, void *elem);


#endif //STEEL_SINGLY_LINKED_LIST_H
