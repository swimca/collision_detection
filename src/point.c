#include <stdio.h>
#include "point.h"

void CDPoint_print(struct CDPoint *p) {
    printf("position x: %0.3f, y: %0.3f, z: %0.3f\n",
            p->x, p->y, p->z);
}


