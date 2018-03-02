#include <stdio.h>

#include "vecteur.h"
#include "utils_vecteur.h"

int main(void) {

  vecteur_t* v1 = lit_vecteur("vecteur1.txt");
  size_t taille1 = taille_vecteur(v1);
  printf("Taille vecteur1: %zu\n", taille_vecteur(v1));
  for (int i = 0; i < taille1 + 100; i++)
      printf("%d", acces_vecteur(v1,i) == NULL);
  printf("\n");
  liberer_vecteur(v1);

  vecteur_t* v2 = lit_vecteur("vecteur2.txt");
  size_t taille2 = taille_vecteur(v2);
  printf("Taille vecteur2: %zu\n", taille2);
  for (int i = 0; i < taille2 + 100; i++)
      printf("%d", acces_vecteur(v2,i) == NULL);
  printf("\n");
  liberer_vecteur(v2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);
  
  return 0;
}
