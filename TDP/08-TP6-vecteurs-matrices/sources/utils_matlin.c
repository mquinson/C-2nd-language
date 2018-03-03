#include <stdio.h>
#include <stdlib.h>

#include "utils_matlin.h"

matlin_t* matlin_build(size_t l, size_t c, double* donnees) {
  matlin_t* m = matlin_new(l, c);
  for (unsigned int i = 0; i < l; i++)
      for (unsigned int j = 0; j < c; j++)
          *matlin_celladdr(m, i, j) = donnees[i * c + j];
  return m;
}

void matlin_print(matlin_t* m) {
  for (unsigned int i = 0; i < matlin_get_linesamount(m); i++) {
    printf("[ ");
    for (unsigned int j = 0; j < matlin_get_rowsamount(m); j++)
      printf("%g ",*matlin_celladdr(m, i, j));
    printf("]\n");
  }
}

matlin_t* matlin_read(char* fichier) {
  FILE* f = fopen(fichier,"r");
  if (!f) {
    fprintf(stderr,"Erreur d'ouverture du fichier de matrice %s\n", fichier);
    exit(1);
  }

  size_t l, c;
  fscanf(f," %zd %zd", &l, &c);

  matlin_t* m = matlin_new(l,c);
  for (unsigned int i = 0; i < l; i++) {
    for (unsigned int j = 0; j < c; j++)
      fscanf(f," %lg", matlin_celladdr(m, i, j));
  }
  fclose(f);
  return m;
}
