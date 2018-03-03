#include <stdio.h>

#include "utils_matrix.h"

int main(void) {
  matrix_t* m1 = matrix_read("data_matrix1.txt");
  matrix_print(m1);
  matrix_delete(m1);

  matrix_t* m2 = matrix_read("data_matrix2.txt");
  matrix_print(m2);
  matrix_delete(m2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
