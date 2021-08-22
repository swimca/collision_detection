#ifndef CD_RAY_H
#define CD_RAY_H
#include "point.h"
#include "direction.h"
#include "vector.h"

/* represents the ray with origin at point a and passing through point b
 */
struct CDRay {
    struct CDPoint origin;
    struct CDVector vector;
};

/* compute the point along the ray*/
void CDRay_point(struct CDPoint *result, struct CDRay *ray, float t);
#endif
