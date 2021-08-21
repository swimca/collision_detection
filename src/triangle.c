#include "triangle.h"

void CDTriangle_print(struct CDTriangle *triangle) {
    printf("triangle: \n");
    CDVertex_print(triangle->p1);
    CDVertex_print(triangle->p2);
    CDVertex_print(triangle->p3);
}
