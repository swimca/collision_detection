#ifndef CD_COLLISION_H
#define CD_COLLISION_H
#include <stdlib.h>
#include <stdbool.h>
#include "mesh.h"
#include "ray.h"

/* Set the pointer to the triangle that the ray intersects with in the
 * given mesh.  The pointer will be set to NULL if the ray does not intersect
 * the mesh.
 */
void CDCollision_ray_mesh(struct CDPoint *intersection,
        struct CDMesh *mesh, struct CDRay *ray);

/* Returns true if the given ray collides with the given triangle, or false
 * otherwise.
 */
bool CDCollision_ray_triangle(struct CDTriangle *triangle, struct CDRay *ray);
#endif
