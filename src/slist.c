#include "include/slist.h"

#include "assert.h"

void steel_slist_init(steel_slist_t *slist, size_t elem_size, size_t link_offset) {
  slist->ssl_elem_size = elem_size;
  slist->ssl_link_offset = link_offset;

  slist->head = NULL;
  slist->tail = NULL;
}

void steel_slist_fini(steel_slist_t *slist) {
  assert(slist->head == NULL);
  assert(slist->tail == NULL);
}

steel_slist_node_t *steel_slist_elem_to_node(const steel_slist_t *slist, void *elem) {
  return (steel_slist_node_t *)((uintprt_t)elem + slist->ssl_elem_offset);
}

void steel_slist_insert(steel_slist_t *slist, void *elem) {
  steel_slist_node_t *node;
  node = steel_slist_elem_to_node(slist, elem);

  if(slist->head == NULL){
    slist->head = node;
    slist->tail = node;
  }
  else{
    slist->tail->next = node;
    slist->tail = node;
  }

  node->next = NULL;
}
