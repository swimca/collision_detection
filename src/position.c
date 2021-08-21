#include <stdio.h>
#include "position.h"

void CDPosition_print(struct CDPosition *p) {
    printf("position x: %0.3f, y: %0.3f, z: %0.3f\n",
            p->x, p->y, p->z);
}
