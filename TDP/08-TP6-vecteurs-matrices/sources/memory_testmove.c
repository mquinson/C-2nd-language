#include <stdio.h>

#include "utils_vector.h"
#include "memory_operations.h"

int main(void) {
  vector_t* v1 = lit_vecteur("data_vector1.txt");
  vector_print(v1);
  size_t taille = vector_size(v1);

  vector_t* v2 = vector_new(taille);
  my_memcpy(vector_celladdr(v2, 0), vector_celladdr(v1, 0), taille * sizeof(double));
  my_memmove(vector_celladdr(v2, 0), vector_celladdr(v2, taille / 4), (taille/2) * sizeof(double));
  vector_print(v2);
  my_memcpy(vector_celladdr(v2, 0), vector_celladdr(v1, 0),taille * sizeof(double));
  my_memmove(vector_celladdr(v2, taille/4), vector_celladdr(v2, 0), (taille/2) * sizeof(double));
  vector_print(v2);
  vector_delete(v1);
  vector_delete(v2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);
  
  return 0;
}
