# collision_detection

This library provides types and functions for working with 3d primitives
and testing for their collision. 

Few tests have been implemented to date, this is very much a work in
progress.

# Getting Started
1. Create a directory for containing build artifacts, named `debug'
   in this example:
```
% mkdir debug
```

2. Run cmake:
```
% cd debug
% cmake ..
% make
```

3. Run the tests:
```
% cd ..
% ./debug/test
```

# Types
The following types have been defined for creating your own 3D values.
* CDPoint - a point in 3D space
* CDVector - a value with direction and magnitude
* CDVertex - a corner of CDTriangle 
* CDRay - a position and a direction
* CDTriangle - a triangle in 3D space comprised of three vertices
* CDMesh - a collection of triangles and the vertices they reference
* CDKDTree - a kd tree that partitions a mesh of triangles
* CDPlane - a distance and a unit normal

# Collision Checks
The following functions have been defined for checking for collisions of
these primitives with each other.
* CDCollision_ray_triangle() - tests whether a ray intersects with a
  triangle and provides the intersection point in the triangle and the
  intersection point in the ray if so.
* CDCollision_ray_plane() - tests whether a ray intersects with a
  plane and provides the intersection point in the triangle and the
  intersection point in the ray if so.
* CDKDTree_ray() - tests whether a ray collides with a kd tree and returns
  the triangle that collides with the ray if so.
