#ifndef UTILS_H
#define UTILS_H

#include "vector.h"

vector_t* vector_build(size_t n, double* donnees);
void vector_print(vector_t* v);
vector_t* lit_vecteur(char* fichier);

#endif
