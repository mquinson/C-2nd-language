#include <stdio.h>
#include <stdlib.h>

#include "utils_vecteur.h"

vector_t* construit_vecteur(size_t n, double* donnees) {
  vector_t* v;

  v = vector_new(n);
  for (unsigned int i = 0; i < n; i++)
      *vector_celladdr(v, i) = donnees[i];

  return v;
}

void vector_print(vector_t* v) {
  unsigned int taille = vector_size(v);

  printf("[ ");
  for (unsigned int i = 0; i < taille; i++)
      printf("%g ", *vector_celladdr(v, i));
  printf("]\n");
}

vector_t* lit_vecteur(char* fichier) {
  vector_t* v;
  unsigned int n;
  FILE* f;

  f = fopen(fichier, "r");
  if (!f) {
    fprintf(stderr, "Erreur d'ouverture du fichier de vecteur %s\n", fichier);
    exit(1);
  }
  fscanf(f, " %d", &n);
  v = vector_new(n);
  v->dynamic = 0;
  for (unsigned int i = 0; i < n; i++) {
    fscanf(f, " %lg", vector_celladdr(v, i));
  }
  fclose(f);

  return v;
}
