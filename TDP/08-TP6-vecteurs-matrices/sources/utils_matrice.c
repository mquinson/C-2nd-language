#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"
#include "utils_matrice.h"

matrice_t *construit_matrice(size_t l, size_t c, double *donnees) {
  matrice_t *m;
  unsigned i, j;

  m = allouer_matrice(l, c);
  for (i = 0; i < l; i++)
      for (j = 0; j < c; j++)
          *acces_matrice(m, i, j) = donnees[i * c + j];
  return m;
}

void affiche_matrice(matrice_t *m) {
  unsigned i,j;

  for (i = 0; i < nb_lignes_matrice(m); i++) {
    printf("[ ");
    for (j = 0; j < nb_colonnes_matrice(m); j++)
      printf("%g ",*acces_matrice(m, i, j));
    printf("]\n");
  }
}

matrice_t *lit_matrice(char *fichier) {
  matrice_t *m;
  unsigned i, j;
  size_t l, c;
  FILE *f;

  f = fopen(fichier,"r");
  if (!f) {
    fprintf(stderr,"Erreur d'ouverture du fichier de matrice %s\n", fichier);
    exit(1);
  }
  fscanf(f," %zd %zd", &l, &c);

  m = allouer_matrice(l,c);
  for (i = 0; i < l; i++) {
    for (j = 0; j < c; j++)
      fscanf(f," %lg", acces_matrice(m, i, j));
  }
  fclose(f);
  return m;
}
