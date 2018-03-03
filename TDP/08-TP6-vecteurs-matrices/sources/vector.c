#include <stdlib.h>

#include "vector.h"

vector_t* vector_new(size_t size) {
  vector_t* v = NULL;
  /* SOLUTION */
  v = malloc(sizeof(*v));
  if (v == NULL)
    abort();

  v->data = malloc(sizeof(*v->data) * size);
  if (v->data == NULL)
    abort();

  v->size = size;
  /* FIN */
  return v;
}

void vector_delete(vector_t* v) {
  /* SOLUTION */
  free(v->data);
  free(v);
  /* FIN */
}

double* vector_celladdr(vector_t* v, unsigned int i) {
  double* result = NULL;
  /* SOLUTION */
  if (i >= v->size && v->dynamic) {
    result = v->data + i;
    size_t new_size = v->size * 2;
    while (i >= new_size)
    	new_size *= 2;
    double* new_block = realloc(v->data, new_size * sizeof(*v->data));
    if (new_block == NULL) {
    	abort();
    }
    v->data = new_block;
    v->size = new_size;
  }
  if (i < v->size)
	  result = v->data + i;
  else
	  result = NULL;
  /* FIN */
  return result;
}

size_t vector_size(const vector_t* v) {
  size_t resultat = 0;
  /* SOLUTION */
  resultat = v->size;
  /* FIN */
  return resultat;
}

void vector_set_dynamic(vector_t* v) {
  v->dynamic = 1;
}
