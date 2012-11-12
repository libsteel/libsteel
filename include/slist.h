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
#ifndef STEEL_SLIST_H
#define STEEL_SLIST_H

typedef struct steel_slist_node {
  struct steel_slist_node *ssn_next;
};
typedef struct steel_slist_node steel_slist_node_t;

typedef struct steel_slist {
  size_t ssl_elem_size;
  size_t ssl_link_offset

  steel_slist_node_t *ssl_head;
  steel_slist_node_t *ssl_tail;
};
typedef struct steel_slist steel_slist_t;

void steel_slist_init(steel_slist_t *ssl, size_t elem_size, size_t link_offset);

void steel_slist_fini(steel_slist_t *ssl);

void *steel_slist_head(steel_slist_t *ssl);

void *steel_slist_tail(steel_slist_t *ssl);

void *steel_slist_insert_head(steel_slist_t *ssl, void *elem);

void *steel_slist_insert_tail(steel_slist_t *ssl, void *elem);

void *steel_slist_insert_after(steel_slist_t *ssl, void *after, void *elem);

void *steel_slist_remove_head(steel_slist_t *ssl);

void *steel_slist_remove(steel_slist_t *ssl, void *elem);


#endif //STEEL_SLIST_H
