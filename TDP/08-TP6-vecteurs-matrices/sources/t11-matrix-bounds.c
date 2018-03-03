#include <stdio.h>

#include "utils_matrix.h"

int main(void) {
  matrix_t* m1 = matrix_read("data_matrix1.txt");
  for (unsigned int i = 0; i < matrix_get_linesamount(m1) + 100; i++) {
    for (unsigned int j = 0; j < matrix_get_rowsamount(m1) + 100; j++)
      if (matrix_celladdr(m1, i, j) == NULL)
        printf("0 ");
      else
        printf("1 ");
    printf("\n");
  }
  matrix_delete(m1);

  matrix_t* m2 = matrix_read("data_matrix2.txt");
  for (unsigned int i = 0; i < matrix_get_linesamount(m2) + 100; i++) {
    for (unsigned int j = 0; j < matrix_get_rowsamount(m2) + 100; j++)
      if (matrix_celladdr(m2, i, j) == NULL)
        printf("0 ");
      else
        printf("1 ");
    printf("\n");
  }
  matrix_delete(m2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
