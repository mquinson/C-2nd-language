#include <stdio.h>

#include "utils_matrix.h"

int main(void) {

  unsigned int limite_basse = 0;
  matrix_t* m1 = matrix_read("data_matrix1.txt");
  matrix_set_dynamic(m1);
  unsigned int limite_lignes = matrix_get_linesamount(m1)+10;
  unsigned int limite_colonnes = matrix_get_rowsamount(m1)+10;
  for (unsigned int i = limite_lignes; i > limite_basse; i--)
      for (unsigned int j = limite_colonnes; j > limite_basse; j--)
          if (matrix_celladdr(m1, i, j) != NULL)
              *matrix_celladdr(m1, i, j) = i % 10;
  for (unsigned int i = limite_lignes; i > limite_basse; i--) {
    for (unsigned int j = limite_colonnes; j > limite_basse; j--)
      if (matrix_celladdr(m1, i, j) != NULL)
        printf("%g ", *matrix_celladdr(m1, i, j));
      else
        printf("- ");
    printf("\n");
  }
  matrix_delete(m1);

  matrix_t* m2 = matrix_read("data_matrix2.txt");
  matrix_set_dynamic(m2);
  limite_lignes = matrix_get_linesamount(m2) + 10;
  limite_colonnes = matrix_get_rowsamount(m2) + 10;
  for (unsigned int i = limite_basse; i < limite_lignes; i++)
      for (unsigned int j = limite_basse; j < limite_colonnes; j++)
          if (matrix_celladdr(m2, i, j) != NULL)
              *matrix_celladdr(m2, i, j) = i % 10;
  for (unsigned int i = limite_basse; i < limite_lignes; i++) {
    for (unsigned int j = limite_basse; j < limite_colonnes; j++)
      if (matrix_celladdr(m2, i, j) != NULL)
        printf("%g ", *matrix_celladdr(m2, i, j));
      else
        printf("- ");
    printf("\n");
  }
  matrix_delete(m2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);
  
  return 0;
}
