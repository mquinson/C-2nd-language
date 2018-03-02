#include <stdio.h>
#include <math.h>

#include "vecteur.h"
#include "utils_vecteur.h"

int main(void) {
  vecteur_t *v1, *v2;
  unsigned i, limite;

  v1 = lit_vecteur("vecteur1.txt");
  limite = taille_vecteur(v1);
  for (i = 0; i < limite + 100; i++)
      if (acces_vecteur(v1, i) != NULL)
          *acces_vecteur(v1, i) = i % 10;
  for (i = 0; i < limite + 100; i++)
      if (acces_vecteur(v1, i) != NULL)
          printf("%g", *acces_vecteur(v1, i));
  printf("\n");
  liberer_vecteur(v1);

  v2 = lit_vecteur("vecteur2.txt");
  limite = taille_vecteur(v2);
  for (i = limite + 101; i > 0; i--)
      if (acces_vecteur(v2, i - 1) != NULL)
          *acces_vecteur(v2, i - 1) = (i - 1) % 10;
  for (i = limite + 101; i > 0; i--)
      if (acces_vecteur(v2, i - 1) != NULL)
          printf("%g", *acces_vecteur(v2, i - 1));
  printf("\n");
  liberer_vecteur(v2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
