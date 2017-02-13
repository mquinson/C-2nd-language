#include "point.h"

int main(int argc, char** argv) {
  point_t* p1 = point_create(10, 20);
  point_t* p2 = point_create(20, 40);
  point_t* total = point_add(p1, p2);
  point_display(total);
  point_free(p1);
  point_free(p2);
  point_free(total);
}
