#include <stdio.h>
int main(int argc, char** argv) {
  int reponse;
  for (int i=0; i<5; i++) {
    printf("Quelle est la réponse?\n");
    scanf("%d", &reponse);
    if (reponse == 42) {
      printf("Bravo, vous avez trouvé!\n");
      exit(0); // termine le programme
    } else {
      printf("Non, ce n'est pas %d\n", reponse);
    }
  }
  printf("Dommage, c'est perdu\n");
  return 1;
}
