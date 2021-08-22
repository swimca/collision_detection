#ifndef CD_VERTEX_H
#define CD_VERTEX_H
#include "color.h"
#include "point.h"

struct CDVertex {
    struct CDPoint p;
    struct CDColor c;
};

void CDVertex_print(struct CDVertex *v);

#endif
