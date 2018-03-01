#include "memory_operations.h"

void *my_memcpy(void *dst, const void *src, size_t len) {
  void *resultat;
  /* SOLUTION */
  char *destination, *source;

  resultat = dst;
  destination = (char *) dst;
  source = (char *) src;
  while (len--)
      *(destination++) = *(source++);
  /* FIN */
  return resultat;
}

void *my_memmove(void *dst, const void *src, size_t len) {
  void *resultat;
  /* SOLUTION */
  char *destination, *source;

  resultat = dst;
  destination = (char *) dst;
  source = (char *) src;
  if (destination < source)
    my_memcpy(dst, src, len);
  else {
    destination += len;
    source += len;
    while (len--)
      *(--destination) = *(--source);
  }
  /* FIN */
  return resultat;
}

int is_little_endian(void) {
  int resultat;
  /* SOLUTION */
  char *caractere;
  int entier = 1;

  caractere = (char *) &entier;
  resultat = *caractere;
  /* FIN */
  return resultat;
}

int reverse_endianess(int value) {
  int resultat;
  /* SOLUTION */
  char *source, *destination;
  int i;

  source = (char *) &value;
  destination = ((char *) &resultat) + sizeof(int);
  for (i = 0; i < sizeof(int); i++)
      *(--destination) = *(source++);
  /* FIN */
  return resultat;
}
