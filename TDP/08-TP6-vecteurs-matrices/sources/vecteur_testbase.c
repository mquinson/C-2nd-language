#include <stdio.h>

#include "vecteur.h"
#include "utils_vecteur.h"

int main(void) {
  vecteur_t *v1;
  vecteur_t *v2;

  v1 = lit_vecteur("vecteur1.txt");
  affiche_vecteur(v1);
  liberer_vecteur(v1);

  v2 = lit_vecteur("vecteur2.txt");
  affiche_vecteur(v2);
  liberer_vecteur(v2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
