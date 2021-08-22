#include <stdio.h>
#include "vertex.h"

void CDVertex_print(struct CDVertex *v) {
    printf("vertex ");
    CDPoint_print(&v->p);
    CDColor_print(&v->c);
}
