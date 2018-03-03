#include <stdlib.h>

unsigned int free_counter = 0;
unsigned int malloc_counter = 0;

void* my_calloc(size_t nmemb, size_t size) {
  malloc_counter++;

  return calloc(nmemb, size);
}

void* my_malloc(size_t size) {
  malloc_counter++;

  return malloc(size);
}

void my_free(void* ptr) {
  free_counter++;
  free(ptr);
}
