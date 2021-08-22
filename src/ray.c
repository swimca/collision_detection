#include "ray.h"

void CDRay_point(struct CDPoint *result, struct CDRay *ray, float t) {
    struct CDVector temp;
    CDVector_scale(&temp, &ray->vector, t);
    result->x = ray->vector.x + temp.x;
    result->y = ray->vector.y + temp.y;
    result->z = ray->vector.z + temp.z;
}


