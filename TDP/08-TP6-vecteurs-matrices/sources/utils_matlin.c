#include <stdio.h>
#include <stdlib.h>

#include "matlin.h"
#include "utils_matlin.h"

matlin_t* construit_matrice(size_t l, size_t c, double* donnees) {
  matlin_t* m = allouer_matrice(l, c);
  for (unsigned int i = 0; i < l; i++)
      for (unsigned int j = 0; j < c; j++)
          *acces_matrice(m, i, j) = donnees[i * c + j];
  return m;
}

void affiche_matrice(matlin_t* m) {
  for (unsigned int i = 0; i < nb_lignes_matrice(m); i++) {
    printf("[ ");
    for (unsigned int j = 0; j < nb_colonnes_matrice(m); j++)
      printf("%g ",*acces_matrice(m, i, j));
    printf("]\n");
  }
}

matlin_t* lit_matrice(char* fichier) {
  FILE* f = fopen(fichier,"r");
  if (!f) {
    fprintf(stderr,"Erreur d'ouverture du fichier de matrice %s\n", fichier);
    exit(1);
  }

  size_t l, c;
  fscanf(f," %zd %zd", &l, &c);

  matlin_t* m = allouer_matrice(l,c);
  for (unsigned int i = 0; i < l; i++) {
    for (unsigned int j = 0; j < c; j++)
      fscanf(f," %lg", acces_matrice(m, i, j));
  }
  fclose(f);
  return m;
}
