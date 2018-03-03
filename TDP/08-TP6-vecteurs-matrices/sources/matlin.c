#include <stdlib.h>

#include "matlin.h"

/* Implementation of the matlin datatype */
struct matlin {
  size_t lines_amount;
  size_t rows_amount;
  double* data;
  int dynamic;
};

matlin_t* matlin_new(size_t lines_amount, size_t rows_amount) {
  matlin_t* m;
  /* SOLUTION */
  m = malloc(sizeof(*m));
  if (m == NULL)
    abort();

  m->data = malloc(sizeof(*m->data) * lines_amount * rows_amount);
  if (m->data == NULL)
    abort();

  m->lines_amount = lines_amount;
  m->rows_amount = rows_amount;
  /* FIN */
  return m;
}

void matlin_delete(matlin_t* m) {
  /* SOLUTION */
  free(m->data);
  free(m);
  /* FIN */
}

double* matlin_celladdr(matlin_t* m, unsigned int i, unsigned int j) {
  double* result = NULL;
  /* SOLUTION */
  if (i < m->lines_amount && j < m->rows_amount)
    result = m->data + i * m->rows_amount + j;
  else if (m->dynamic) {
    size_t new_lines = (i >= m->lines_amount) ? i + 1 : m->lines_amount;
    size_t new_rows = (j >= m->rows_amount) ? j + 1 : m->rows_amount;
    double* new_block = malloc(sizeof(*m->data) * new_lines * new_rows);
    if (!new_block) {
      abort();
    }
    for (unsigned int k = 0; k < m->lines_amount; k++)
      for (unsigned int l = 0; l < m->rows_amount; l++)
        new_block[k * new_rows + l] = m->data[k * m->rows_amount + l];
    free(m->data);
    m->data = new_block;
    m->lines_amount = new_lines;
    m->rows_amount = new_rows;
    result = m->data + i * m->rows_amount + j;

  } else {
    result = NULL;
  }
  /* FIN */
  return result;
}

size_t matlin_get_linesamount(const matlin_t* m) {
  size_t result = 0;
  /* SOLUTION */
  result = m->lines_amount;
  /* FIN */
  return result;
}

size_t matlin_get_rowsamount(const matlin_t* m) {
  size_t result = 0;
  /* SOLUTION */
  result = m->rows_amount;
  /* FIN */
  return result;
}

void matlin_set_dynamic(matlin_t* m) {
  m->dynamic = 1;
}
