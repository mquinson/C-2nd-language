#include <stdio.h>

#include "utils_matrice.h"

int main(void) {
  matrix_t* m1 = lit_matrice("matrice1.txt");
  for (unsigned int i = 0; i < nb_lignes_matrice(m1) + 100; i++) {
    for (unsigned int j = 0; j < nb_colonnes_matrice(m1) + 100; j++)
      if (acces_matrice(m1, i, j) == NULL)
        printf("0 ");
      else
        printf("1 ");
    printf("\n");
  }
  liberer_matrice(m1);

  matrix_t* m2 = lit_matrice("matrice2.txt");
  for (unsigned int i = 0; i < nb_lignes_matrice(m2) + 100; i++) {
    for (unsigned int j = 0; j < nb_colonnes_matrice(m2) + 100; j++)
      if (acces_matrice(m2, i, j) == NULL)
        printf("0 ");
      else
        printf("1 ");
    printf("\n");
  }
  liberer_matrice(m2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
