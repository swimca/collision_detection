#ifndef CD_VECTOR_H
#define CD_VECTOR_H
#include "point.h"

/* a vector is a magnitude and a direction.  This is represented as a point
 * whose magnitude is the length of the vector, and whose position
 * represents the direction of the vector.
 */
struct CDVector {
    float x;
    float y;
    float z;
};

void CDVector_from_points(struct CDVector *vector, struct CDPoint *p1,
        struct CDPoint *p2);

float CDVector_dot(struct CDVector *v1, struct CDVector *v2);

void CDVector_cross(struct CDVector *result, struct CDVector *v1,
        struct CDVector *v2);

void CDVector_print(struct CDVector *v);

#endif
