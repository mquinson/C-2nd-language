#include <stdio.h>

#include "matrice.h"
#include "utils_matrice.h"

int main(void) {
  matrix_t* m1 = lit_matrice("matrice1.txt");
  affiche_matrice(m1);
  liberer_matrice(m1);
  matrix_t* m2 = lit_matrice("matrice2.txt");
  affiche_matrice(m2);
  liberer_matrice(m2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
