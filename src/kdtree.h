#ifndef CDKDTREE_H
#define CDKDTREE_H
#include <stdlib.h>
#include "mesh.h"
#include "ray.h"

enum CDKDAxis {
    CDKD_AXIS_X = 0,
    CDKD_AXIS_Y = 1,
    CDKD_AXIS_Z = 2,
    CDKD_AXIS_SIZE = 3
};

struct CDKDTree {
    struct CDKDNode *nodes;
    struct CDKDElement *elements;
    struct CDKDNode *root;
};

struct CDKDElement {
    struct CDTriangle *triangle;
    struct CDKDElement *next;
};

struct CDKDNode {
    struct CDKDNode *left;
    struct CDKDNode *right;
    enum CDKDAxis axis;
    float split;
    struct CDKDElement *elements;
    size_t num_elements;
};

/* construct a kd tree from a mesh.
 */
void CDKDTree_init(struct CDKDTree *tree, struct CDMesh *mesh);

void CDKDTree_free(struct CDKDTree *tree);

/* find the first triangle that intersects with the given ray
 * in the mesh, or rreturns NULL if no such triangle exists.
 */
struct CDTriangle *CDKDTree_ray(struct CDKDTree *tree,
        struct CDRay *ray);

void CDKDTree_print(struct CDKDTree *tree);

#endif
