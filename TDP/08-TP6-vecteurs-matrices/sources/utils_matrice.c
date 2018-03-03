#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"
#include "utils_matrice.h"

matrix_t* matrix_build(size_t l, size_t c, double* donnees) {
  matrix_t* m;

  m = matrix_new(l, c);
  for (unsigned int i = 0; i < l; i++)
      for (unsigned int j = 0; j < c; j++)
          *matrix_celladdr(m, i, j) = donnees[i * c + j];
  return m;
}

void matrix_print(matrix_t* m) {
  for (unsigned int i = 0; i < matrix_get_linesamount(m); i++) {
    printf("[ ");
    for (unsigned int j = 0; j < matrix_get_rowsamount(m); j++)
      printf("%g ",*matrix_celladdr(m, i, j));
    printf("]\n");
  }
}

matrix_t* matrix_read(char* fichier) {
  FILE* f = fopen(fichier,"r");
  if (!f) {
    fprintf(stderr,"Erreur d'ouverture du fichier de matrice %s\n", fichier);
    exit(1);
  }
  size_t l, c;
  fscanf(f," %zd %zd", &l, &c);

  matrix_t* m = matrix_new(l,c);
  for (unsigned int i = 0; i < l; i++) {
    for (unsigned int j = 0; j < c; j++)
      fscanf(f," %lg", matrix_celladdr(m, i, j));
  }
  fclose(f);
  return m;
}
