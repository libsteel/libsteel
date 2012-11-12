INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/test)

ADD_EXECUTABLE(ListInitTests list_init_tests.c)
TARGET_LINK_LIBRARIES(ListInitTests steel)

ADD_EXECUTABLE(HeadInsertTests list_head_insert_test.c)
TARGET_LINK_LIBRARIES(HeadInsertTests steel)

ADD_TEST(ListInitTests ${CMAKE_CURRENT_BINARY_DIR}/ListInitTests)
ADD_TEST(HeadInsertTests ${CMAKE_CURRENT_BINARY_DIR}/HeadInsertTests)
