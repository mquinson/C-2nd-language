#include <stddef.h>

void* my_calloc(size_t nmemb, size_t size);
void* my_malloc(size_t size);
void my_free(void* ptr);

extern unsigned int malloc_counter;
extern unsigned int free_counter;

#define calloc my_calloc
#define malloc my_malloc
#define free my_free
