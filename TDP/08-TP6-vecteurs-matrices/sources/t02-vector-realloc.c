#include <stdio.h>
#include <math.h>

#include "vecteur.h"
#include "utils_vecteur.h"

int main(void) {

  printf("Crée un vecteur dynamique de longueur 20 où chaque case est un seul chiffre:\n");
  vecteur_t* v1 = allouer_vecteur(20);
  vecteur_rend_dynamique(v1);
  for (unsigned int i = 0; i < 20; i++)
    *acces_vecteur(v1, i) = i % 10;

  for (unsigned int i = 0; i < taille_vecteur(v1); i++)
      if (acces_vecteur(v1, i) != NULL)
          printf("%g", *acces_vecteur(v1, i));
  printf("\n\n");

  printf("Ajoute 10 cases derrière, et réaffiche le tout:\n");
  for (unsigned int i = 20; i < 30; i++)
      if (acces_vecteur(v1, i) != NULL)
          *acces_vecteur(v1, i) = i % 10;

  for (unsigned int i = 0; i < 30; i++)
      if (acces_vecteur(v1, i) != NULL)
          printf("%g", *acces_vecteur(v1, i));
  printf("\n");
  liberer_vecteur(v1);

  printf("\n\n\nCrée un nouveau vecteur dynamique de longueur 20 où chaque case est un seul chiffre:\n");
  vecteur_t* v2 = allouer_vecteur(20);
  vecteur_rend_dynamique(v2);
  for (unsigned int i = 0; i < 20; i++)
    *acces_vecteur(v2, i) = i % 10;

  for (unsigned int i = 0; i < taille_vecteur(v2); i++)
      if (acces_vecteur(v2, i) != NULL)
          printf("%g", *acces_vecteur(v2, i));
  printf("\n\n");

  printf("Ajoute 10 cases derrière (en commençant par la dernière), et réaffiche le tout:\n");
  for (unsigned int i = 0; i < 10; i++)
      if (acces_vecteur(v2, 30-i) != NULL)
          *acces_vecteur(v2, 30-i) = i % 10;

  for (unsigned int i = 0; i < 30; i++)
      if (acces_vecteur(v2, i) != NULL)
          printf("%g", *acces_vecteur(v2, i));
  printf("\n");
  liberer_vecteur(v2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
