#include <stdbool.h>
#include "vector.h"
#include "collision.h"


void CDCollision_ray_mesh(struct CDPoint *intersection,
        struct CDMesh *mesh, struct CDRay *ray) {
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
    printf("ab: ");
    CDVector_print(&ab);
    printf("ac: ");
    CDVector_print(&ac);
    printf("qp: ");
    CDVector_print(&ray->vector);

    struct CDVector h;
    CDVector_cross(&h, &ray->vector, &ac);
    printf("h: ");
    CDVector_print(&h);

    float a = CDVector_dot(&ab, &h);
    printf("a: %0.3f\n", a);
    if(a > -EPSILON && a < EPSILON) {
        return false;
    }
    float f = 1.0f / a;
    printf("f: %0.3f\n", f);

    struct CDVector s;
    CDVector_from_points(&s, &triangle->a->p, &ray->origin);
    printf("s: ");
    CDVector_print(&s);
    float u = f * CDVector_dot(&s, &h);
    printf("u: %0.3f\n", u);
    if(u < 0.0f || u > 1.0f)
        return false;

    struct CDVector q;
    CDVector_cross(&q, &s, &ab);
    printf("q: ");
    CDVector_print(&q);
    float v = f * CDVector_dot(&ray->vector, &q);
    printf("v: %0.3f\n", v);
    if (v < 0.0 || u + v > 1.0)
        return false;

    // compute the intersection point t, on the line
    *t = f * CDVector_dot(&ac, &q);
    printf("t: %0.3f\n", *t);
    if (*t > EPSILON) {
        CDRay_point(intersection, ray, *t);
        printf("intersection: ");
        CDPoint_print(intersection);
        return true;
    }

    // there is a line intersection but not a ray intersection
    return false;
}
