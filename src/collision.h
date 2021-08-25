#ifndef CD_COLLISION_H
#define CD_COLLISION_H
#include <stdlib.h>
#include <stdbool.h>
#include "mesh.h"
#include "ray.h"
#include "plane.h"

/* Returns true if the given ray collides with the given triangle, or false
 * otherwise.  If there is a collision, the point of intersection and the
 * position on the ray is provided.
 */
bool CDCollision_ray_triangle(struct CDPoint *intersection,
        float *t, struct CDTriangle *triangle, struct CDRay *ray);

/* Returns true if the given ray collides with the given plane, or false
 * otherwise.  If there is a collision, the point of intersection on the plane
 * and the position on the ray is provided.
 */
bool CDCollision_ray_plane(struct CDPoint *intersection,
        float *t, struct CDPlane *plane, struct CDRay *ray);

#endif
