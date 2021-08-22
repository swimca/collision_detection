#ifndef CD_RAY_H
#define CD_RAY_H
#include "point.h"
#include "direction.h"

/* represents the ray with origin at point a and passing through point b
 */
struct CDRay {
    struct CDPoint a;
    struct CDPoint b;
};

#endif
