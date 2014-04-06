#include <time.h>
#include <stdio.h>

int main() {
   int res;
   
   /* initialise le generateur pseudo-aleatoire */
   srand(time(NULL));
   
   /* tire un nombre au hasard entre 1 et 6 et l'affiche */
   res = rand() % 6 + 1;
   printf("Tirage aleatoire: %d\n", res);
   
   /* Programme fini avec succes */
   return 0;
}
