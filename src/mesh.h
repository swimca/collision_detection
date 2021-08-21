#include <stdlib.h>
#include "triangle.h"
#include "vertex.h"

struct CDMesh {
    struct CDTriangle *triangles;
    size_t num_triangles;
    struct CDVertex *vertices;
    size_t num_vertices;
};

void CDMesh_create(struct CDMesh *mesh, unsigned long vertices_x,
        unsigned long vertices_z, float size_x, float size_z);

void CDMesh_print(struct CDMesh *mesh);
