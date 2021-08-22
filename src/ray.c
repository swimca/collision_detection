#include "ray.h"

void CDRay_point(struct CDPoint *result, struct CDRay *ray, float t) {
    struct CDVector temp;
    CDVector_scale(&temp, &ray->vector, t);
    result->x = ray->origin.x + temp.x;
    result->y = ray->origin.y + temp.y;
    result->z = ray->origin.z + temp.z;
}


