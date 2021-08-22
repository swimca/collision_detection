#include "triangle.h"

void CDTriangle_print(struct CDTriangle *triangle) {
    printf("triangle: \n");
    CDVertex_print(triangle->a);
    CDVertex_print(triangle->b);
    CDVertex_print(triangle->c);
}
