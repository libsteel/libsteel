INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/test)

ADD_UNIT_TEST( ListInitTest list_init_test.c)
ADD_UNIT_TEST( ListHeadInsertTest list_head_insert_test.c)

