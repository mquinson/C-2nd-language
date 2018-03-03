#include <stdio.h>

#include "utils_vector.h"
#include "memory_operations.h"

int main(void) {
  vector_t* v1 = lit_vecteur("data_vector1.txt");
  vector_t* v2 = vector_new(vector_size(v1));

  my_memcpy(vector_celladdr(v2, 0), vector_celladdr(v1, 0),vector_size(v1) * sizeof(double));

  vector_print(v1);
  vector_print(v2);
  vector_delete(v1);
  vector_delete(v2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);
  
  return 0;
}
