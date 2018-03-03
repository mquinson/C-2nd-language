#include <stdio.h>

#include "utils_matlin.h"

int main(void) {

  unsigned int limite_basse = 0;
  matlin_t* m1 = lit_matrice("matrice1.txt");
  matlin_rend_dynamique(m1);
  unsigned int limite_lignes = nb_lignes_matrice(m1)+10;
  unsigned int limite_colonnes = nb_colonnes_matrice(m1)+10;
  for (unsigned int i = limite_lignes; i > limite_basse; i--)
      for (unsigned int j = limite_colonnes; j > limite_basse; j--)
          if (acces_matrice(m1, i, j) != NULL)
              *acces_matrice(m1, i, j) = i % 10;
  for (unsigned int i = limite_lignes; i > limite_basse; i--) {
    for (unsigned int j = limite_colonnes; j > limite_basse; j--)
      if (acces_matrice(m1, i, j) != NULL)
        printf("%g ", *acces_matrice(m1, i, j));
      else
        printf("- ");
    printf("\n");
  }
  liberer_matrice(m1);

  matlin_t* m2 = lit_matrice("matrice2.txt");
  matlin_rend_dynamique(m2);
  limite_lignes = nb_lignes_matrice(m2) + 10;
  limite_colonnes = nb_colonnes_matrice(m2) + 10;
  for (unsigned int i = limite_basse; i < limite_lignes; i++)
      for (unsigned int j = limite_basse; j < limite_colonnes; j++)
          if (acces_matrice(m2, i, j) != NULL)
              *acces_matrice(m2, i, j) = i % 10;
  for (unsigned int i = limite_basse; i < limite_lignes; i++) {
    for (unsigned int j = limite_basse; j < limite_colonnes; j++)
      if (acces_matrice(m2, i, j) != NULL)
        printf("%g ", *acces_matrice(m2, i, j));
      else
        printf("- ");
    printf("\n");
  }
  liberer_matrice(m2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);
  
  return 0;
}
