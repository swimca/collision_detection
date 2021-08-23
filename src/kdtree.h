#ifndef CDKDTREE_H
#define CDKTTREE_H

struct CDKDNode {
    struct KDNode *near;
    struct KDNode *far;
    float split_at;   // p
};

struct CDKTree {
    struct CDKDNode root;
};

void CDKDTree_init(struct CDKDNode *root, struct CDMesh *mesh) {

    // assign each 
    // assign each triangle to the left of the node's split point
    // to the near tree.
}


#endif
