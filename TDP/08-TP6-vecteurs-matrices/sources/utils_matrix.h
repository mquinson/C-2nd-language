#ifndef UTILS_MATRICE_H
#define UTILS_MATRICE_H

#include <stddef.h>

#include "matrix.h"

matrix_t* matrix_build(size_t l, size_t c, double* donnees);
void matrix_print(matrix_t* m);
matrix_t* matrix_read(char* fichier);

#endif
