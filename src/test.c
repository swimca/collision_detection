#include "mesh.h"
#include "ray.h"
#include "collision.h"
#include "vertex.h"
#include "assert.h"
#include "kdtree.h"

int main() {

    // create a mesh on the XY plane centered at the origin with the given
    // width and height and the given number of vertices in the x and y
    // axes
    struct CDMesh mesh;
    CDMesh_create(&mesh, 11, 11, 100.0f, 100.0f);
    CDMesh_print(&mesh);

    // create a ray above the plane and directed down the negative z axis

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
    struct CDRay ray_parallel;
    ray_parallel.origin = (struct CDPoint){0.0f, 0.0f, 0.0f};
    ray_parallel.vector = (struct CDVector){0.0f, 1.0f, 0.0f};

    // verify the ray does not intersect
    float t;
    struct CDPoint intersection;
    assert(false == CDCollision_ray_triangle(&intersection, &t,
                &triangle, &ray_parallel));

    // define a ray that intersects with the triangle and verify the
    // point and vector ray scale are as expected
    struct CDRay ray_intersects;
    ray_intersects.origin = (struct CDPoint){0.1f, 0.1f, 1.0f};
    ray_intersects.vector = (struct CDVector){0.0f, 0.0f, -1.0f};
    assert(true == CDCollision_ray_triangle(&intersection, &t,
                &triangle, &ray_intersects));
    assert(intersection.x == 0.1f && intersection.y == 0.1f &&
            intersection.z == 0.0f);

    // create a plane with a distance from the origin and a unit normal vector
    struct CDPlane plane;
    plane.d = 0.0f;
    plane.n = (struct CDVector) {0.0f, 0.0f, 1.0f};

    // calculate the intersection of the ray with the plane.
    struct CDRay ray;
    ray.origin = (struct CDPoint) {1.0f, 1.0f, 3.0f};
    ray.vector = (struct CDVector) {0.0f, 0.0f, -1.0f};
    assert(CDCollision_ray_plane(&intersection, &t, &plane, &ray));
    printf("t2: %0.3f\n", t);
    printf("intersection2: ");
    CDPoint_print(&intersection);

    // verify intersection of ray pointing away from the plane fails
    struct CDRay ray2;
    ray2.origin = (struct CDPoint) {0.0f, 0.0f, 3.0f};
    ray2.vector = (struct CDVector) {1.0f, 0.0f, 0.0f};
    assert(!CDCollision_ray_plane(&intersection, &t, &plane, &ray2));

    // create a kd tree from the mesh
    struct CDKDTree tree;
    CDKDTree_init(&tree, &mesh);
    //CDKDTree_print(&tree);

    // find the triangle that intersects with the ray in the mesh
    struct CDRay ray3;
    ray3.origin = (struct CDPoint) {21.0f, 21.0f, 3.0f};
    ray3.vector = (struct CDVector) {0.0f, 0.0f, -1.0f};

    struct CDTriangle *result = CDKDTree_ray(&tree, &ray3);
    printf("collided triangle:\n");
    if(result == NULL) {
        printf("no triangle found\n");
    } else {
        CDTriangle_print(result);
    }

    CDKDTree_free(&tree);
    return EXIT_SUCCESS;
}
