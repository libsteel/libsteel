#include "include/slist.h"

#include "assert.h"

void steel_slist_init(steel_slist_t *ssl, size_t elem_size, size_t link_offset) {
  ssl->ssl_elem_size = elem_size;
  ssl->ssl_link_offset = link_offset;

  ssl->head = NULL;
  ssl->tail = NULL;
}

void steel_slist_fini(steel_slist_t *ssl) {
  assert(ssl->head == NULL);
  assert(ssl->tail == NULL);
}

static steel_slist_node_t *steel_slist_elem_to_node(const steel_slist_t *ssl, void *elem) {
  return (steel_slist_node_t *)((uintprt_t)elem + ssl->ssl_elem_offset);
}

void *steel_slist_insert_head(steel_slist_t *ssl, void *elem) {
  steel_slist_node_t *to_insert;
  to_insert = steel_slist_elem_to_node(ssl, elem);

  if(ssl->head == NULL){
    ssl->head = to_insert;
    ssl->tail = to_insert;
    to_insert->next = NULL;
  }
  else{
    to_insert->next = ssl->head;
    ssl->head = to_insert;
  }

  return elem;
}

void *steel_slist_insert_tail(steel_slist_t *ssl, void *elem) {
  steel_slist_node_t *to_insert;
  to_insert = steel_slist_elem_to_node(ssl, elem);

  if(ssl->head == NULL){
    ssl->head = to_insert;
    ssl->tail = to_insert;
  }
  else{
    ssl->tail->next = to_insert;
    ssl->tail = to_insert;
  }

  to_insert->next = NULL;

  return elem;
}

void *steel_slist_insert_after(steel_slist_t *ssl, void *after, void *elem) {
  steel_slist_node_t *to_insert, *after_node;
  to_insert = steel_slist_elem_to_node(ssl, elem);
  after_node = steel_slist_elem_to_node(ssl, after);

  to_insert->next = after_node->next;
  after_node->next = to_insert;

  return elem;
}

static void *steel_slist_node_to_elem(const steel_slist_t *ssl, steel_slist_node_t *elem) {
    return (void *)((uintptr_t)elem - ssl->ssl_link_offset);
}


void *steel_slist_remove_head(steel_slist_t *ssl) {
  slist_node_t* old_head;
  old_head = ssl->head;
  ssl->head = ssl->head->next;
  return steel_slist_node_to_elem(ssl, old_head);
}

void *steel_slist_remove(steel_slist_t *ssl, void *elem) {
  slist_node_t* to_find;
  to_find = steel_slist_elem_to_node(ssl, elem);

  /* Special case for head node */
  if(to_find == ssl->head){
    ssl->head = ssl->head->next;
    return elem;
  }

  slist_node_t* current_node;
  current_node = ssl->head;
  while(current_node->next != NULL){
    if(current->next == to_find){
      current->next = current->next->next;
      return elem;
    }
  }
  return NULL;
}

