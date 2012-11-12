/**
 * Copyright 2012 Dave Majnemer and Kurtis Nusbaum
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "slist.h"

#include <assert.h>

static steel_slist_node_t *steel_slist_elem_to_node(const steel_slist_t *ssl, void *elem) {
  return (steel_slist_node_t *)((uintprt_t)elem + ssl->ssl_elem_offset);
}

static void *steel_slist_node_to_elem(const steel_slist_t *ssl, steel_slist_node_t *node) {
    return (void *)((uintptr_t)node - ssl->ssl_link_offset);
}

void steel_slist_init(steel_slist_t *ssl, size_t elem_size, size_t link_offset) {
  ssl->ssl_elem_size = elem_size;
  ssl->ssl_link_offset = link_offset;

  ssl->ssl_head = NULL;
  ssl->ssl_tail = NULL;
}

void steel_slist_fini(steel_slist_t *ssl) {
  assert(ssl->ssl_head == NULL);
  assert(ssl->ssl_tail == NULL);
}

void *steel_slist_head(steel_slist_t *ssl){
  return steel_slist_node_to_elem(ssl, ssl->ssl_head);
}

void *steel_slist_tail(steel_slist_t *ssl){
  return steel_slist_node_to_elem(ssl, ssl->ssl_tail);
}

void *steel_slist_insert_head(steel_slist_t *ssl, void *elem) {
  steel_slist_node_t *to_insert;

  to_insert = steel_slist_elem_to_node(ssl, elem);

  if (ssl->ssl_head == NULL) {
    ssl->ssl_tail = to_insert;
    to_insert->ssn_next = NULL;
  } else {
    to_insert->ssn_next = ssl->ssl_head;
  }
  ssl->ssl_head = to_insert;

  return elem;
}

void *steel_slist_insert_tail(steel_slist_t *ssl, void *elem) {
  steel_slist_node_t *to_insert;

  to_insert = steel_slist_elem_to_node(ssl, elem);

  if (ssl->ssl_head == NULL) {
    ssl->ssl_head = to_insert;
  } else {
    ssl->ssl_tail->ssn_next = to_insert;
  }

  ssl->ssl_tail = to_insert;
  to_insert->ssn_next = NULL;

  return elem;
}

void *steel_slist_insert_after(steel_slist_t *ssl, void *after, void *elem) {
  steel_slist_node_t *to_insert
  steel_slist_node_t *after_node;

  to_insert = steel_slist_elem_to_node(ssl, elem);
  after_node = steel_slist_elem_to_node(ssl, after);

  to_insert->ssn_next = after_node->ssn_next;
  after_node->ssn_next = to_insert;

  return elem;
}

void *steel_slist_remove_head(steel_slist_t *ssl) {
  slist_node_t *old_head;

  old_head = ssl->ssl_head;
  ssl->ssl_head = ssl->ssl_head->ssn_next;
  return steel_slist_node_to_elem(ssl, old_head);
}

void *steel_slist_remove(steel_slist_t *ssl, void *elem) {
  slist_node_t *to_find;
  slist_node_t *current_node;

  to_find = steel_slist_elem_to_node(ssl, elem);

  /* Special case for head node */
  if (ssl->ssl_head == to_find) {
    ssl->ssl_head = ssl->ssl_head->ssn_next;
    return elem;
  }

  current_node = ssl->ssl_head;
  while (current_node->ssn_next != NULL) {
    if (current_node->ssn_next == to_find) {
      current_node->ssn_next = current_node->ssn_next->ssn_next;
      return elem;
    }
  }
  return NULL;
}

