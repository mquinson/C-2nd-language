#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  unsigned long seed;

  if (argc < 3)
    {
      fprintf(stderr,"Au moins deux arguments sont necessaires (dimensions de la matrice)\n");
      exit (1);
    }
  int l = atoi(argv[1]);
  int c = atoi(argv[2]);
  if (argc == 4)
      seed = atoi(argv[3]);
  else
      seed = 0;
  srandom(seed);
  printf("%d %d\n",l,c);
  for (int i=0; i<l; i++)
    {
      for (int j=0; j<c; j++)
          printf("%0.1lf ",((double) random())/0x7FFFFFFF*10);
      printf("\n");
    }
  printf("\n");
  return 0;
}
