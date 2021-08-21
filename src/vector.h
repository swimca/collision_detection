#ifndef CD_VECTOR_H
#define CD_VECTOR_H
#include "direction.h"

/* a vector is a magnitude and a direction (where the direction is itself a
 * unit vector
 */
struct VCDVector {
    float magnitude;
    struct CDDirection direction;
};

#endif
