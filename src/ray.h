#ifndef CD_RAY_H
#define CD_RAY_H
#include "position.h"
#include "direction.h"

/* a ray consists of an origin position and a direction along which the
 * ray extends
 */
struct Ray {
    struct CDPosition origin;
    struct CDDirection direction;
};

#endif
