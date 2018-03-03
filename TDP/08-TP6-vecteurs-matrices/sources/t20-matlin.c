#include <stdio.h>

#include "matlin.h"
#include "utils_matlin.h"

int main(void) {

  matlin_t* m1 = lit_matrice("matrice1.txt");
  affiche_matrice(m1);
  liberer_matrice(m1);
  matlin_t* m2 = lit_matrice("matrice2.txt");
  affiche_matrice(m2);
  liberer_matrice(m2);

  printf("Difference malloc/free : %d\n", malloc_counter - free_counter);

  return 0;
}
