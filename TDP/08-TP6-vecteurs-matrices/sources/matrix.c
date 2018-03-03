#include <stdlib.h>

#include "matrix.h"

/* Private implementation of the matrix datatype */
struct matrix {
  size_t lines_amount;
  size_t row_amount;
  double** data;
  int dynamic;
};

matrix_t* matrix_new(size_t lines_amount, size_t row_amount) {
  matrix_t* m = NULL;
  /* SOLUTION */
  m = malloc(sizeof(*m));
  if (!m)
    abort();

  m->data = malloc(sizeof(*m->data) * lines_amount);
  if (m->data == NULL)
	  abort();
  for (unsigned int i = 0; i < lines_amount; i++) {
    m->data[i] = malloc(sizeof(*m->data[i]) * row_amount);
    if (m->data[i] == NULL)
      abort();
  }

  m->lines_amount = lines_amount;
  m->row_amount = row_amount;
  m->dynamic = 0;
  /* FIN */
  return m;
}

void matrix_delete(matrix_t* m) {
  /* SOLUTION */
  for (unsigned int i = 0; i < m->lines_amount; i++) {
    free(m->data[i]);
  }
  free(m->data);
  free(m);
  /* FIN */
}

double* matrix_celladdr(matrix_t* m, unsigned int i, unsigned int j) {
  double* result = NULL;
  /* SOLUTION */
  if (i < m->lines_amount && j < m->row_amount)
    result = & m->data[i][j];
  else if (m->dynamic == 0)
    result = NULL;
  else {

    if (i >= m->lines_amount) {
      size_t nouveau_l = i + 1;
      m->data = realloc(m->data, nouveau_l * sizeof(*m->data));
      if (m->data == NULL)
        abort();

      for (unsigned int k = m->lines_amount; k < nouveau_l; k++) {
        m->data[k] = malloc(sizeof(*m->data[k]) * m->row_amount);
        if (m->data[k] == NULL)
          abort();
      }

      m->lines_amount = nouveau_l;
    }
    if (j >= m->row_amount) {
      size_t nouveau_c = j + 1;
      for (unsigned int k = 0; k < m->lines_amount; k++) {
        m->data[k] = realloc(m->data[k], nouveau_c * sizeof(*m->data[k]));
        if (m->data[k] == NULL)
          abort();
      }
      m->row_amount = nouveau_c;
    }

    result = & m->data[i][j];
  }
  /* FIN */
  return result;
}

size_t matrix_get_linesamount(const matrix_t* m) {
  size_t result;
  /* SOLUTION */
  result = m->lines_amount;
  /* FIN */
  return result;
}

size_t matrix_get_rowsamount(const matrix_t* m) {
  size_t result;
  /* SOLUTION */
  result = m->row_amount;
  /* FIN */
  return result;
}

void matrix_set_dynamic(matrix_t* m) {
  m->dynamic = 1;
}
