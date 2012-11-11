#ifndef STEEL_SINGLY_LINKED_LIST_H
#define STEEL_SINGLY_LINKED_LIST_H

typedef struct steel_slist_node{
  struct steel_slist_node *next;
};

typedef struct steel_slist_node steel_slist_node_t;

typedef struct steel_slist{
  size_t ssl_elem_size;
  size_t ssl_link_offset

  steel_ordered_comparator_t ssl_comparator;
  steel_allocator_t ssl_allocator,
  steel_deallocator_t ssl_deallocator;

  steel_slist_node_t *head;
  steel_slist_node_t *tail;
};

typedef struct steel_slist steel_slist_t;

void steel_slist_init(steel_slist_t *slist, size_t elem_size, size_t link_offset,
                      steel_ordered_comparator_t comparator, steel_allocator_t allocator,
                      steel_deallocator_t deallocator);

void steel_slist_fini(steel_slist_t *slist);



#endif //STEEL_SINGLY_LINKED_LIST_H
