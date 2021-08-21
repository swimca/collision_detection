#ifndef CD_TRIANGLE
#define CD_TRIANGLE
#include <stdio.h>
#include "vertex.h"

/* a triangle consists of three references to vertices.  Other triangles
 * may reference the same vertices
 */
struct CDTriangle {
    struct CDVertex *p1;
    struct CDVertex *p2;
    struct CDVertex *p3;
};

void CDTriangle_print(struct CDTriangle *triangle);

#endif
