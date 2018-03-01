#include <stdio.h>

#include "vecteur.h"
#include "utils_vecteur.h"

int main(void) {
  vecteur *v1, *v2;
  unsigned i;

  v1 = lit_vecteur("vecteur1.txt");
  for (i = 0; i < taille_vecteur(v1) + 1000; i++)
      printf("%d", acces_vecteur(v1,i) == NULL);
  printf("\n");
  liberer_vecteur(v1);

  v2 = lit_vecteur("vecteur2.txt");
  for (i = 0; i < taille_vecteur(v2) + 1000; i++)
      printf("%d", acces_vecteur(v2,i) == NULL);
  printf("\n");
  liberer_vecteur(v2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);
  
  return 0;
}
