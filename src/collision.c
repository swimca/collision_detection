#include <stdbool.h>
#include "vector.h"
#include "collision.h"


void CDCollision_ray_mesh(struct CDPoint *intersection,
        struct CDMesh *mesh, struct CDRay *ray) {
}

bool CDCollision_ray_triangle(struct CDTriangle *triangle, struct CDRay *ray) {

    // a constant used to indicate approximately equal
    const float EPSILON = 0.000001;

    // compute the vectors we use in subsequent calculations
    struct CDVector ab;
    struct CDVector ac;
    struct CDVector qp;
    CDVector_from_points(&ab, &triangle->a->p, &triangle->b->p);
    CDVector_from_points(&ac, &triangle->a->p, &triangle->c->p);
    CDVector_from_points(&qp, &ray->a, &ray->b);
    printf("ab: ");
    CDVector_print(&ab);
    printf("ac: ");
    CDVector_print(&ac);
    printf("qp: ");
    CDVector_print(&qp);

    struct CDVector h;
    CDVector_cross(&h, &qp, &ac);
    printf("h: ");
    CDVector_print(&h);

    float a = CDVector_dot(&ab, &h);
    if(a > -EPSILON && a < EPSILON) {
        return false;
    }
    return true;
}
