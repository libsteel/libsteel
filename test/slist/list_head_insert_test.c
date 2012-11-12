#include "slist.h"
#include "test_utils.h"

struct test_element{
  int value;
  steel_slist_node_t link;
};
typedef struct test_element test_element_t;

void test_basic_init(){
  test_element_t my_element2;
  test_element_t my_element1;
  steel_slist_t my_list;

  steel_slist_init(&my_list, sizeof(test_element_t), offsetof(test_element_t, link));
  my_element1.value = 5;
  my_element2.value = 1;
  steel_slist_insert_head(&my_list, &my_element1);
  steel_slist_insert_head(&my_list, &my_element2);
  ASSERT_TRUE(steel_slist_head(&my_list) == &my_element2, "Head doesn't equal the second element.")
}


int main(int argc, char *argv[]){
  test_basic_init();
  return 0;
}

