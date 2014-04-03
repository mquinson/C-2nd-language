#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int i, n;
  unsigned long seed;

  if (argc < 2)
    {
      fprintf(stderr,"Au moins un argument est necessaire (taille du vecteur)\n");
      exit (1);
    }
  n = atoi(argv[1]);
  if (argc == 3)
      seed = atoi(argv[2]);
  else
      seed = 0;
  srandom(seed);
  printf("%d\n",n);
  for (i=0; i<n; i++)
    printf("%0.1lf ",((double) random())/0x7FFFFFFF*10);
  printf("\n");
  return 0;
}
