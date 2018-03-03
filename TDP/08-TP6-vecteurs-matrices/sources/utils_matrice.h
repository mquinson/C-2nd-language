#ifndef UTILS_MATRICE_H
#define UTILS_MATRICE_H

#include <stddef.h>

#include "matrice.h"

matrix_t* construit_matrice(size_t l, size_t c, double* donnees);
void affiche_matrice(matrix_t* m);
matrix_t* lit_matrice(char* fichier);

#endif
