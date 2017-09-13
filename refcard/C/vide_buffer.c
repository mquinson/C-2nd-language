// Juste pour vérifier que ça marche

#include <stdio.h>

char lit_charactere() {
  char data;
  scanf("%c", &data);

  char c;
  while ((c = getchar()) != '\n' && c != EOF) { }
  return data;
}

int main() {
  printf ("Lu %c\n", lit_charactere());
  printf ("Lu %c\n", lit_charactere());
  printf ("Lu %c\n", lit_charactere());
  return 0;
}
