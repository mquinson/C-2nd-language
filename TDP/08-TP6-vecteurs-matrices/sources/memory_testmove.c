#include <stdio.h>

#include "vecteur.h"
#include "utils_vecteur.h"
#include "memory_operations.h"

int main(void) {
  vecteur_t* v1 = lit_vecteur("vecteur1.txt");
  affiche_vecteur(v1);
  size_t taille = taille_vecteur(v1);
  vecteur_t* v2 = allouer_vecteur(taille);
  my_memcpy(acces_vecteur(v2, 0), acces_vecteur(v1, 0), taille * sizeof(double));
  my_memmove(acces_vecteur(v2, 0), acces_vecteur(v2, taille / 4), (taille/2) * sizeof(double));
  affiche_vecteur(v2);
  my_memcpy(acces_vecteur(v2, 0), acces_vecteur(v1, 0),taille * sizeof(double));
  my_memmove(acces_vecteur(v2, taille/4), acces_vecteur(v2, 0), (taille/2) * sizeof(double));
  affiche_vecteur(v2);
  liberer_vecteur(v1);
  liberer_vecteur(v2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);
  
  return 0;
}
