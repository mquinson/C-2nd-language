#include <stdio.h>

#include "matrice.h"
#include "utils_matrice.h"

int main(void) {
  matrix_t* m1 = matrix_read("matrice1.txt");
  matrix_print(m1);
  matrix_delete(m1);
  matrix_t* m2 = matrix_read("matrice2.txt");
  matrix_print(m2);
  matrix_delete(m2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
