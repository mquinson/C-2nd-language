#include <stdio.h>

#include "matlin.h"
#include "utils_matlin.h"

int main(void) {

  matlin_t* m1 = matlin_read("matrice1.txt");
  matlin_print(m1);
  matlin_delete(m1);

  matlin_t* m2 = matlin_read("matrice2.txt");
  matlin_print(m2);
  matlin_delete(m2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
