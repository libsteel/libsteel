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

void *steel_slist_insert_head(steel_slist_t *slist, void *elem) {
  steel_slist_node_t *to_insert;
  to_insert = steel_slist_elem_to_node(slist, elem);

  if(slist->head == NULL){
    slist->head = to_insert;
    slist->tail = to_insert;
    to_insert->next = NULL;
  }
  else{
    to_insert->next = slist->head;
    slist->head = to_insert;
  }

  return elem;
}

void *steel_slist_insert_tail(steel_slist_t *slist, void *elem) {
  steel_slist_node_t *to_insert;
  to_insert = steel_slist_elem_to_node(slist, elem);

  if(slist->head == NULL){
    slist->head = to_insert;
    slist->tail = to_insert;
  }
  else{
    slist->tail->next = to_insert;
    slist->tail = to_insert;
  }

  to_insert->next = NULL;

  return elem;
}

void *steel_slist_insert_after(steel_slist_t *slist, void *after, void *elem) {
  steel_slist_node_t *to_insert, *after_node;
  to_insert = steel_slist_elem_to_node(slist, elem);
  after_node = steel_slist_elem_to_node(slist, after);

  to_insert->next = after_node->next;
  after_node->next = to_insert;

  return elem;
}

