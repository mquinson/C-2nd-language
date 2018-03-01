#ifndef UTILS_MATRICE_H
#define UTILS_MATRICE_H

#include <stddef.h>

#include "matrice.h"

matrice *construit_matrice(size_t l, size_t c, double *donnees);
void affiche_matrice(matrice *m);
matrice *lit_matrice(char *fichier);

#endif
