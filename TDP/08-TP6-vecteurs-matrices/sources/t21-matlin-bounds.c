#include <stdio.h>

#include "utils_matlin.h"

int main(void) {
  matlin_t* m1 = matlin_read("matrice1.txt");
  for (unsigned int i = 0; i < matlin_get_linesamount(m1) + 100; i++) {
    for (unsigned int j = 0; j < matlin_get_rowsamount(m1) + 100; j++)
      if (matlin_celladdr(m1, i, j) == NULL)
        printf("0 ");
      else
        printf("1 ");
    printf("\n");
  }
  matlin_delete(m1);

  matlin_t* m2 = matlin_read("matrice2.txt");
  for (unsigned int i = 0; i < matlin_get_linesamount(m2) + 100; i++) {
    for (unsigned int j = 0; j < matlin_get_rowsamount(m2) + 100; j++)
      if (matlin_celladdr(m2, i, j) == NULL)
        printf("0 ");
      else
        printf("1 ");
    printf("\n");
  }
  matlin_delete(m2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
