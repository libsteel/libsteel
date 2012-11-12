#include "slist.h"

#include <assert.h>

struct test_element{
  int value;
  steel_slist_node_t link;
};
typedef struct test_element test_element_t;


int main(int argc, char *argv[]){
  steel_slist_t my_list;
  steel_slist_init(&my_list, sizeof(test_element_t), offsetof(test_element_t, link));

  assert(my_list.ssl_elem_size == sizeof(test_element_t));
  assert(my_list.ssl_link_offset == offsetof(test_element_t, link));
  assert(my_list.ssl_head == NULL);
  assert(my_list.ssl_tail == NULL);

  return 0;
}

