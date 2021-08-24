#include <stdbool.h>
#include "kdtree.h"
#define MIN_ELEMENTS 10

/* construct a kd tree by partitioning a mesh of triangles.  The
 * kd tree nodes maintain a linked list of pointers to the mesh.
 * When the list is small enough, the kd tree processing stops.
 * The split is the mean of the smallest value of the respective
 * dimension of all the triangles being split.
 */

/* an element in the linked list associated with the node */
// TODO: use median instead of mean
float mean(struct CDKDElement *element, enum CDKDAxis axis) {
    float total = 0.0f;
    float count = 0;
    while(element != NULL) {
        switch(axis) {
            case CDKD_AXIS_X:
                total += element->triangle->a->p.x;
                break;
            case CDKD_AXIS_Y:
                total += element->triangle->a->p.y;
                break;
            case CDKD_AXIS_Z:
                total += element->triangle->a->p.z;
                break;
            default:
                break;
        }
        count++;
        element = element->next;
    }
    return total / count;
}

bool is_left_element(struct CDKDElement *element, float split,
        enum CDKDAxis axis) {
    switch(axis) {
        case CDKD_AXIS_X:
            return element->triangle->a->p.x < split;
        case CDKD_AXIS_Y:
            return element->triangle->a->p.y < split;
        case CDKD_AXIS_Z:
            return element->triangle->a->p.z < split;
        default:
            return false;
    }
}

struct CDKDNode *tree_helper(struct CDKDNode *nodes,
        size_t *num_nodes, struct CDKDElement *elements, size_t num_elements,
        enum CDKDAxis axis) {
    // if there are no elements to be partitioned in the tree,
    // do not add a new node, just return NULL
    if(num_elements == 0) {
        return NULL;
    }
    struct CDKDNode *new_node = &nodes[*num_nodes];

    // initialize the node
    new_node->axis = axis;
    new_node->split = mean(elements, axis);
    *num_nodes = *num_nodes + 1;
    if(num_elements < MIN_ELEMENTS) {
        new_node->elements = elements;
        new_node->num_elements = num_elements;
        return new_node;
    }

    // given a list of the elements we should process, and the axis
    // we should process them on and the split point on the axis,
    // divide the elements into two pools 
    enum CDKDAxis next_axis = (axis + 1) % CDKD_AXIS_SIZE;

    // otherwise, partition the given linked list of elements one
    struct CDKDElement *left_elements = NULL;
    size_t num_left_elements = 0;
    struct CDKDElement *right_elements = NULL;
    size_t num_right_elements = 0;

    // partition the elements list into two separate lists
    while(elements != NULL) {
        if(is_left_element(elements, new_node->split, axis)) {
            struct CDKDElement *prev = left_elements;
            left_elements = elements;
            elements = elements->next;
            left_elements->next = prev;
            num_left_elements++;
        } else {
            struct CDKDElement *prev = right_elements;
            right_elements = elements;
            elements = elements->next;
            right_elements->next = prev;
            num_right_elements++;
        }
    }
    new_node->left = tree_helper(nodes, num_nodes, left_elements,
            num_left_elements, next_axis);
    new_node->right = tree_helper(nodes, num_nodes, right_elements,
            num_right_elements, next_axis);
    return new_node;
}

void CDKDTree_init(struct CDKDTree *tree, struct CDMesh *mesh) {
    tree->nodes = malloc(
            sizeof(struct CDKDNode) * mesh->num_triangles * 2);
    tree->elements = malloc(
            sizeof(struct CDKDElement) * mesh->num_triangles);

    size_t num_nodes = 0; // the root node

    // initialize the elements so they point to triangles and
    // also form a linked list
    for(size_t i = 0; i < mesh->num_triangles; i++) {
        tree->elements[i].triangle = &mesh->triangles[i];
        tree->elements[i].next = &tree->elements[i+1];
    }
    tree->elements[mesh->num_triangles-1].next = NULL;

    // recursively build the kd tree
    tree->root = tree_helper(tree->nodes, &num_nodes, tree->elements,
            mesh->num_triangles, CDKD_AXIS_X);
}

void CDKDTree_free(struct CDKDTree *tree) {
    free(tree->nodes);
    free(tree->elements);
}

struct CDTriangle *CDKDTree_ray(struct CDKDTree *tree,
        struct CDRay *ray) {
    return NULL;
}

void CDKDNode_print(struct CDKDNode *node) {
    printf("axis: %d, split: %0.3f, num_elements: %lu\n",
            node->axis, node->split, node->num_elements);
}

void print_helper(struct CDKDNode *node, size_t depth) {

    for(size_t i = 0; i < depth; i++) {
        printf(" ");
    }
    if(node == NULL) {
        printf("NULL\n");
        return;
    } else {
        CDKDNode_print(node);
    }
    print_helper(node->left, depth+2);
    print_helper(node->right, depth+2);
}

void CDKDTree_print(struct CDKDTree *tree) {
    print_helper(tree->root, 0);
}
