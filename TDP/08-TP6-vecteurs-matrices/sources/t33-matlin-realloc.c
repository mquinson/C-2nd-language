#include <stdio.h>

#include "utils_matlin.h"

int main(void) {

  unsigned int limite_basse = 0;
  matlin_t* m1 = matlin_read("data_matrix1.txt");
  matlin_set_dynamic(m1);
  unsigned int limite_lignes = matlin_get_linesamount(m1)+10;
  unsigned int limite_colonnes = matlin_get_rowsamount(m1)+10;
  for (unsigned int i = limite_lignes; i > limite_basse; i--)
      for (unsigned int j = limite_colonnes; j > limite_basse; j--)
          if (matlin_celladdr(m1, i, j) != NULL)
              *matlin_celladdr(m1, i, j) = i % 10;
  for (unsigned int i = limite_lignes; i > limite_basse; i--) {
    for (unsigned int j = limite_colonnes; j > limite_basse; j--)
      if (matlin_celladdr(m1, i, j) != NULL)
        printf("%g ", *matlin_celladdr(m1, i, j));
      else
        printf("- ");
    printf("\n");
  }
  matlin_delete(m1);

  matlin_t* m2 = matlin_read("data_matrix2.txt");
  matlin_set_dynamic(m2);
  limite_lignes = matlin_get_linesamount(m2) + 10;
  limite_colonnes = matlin_get_rowsamount(m2) + 10;
  for (unsigned int i = limite_basse; i < limite_lignes; i++)
      for (unsigned int j = limite_basse; j < limite_colonnes; j++)
          if (matlin_celladdr(m2, i, j) != NULL)
              *matlin_celladdr(m2, i, j) = i % 10;
  for (unsigned int i = limite_basse; i < limite_lignes; i++) {
    for (unsigned int j = limite_basse; j < limite_colonnes; j++)
      if (matlin_celladdr(m2, i, j) != NULL)
        printf("%g ", *matlin_celladdr(m2, i, j));
      else
        printf("- ");
    printf("\n");
  }
  matlin_delete(m2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);
  
  return 0;
}
