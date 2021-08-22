#ifndef CD_TRIANGLE
#define CD_TRIANGLE
#include <stdio.h>
#include "vertex.h"

/* a triangle consists of three references to vertices.  Other triangles
 * may reference the same vertices
 */
struct CDTriangle {
    struct CDVertex *a;
    struct CDVertex *b;
    struct CDVertex *c;
};

void CDTriangle_print(struct CDTriangle *triangle);

#endif
