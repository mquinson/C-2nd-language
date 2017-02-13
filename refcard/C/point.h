#ifndef POINT_H
#define POINT_H

typedef struct point point_t; // implem cachée

point_t *point_create(double x, double y);
void point_free(point_t* p);

point_t* point_add(point_t* p1, point_t* p2);
void point_display(point_t* p);
#endif /* POINT_H */
