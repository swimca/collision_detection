#include "mesh.h"
#include "ray.h"
#include "collision.h"
#include "vertex.h"
#include "assert.h"

int main() {

    // create a mesh on the XY plane centered at the origin with the given
    // width and height and the given number of vertices in the x and y
    // axes
    struct CDMesh mesh;
    CDMesh_create(&mesh, 3, 3, 100.0f, 100.0f);
    CDMesh_print(&mesh);

    // create a ray above the plane and directed down the negative z axis
    struct CDRay ray;

    // populate an array of triangle pointers that contain the triangles in
    // the mesh that intersect with the ray
    struct CDPoint intersection;
    CDCollision_ray_mesh(&intersection, &mesh, &ray);

    // test intersection of a ray and a triangle
    
    // define a triangle on the xy plane
    struct CDVertex triangle_vertices[3];
    triangle_vertices[0].p = (struct CDPoint){0.0f, 0.0f, 0.0f};
    triangle_vertices[1].p = (struct CDPoint){0.0f, 1.0f, 0.0f};
    triangle_vertices[2].p = (struct CDPoint){1.0f, 0.0f, 0.0f};
    struct CDTriangle triangle;
    triangle.a = &triangle_vertices[0];
    triangle.b = &triangle_vertices[1];
    triangle.c = &triangle_vertices[2];

    // define a ray that is on the same plane as the triangle
    ray.origin = (struct CDPoint){0.0f, 0.0f, 0.0f};
    ray.vector = (struct CDVector){0.0f, 1.0f, 0.0f};

    // verify the ray does not intersect
    float t;
    assert(false == CDCollision_ray_triangle(&intersection, &t,
                &triangle, &ray));

    // define a ray that is not on the same plane as the triangle
    struct CDRay ray2;
    ray2.origin = (struct CDPoint){0.0f, 0.0f, 1.0f};
    ray2.vector = (struct CDVector){0.0f, 0.0f, 1.0f};

    // verify the ray does not intersect
    assert(true == CDCollision_ray_triangle(&intersection, &t, &triangle,
                &ray2));

    return EXIT_SUCCESS;
}
