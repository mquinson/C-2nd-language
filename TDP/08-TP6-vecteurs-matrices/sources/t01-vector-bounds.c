#include <stdio.h>

#include "utils_vector.h"

int main(void) {

  vector_t* v1 = lit_vecteur("data_vector1.txt");
  size_t taille1 = vector_size(v1);
  printf("Taille vecteur1: %zu\n", vector_size(v1));
  for (int i = 0; i < taille1 + 100; i++)
      printf("%d", vector_celladdr(v1,i) == NULL);
  printf("\n");
  vector_delete(v1);

  vector_t* v2 = lit_vecteur("data_vector2.txt");
  size_t taille2 = vector_size(v2);
  printf("Taille vecteur2: %zu\n", taille2);
  for (int i = 0; i < taille2 + 100; i++)
      printf("%d", vector_celladdr(v2,i) == NULL);
  printf("\n");
  vector_delete(v2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);
  
  return 0;
}
