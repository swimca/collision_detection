#include <stdio.h>
#include <math.h>
#include "vector.h"
#include "point.h"

void CDVector_from_points(struct CDVector *vector, struct CDPoint *p1,
        struct CDPoint *p2) {
    vector->x = p2->x - p1->x;
    vector->y = p2->y - p1->y;
    vector->z = p2->z - p1->z;
}


void CDVector_cross(struct CDVector *result, struct CDVector *v1,
        struct CDVector *v2) {
    result->x = v1->y*v2->z-v1->z*v2->y;
    result->y = v1->z*v2->x-v1->x*v2->z;
    result->z = v1->x*v2->y-v1->y*v2->x;
}

float CDVector_dot(struct CDVector *v1, struct CDVector *v2) {
    return sqrtf(v1->x*v2->x + v1->y*v2->y + v1->z*v2->z);
}

void CDVector_print(struct CDVector *v) {
    printf("x: %0.3f, y: %0.3f, z: %0.3f\n", v->x, v->y, v->z);
}
