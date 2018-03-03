#include <stdio.h>

#include "utils_matrice.h"

int main(void) {
  matrice_t *m1, *m2;
  unsigned i, j;
  unsigned limite_lignes, limite_colonnes, limite_basse;

  limite_basse = 0;
  m1 = lit_matrice("matrice1.txt");
  limite_lignes = nb_lignes_matrice(m1)+10;
  limite_colonnes = nb_colonnes_matrice(m1)+10;
  for (i = limite_lignes; i > limite_basse; i--)
      for (j = limite_colonnes; j > limite_basse; j--)
          if (acces_matrice(m1, i, j) != NULL)
              *acces_matrice(m1, i, j) = i % 10;
  for (i = limite_lignes; i > limite_basse; i--) {
    for (j = limite_colonnes; j > limite_basse; j--)
      if (acces_matrice(m1, i, j) != NULL)
        printf("%g ", *acces_matrice(m1, i, j));
      else
        printf("- ");
    printf("\n");
  }
  liberer_matrice(m1);
  m2 = lit_matrice("matrice2.txt");
  limite_lignes = nb_lignes_matrice(m2) + 10;
  limite_colonnes = nb_colonnes_matrice(m2) + 10;
  for (i = limite_basse; i < limite_lignes; i++)
      for (j = limite_basse; j < limite_colonnes; j++)
          if (acces_matrice(m2, i, j) != NULL)
              *acces_matrice(m2, i, j) = i % 10;
  for (i = limite_basse; i < limite_lignes; i++) {
    for (j = limite_basse; j < limite_colonnes; j++)
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
