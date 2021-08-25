#include <assert.h>
#include "mesh.h"


/* create a rectangular mesh on the XY plane centered at the origin with the
 * given number of vertices in the X and Y directions where X is to the right
 * and Y is up.  Z points out of the screen.
 */
void CDMesh_create(struct CDMesh *mesh, unsigned long vertices_x,
        unsigned long vertices_y, float size_x, float size_y) {
    assert(vertices_x > 0);
    assert(vertices_y > 0);
    assert(size_x > 0);
    assert(size_y > 0);
    mesh->num_vertices = vertices_y * vertices_x;
    mesh->num_triangles = 2 * (vertices_y-1) * (vertices_x - 1);
    mesh->vertices = malloc(sizeof(struct CDVertex) * mesh->num_vertices);
    mesh->triangles = malloc(sizeof(struct CDTriangle) * mesh->num_triangles);

    float fx = size_x / (vertices_x - 1);
    float fy = size_y / (vertices_y - 1);
    for(size_t vy = 0; vy < vertices_y; vy++) {
        for(size_t vx = 0; vx < vertices_x; vx++) {
            size_t index = vy*vertices_x + vx;
            mesh->vertices[index].p.x = fx * vx - size_x/2.0f;
            mesh->vertices[index].p.y = size_y/2.0f - fy * vy;
            mesh->vertices[index].p.z = 0.0f;
        }
    }

    // initialize the triangles with references to the appropriate vertices
    size_t num_rows = vertices_y - 1;
    size_t num_cols = vertices_x - 1;
    for(size_t row = 0; row < num_rows; row++) {
        for(size_t col = 0; col < num_cols; col++) {
            size_t triangle_a_idx = row * num_cols * 2 + 2 * col;
            size_t triangle_b_idx = triangle_a_idx + 1;
            mesh->triangles[triangle_a_idx].a = &mesh->vertices[row*vertices_x + col];
            mesh->triangles[triangle_a_idx].b = &mesh->vertices[row*vertices_x + col + 1];
            mesh->triangles[triangle_a_idx].c = &mesh->vertices[(row+1)*vertices_x + col + 1];
            mesh->triangles[triangle_b_idx].a = &mesh->vertices[row*vertices_x + col];
            mesh->triangles[triangle_b_idx].b = &mesh->vertices[(row+1)*vertices_x + col + 1];
            mesh->triangles[triangle_b_idx].c = &mesh->vertices[(row+1)*vertices_x + col];
        }
    }
}

void CDMesh_free(struct CDMesh *mesh) {
    free(mesh->triangles);
    free(mesh->vertices);
}

void CDMesh_print(struct CDMesh *mesh) {
    printf("vertices: %lu\n", mesh->num_vertices);
    for(size_t i = 0; i < mesh->num_vertices; i++) {
        CDVertex_print(&mesh->vertices[i]);
    }
    printf("triangles: %lu\n", mesh->num_triangles);
    for(size_t i = 0; i < mesh->num_triangles; i++) {
        CDTriangle_print(&mesh->triangles[i]);
    }
}
