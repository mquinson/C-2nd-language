#include <stdio.h>
int main(int argc, char **argv) {

  int a[] = {12, 23, 34, 45, 56, 67, 78, 89, 90, 100};
  int *p = a;      

  printf("a: %d\n", *p+2);
  printf("b: %d\n", *(p+2));
  printf("c: %d\n", &p+1);
  printf("d: %d\n", a+3);
  printf("e: %d\n", &a[7]-p);
  printf("f: %d\n", p+(*p-10));
}
