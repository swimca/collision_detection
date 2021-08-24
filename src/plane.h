#ifndef CD_PLANE_H
#define CD_PLANE_H
#include "vector.h"

/* a point-normal representation of a plane, where n /dot x = d and x is
 * any point on the plane.
 */
struct CDPlane {
    struct CDVector n; // should always be normalized
    float d;
};
#endif
