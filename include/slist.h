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

#include <stddef.h>

/**
 * \brief Represents a node in a singly linked list.
 */
struct steel_slist_node {
  struct steel_slist_node *ssn_next;
};

/**
 * \brief Convenience typedef.
 */
typedef struct steel_slist_node steel_slist_node_t;

/**
 * \brief Represents a node in a singly linked list.
 */
struct steel_slist {
  size_t ssl_elem_size;
  size_t ssl_link_offset;

  steel_slist_node_t *ssl_head;
  steel_slist_node_t *ssl_tail;
};

/**
 * \brief Convenience typedef.
 */
typedef struct steel_slist steel_slist_t;

/**
 * \brief Initializes a Singly Linked List.
 *
 * \param ssl The Singly Linked List to be initialized.
 * \param elem_size The size of the elements comprising the Singly Linked List.
 * \param link_offset The offset of the steel_slist_node within each element in the Singly Linked List.
 */
void steel_slist_init(steel_slist_t *ssl, size_t elem_size, size_t link_offset);

/**
 * \brief Finalizes a Singly Linked List.
 *
 * Performs any necessary clean up for a Singly Linked List.
 *
 * \param ssl The Singly Linked List to finalize.
 */
void steel_slist_fini(steel_slist_t *ssl);

/**
 * \brief Returns the head element of a Singly Linked List.
 *
 * \param ssl The Singly Linked List whose head is desired.
 * \return The head element of the given Singly Linked List. Returns NULL if the list is empty.
 */
void *steel_slist_head(steel_slist_t *ssl);

/**
 * \brief Returns the tail element of a Singly Linked List.
 *
 * \param ssl The Singly Linked List whose tail is desired.
 * \return The tail element of the given Singly Linked List. Returns NULL if the list is empty.
 */
void *steel_slist_tail(steel_slist_t *ssl);

/**
 * \brief Inserts a new element into the Singly Linked List at the head of the list.
 *
 * \param ssl The Singly Linked List into which the given element should be inserted.
 * \param elem The element to be inserted into the given Singly Linked List.
 * \return The element that was inserted.
 */
void *steel_slist_insert_head(steel_slist_t *ssl, void *elem);

/**
 * \brief Inserts a new element into the Singly Linked List at the tail of the list.
 *
 * \param ssl The Singly Linked List into which the given element should be inserted.
 * \param elem The element to be inserted into the given Singly Linked List.
 * \return The element that was inserted.
 */
void *steel_slist_insert_tail(steel_slist_t *ssl, void *elem);

/**
 * \brief Inserts a new element into the Singly Linked List after the specified element.
 *
 * \param ssl The Singly Linked List into which the given element should be inserted.
 * \param after The element after which given element should be inserted in the Singly Linked List.
 * \param elem The element to be inserted into the given Singly Linked List.
 * \return The element that was inserted.
 */
void *steel_slist_insert_after(steel_slist_t *ssl, void *after, void *elem);

/**
 * \brief Removes the head element from the given Singly Linked List.
 *
 * \param ssl The Singly Linked List from which the head should be removed.
 * \return The head element that was removed from the Singly Linked List. Returns NULL if the
 * Singly Linked List is empty.
 */
void *steel_slist_remove_head(steel_slist_t *ssl);

/**
 * \brief Removes the tail element from the given Singly Linked List.
 *
 * \param ssl The Singly Linked List from which the tail should be remove.
 * \return The tail element that was removed from the Singly Linked List. Returns NULL
 * if the element is not in the Singly Linked List.
 */
void *steel_slist_remove(steel_slist_t *ssl, void *elem);


#endif //STEEL_SLIST_H
