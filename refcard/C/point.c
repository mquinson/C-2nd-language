#include "point.h"
#include <stdlib.h>
#include <stdio.h>

int maxRank = 0;
struct point {
  int rank;
  double x, y;
};  
point_t* point_create(double x, double y) {
  point_t* res = malloc(sizeof(point_t));
  res->rank = maxRank++;
  res->x = x;
  res->y = y;
  return res;
}
void point_free(point_t* p) {
  free(p);
}
point_t* point_add(point_t* p1, point_t* p2) {
  return
     point_create(p1->x + p2->x, p1->y + p2->y);
}
void point_display(point_t* p) {
  printf("%d: %g, %g\n", p->rank, p->x, p->y);
}
