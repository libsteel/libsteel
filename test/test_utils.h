#ifndef STEEL_TEST_UTILS_H
#define STEEL_TEST_UTILS_H
#include <stdio.h>
#include <stdlib.h>

#define ASSERT_TRUE( CONDITION , ERROR_MESSAGE) \
  if (! (CONDITION) ) { \
    fprintf(stderr , "Error in __FILE__ at line __LINE__: %s\n", ERROR_MESSAGE); \
    exit(1); \
  }


#endif //STEEL_TEST_HELPERS_H
