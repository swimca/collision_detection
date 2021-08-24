#include <stdbool.h>
#include "vector.h"
#include "collision.h"


bool CDCollision_ray_plane(struct CDPoint *intersection,
        float *t, struct CDPlane *plane, struct CDRay *ray) {
    struct CDVector origin_vector;
    struct CDPoint origin = {0.0f, 0.0f, 0.0f};
    CDVector_from_points(&origin_vector, &origin, &ray->origin);
    *t = (plane->d -CDVector_dot(&plane->n, &origin_vector))
        / CDVector_dot(&plane->n, &ray->vector);

    if(*t >= 0.0f) {
        CDRay_point(intersection, ray, *t);
        return true; 
    }
    return false;
}

bool CDCollision_ray_triangle(struct CDPoint *intersection,
        float *t, struct CDTriangle *triangle, struct CDRay *ray) {

    // a constant used to indicate approximately equal
    const float EPSILON = 0.000001;

    // compute the vectors we use in subsequent calculations
    struct CDVector ab;
    struct CDVector ac;
    CDVector_from_points(&ab, &triangle->a->p, &triangle->b->p);
    CDVector_from_points(&ac, &triangle->a->p, &triangle->c->p);

    struct CDVector h;
    CDVector_cross(&h, &ray->vector, &ac);

    float a = CDVector_dot(&ab, &h);
    if(a > -EPSILON && a < EPSILON) {
        return false;
    }

    float f = 1.0f / a;

    struct CDVector s;
    CDVector_from_points(&s, &triangle->a->p, &ray->origin);

    float u = f * CDVector_dot(&s, &h);
    if(u < 0.0f || u > 1.0f)
        return false;

    struct CDVector q;
    CDVector_cross(&q, &s, &ab);

    float v = f * CDVector_dot(&ray->vector, &q);
    if (v < 0.0 || u + v > 1.0)
        return false;

    // compute the intersection point t, on the line
    *t = f * CDVector_dot(&ac, &q);
    if (*t > EPSILON) {
        CDRay_point(intersection, ray, *t);
        return true;
    }

    // there is a line intersection but not a ray intersection
    return false;
}
