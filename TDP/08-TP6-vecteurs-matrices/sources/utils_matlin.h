#ifndef UTILS_MATRICE_H
#define UTILS_MATRICE_H

#include <stddef.h>

#include "matlin.h"

matlin_t* construit_matrice(size_t l, size_t c, double* donnees);
void affiche_matrice(matlin_t* m);
matlin_t* lit_matrice(char* fichier);

#endif
