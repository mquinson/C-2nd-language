#include <stdio.h>
#include <stdlib.h>

#include "utils_vecteur.h"

vecteur_t* construit_vecteur(size_t n, double* donnees) {
  vecteur_t* v;

  v = allouer_vecteur(n);
  for (unsigned int i = 0; i < n; i++)
      *acces_vecteur(v, i) = donnees[i];

  return v;
}

void affiche_vecteur(vecteur_t* v) {
  unsigned int taille = taille_vecteur(v);

  printf("[ ");
  for (unsigned int i = 0; i < taille; i++)
      printf("%g ", *acces_vecteur(v, i));
  printf("]\n");
}

vecteur_t* lit_vecteur(char* fichier) {
  vecteur_t* v;
  unsigned int n;
  FILE* f;

  f = fopen(fichier, "r");
  if (!f) {
    fprintf(stderr, "Erreur d'ouverture du fichier de vecteur %s\n", fichier);
    exit(1);
  }
  fscanf(f, " %d", &n);
  v = allouer_vecteur(n);
  v->dynamique = 0;
  for (unsigned int i = 0; i < n; i++) {
    fscanf(f, " %lg", acces_vecteur(v, i));
  }
  fclose(f);

  return v;
}
