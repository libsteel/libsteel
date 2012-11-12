#include "slist.h"
#include "test_utils.h"

struct test_element{
  int value;
  steel_slist_node_t link;
};
typedef struct test_element test_element_t;

void test_basic_init(){
  steel_slist_t my_list;
  steel_slist_init(&my_list, sizeof(test_element_t), offsetof(test_element_t, link));

  ASSERT_TRUE(my_list.ssl_elem_size == sizeof(test_element_t), "Element sizes don't match.");
  ASSERT_TRUE(my_list.ssl_link_offset == offsetof(test_element_t, link), "Offsets don't match.");
  ASSERT_TRUE(my_list.ssl_head == NULL, "Head isn't null.");
  ASSERT_TRUE(my_list.ssl_tail == NULL, "Tail isn't null.");
}


int main(int argc, char *argv[]){
  test_basic_init();
  return 0;
}

