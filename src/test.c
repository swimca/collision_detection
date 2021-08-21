#include "mesh.h"

int main() {

    struct CDMesh mesh;
    CDMesh_create(&mesh, 3, 3, 100.0f, 100.0f);
    CDMesh_print(&mesh);
    return EXIT_SUCCESS;
}
