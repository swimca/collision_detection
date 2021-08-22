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

// compute p2 - p1 and store the result in the vector
void CDVector_from_points(struct CDVector *vector, struct CDPoint *p1,
        struct CDPoint *p2);

float CDVector_dot(struct CDVector *v1, struct CDVector *v2);

void CDVector_cross(struct CDVector *result, struct CDVector *v1,
        struct CDVector *v2);

void CDVector_print(struct CDVector *v);

void CDVector_subtract(struct CDVector *result, struct CDVector *v1,
        struct CDVector *v2);

void CDVector_scale(struct CDVector *result, struct CDVector *in,
        float scale);

void CDVector_scale(struct CDVector *result, struct CDVector *in,
        float scale);

void CDVector_add(struct CDVector *result, struct CDVector *v1,
        struct CDVector *v2);
#endif
