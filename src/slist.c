#include "include/slist.h"

#include "assert.h"

void steel_slist_init(steel_slist_t *slist, size_t elem_size, size_t link_offset,
                      steel_allocator_t allocator, steel_deallocator_t deallocator) {
  slist->ssl_elem_size = elem_size;
  slist->ssl_link_offset = link_offset;

  slist->ssl_allocator = allocator;
  slist->ssl_deallocator = deallocator;

  slist->head = NULL;
  slist->tail = NULL;
}

void steel_slist_fini(steel_slist_t *slist) {
  assert(slist->head == NULL);
  assert(slist->tail == NULL);
}
