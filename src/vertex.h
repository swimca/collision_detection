#ifndef CD_VERTEX_H
#define CD_VERTEX_H
#include "color.h"
#include "position.h"

struct CDVertex {
    struct CDPosition p;
    struct CDColor c;
};

void CDVertex_print(struct CDVertex *v);

#endif
