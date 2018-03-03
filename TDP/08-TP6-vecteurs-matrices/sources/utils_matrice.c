#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"
#include "utils_matrice.h"

matrix_t* construit_matrice(size_t l, size_t c, double* donnees) {
  matrix_t* m;

  m = allouer_matrice(l, c);
  for (unsigned int i = 0; i < l; i++)
      for (unsigned int j = 0; j < c; j++)
          *acces_matrice(m, i, j) = donnees[i * c + j];
  return m;
}

void affiche_matrice(matrix_t* m) {
  for (unsigned int i = 0; i < nb_lignes_matrice(m); i++) {
    printf("[ ");
    for (unsigned int j = 0; j < nb_colonnes_matrice(m); j++)
      printf("%g ",*acces_matrice(m, i, j));
    printf("]\n");
  }
}

matrix_t* lit_matrice(char* fichier) {
  matrix_t* m;
  size_t l, c;
  FILE* f;

  f = fopen(fichier,"r");
  if (!f) {
    fprintf(stderr,"Erreur d'ouverture du fichier de matrice %s\n", fichier);
    exit(1);
  }
  fscanf(f," %zd %zd", &l, &c);

  m = allouer_matrice(l,c);
  for (unsigned int i = 0; i < l; i++) {
    for (unsigned int j = 0; j < c; j++)
      fscanf(f," %lg", acces_matrice(m, i, j));
  }
  fclose(f);
  return m;
}
