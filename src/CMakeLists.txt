INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

SET(SRC
  avl.c
  slist.c
)

ADD_LIBRARY(steel ${SRC})
