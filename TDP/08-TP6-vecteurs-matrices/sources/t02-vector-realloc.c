#include <stdio.h>
#include <math.h>

#include "vecteur.h"
#include "utils_vecteur.h"

int main(void) {

  printf("Crée un vecteur dynamique de longueur 20 où chaque case est un seul chiffre:\n");
  vector_t* v1 = vector_new(20);
  vector_set_dynamic(v1);
  for (unsigned int i = 0; i < 20; i++)
    *vector_celladdr(v1, i) = i % 10;

  for (unsigned int i = 0; i < vector_size(v1); i++)
      if (vector_celladdr(v1, i) != NULL)
          printf("%g", *vector_celladdr(v1, i));
  printf("\n\n");

  printf("Ajoute 10 cases derrière, et réaffiche le tout:\n");
  for (unsigned int i = 20; i < 30; i++)
      if (vector_celladdr(v1, i) != NULL)
          *vector_celladdr(v1, i) = i % 10;

  for (unsigned int i = 0; i < 30; i++)
      if (vector_celladdr(v1, i) != NULL)
          printf("%g", *vector_celladdr(v1, i));
  printf("\n");
  vector_delete(v1);

  printf("\n\n\nCrée un nouveau vecteur dynamique de longueur 20 où chaque case est un seul chiffre:\n");
  vector_t* v2 = vector_new(20);
  vector_set_dynamic(v2);
  for (unsigned int i = 0; i < 20; i++)
    *vector_celladdr(v2, i) = i % 10;

  for (unsigned int i = 0; i < vector_size(v2); i++)
      if (vector_celladdr(v2, i) != NULL)
          printf("%g", *vector_celladdr(v2, i));
  printf("\n\n");

  printf("Ajoute 10 cases derrière (en commençant par la dernière), et réaffiche le tout:\n");
  for (unsigned int i = 0; i < 10; i++)
      if (vector_celladdr(v2, 30-i) != NULL)
          *vector_celladdr(v2, 30-i) = i % 10;

  for (unsigned int i = 0; i < 30; i++)
      if (vector_celladdr(v2, i) != NULL)
          printf("%g", *vector_celladdr(v2, i));
  printf("\n");
  vector_delete(v2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
