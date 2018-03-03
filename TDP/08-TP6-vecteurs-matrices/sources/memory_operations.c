#include "memory_operations.h"

void* my_memcpy(void* dst, const void* src, size_t len) {
  void* result;
  /* SOLUTION */
  char* destination, *source;

  result = dst;
  destination = (char*) dst;
  source = (char*) src;
  while (len--)
      *(destination++) = *(source++);
  /* FIN */
  return result;
}

void* my_memmove(void* dst, const void* src, size_t len) {
  void* resultat;
  /* SOLUTION */
  char* destination, *source;

  resultat = dst;
  destination = (char*) dst;
  source = (char*) src;
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
  int result;
  /* SOLUTION */
  char* caractere;
  int entier = 1;

  caractere = (char*) &entier;
  result = *caractere;
  /* FIN */
  return result;
}

int reverse_endianess(int value) {
  int result;
  /* SOLUTION */
  char* source, *destination;
  int i;

  source = (char*) &value;
  destination = ((char*) &result) + sizeof(int);
  for (i = 0; i < sizeof(int); i++)
      *(--destination) = *(source++);
  /* FIN */
  return result;
}
