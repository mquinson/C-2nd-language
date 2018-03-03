#include <stdio.h>

#include "utils_vector.h"

int main(void) {

  vector_t* v1 = lit_vecteur("data_vector1.txt");
  vector_print(v1);
  vector_delete(v1);

  vector_t* v2 = lit_vecteur("data_vector2.txt");
  vector_print(v2);
  vector_delete(v2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
