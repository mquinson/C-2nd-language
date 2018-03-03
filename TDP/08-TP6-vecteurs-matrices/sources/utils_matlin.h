#ifndef UTILS_MATRICE_H
#define UTILS_MATRICE_H

#include <stddef.h>

#include "matlin.h"

matlin_t* matlin_build(size_t l, size_t c, double* donnees);
void matlin_print(matlin_t* m);
matlin_t* matlin_read(char* fichier);

#endif
