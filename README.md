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

* CDPoint - a point in 3D space
* CDVector - a value with direction and magnitude
* CDVertex - a corner of CDTriangle 
* CDRay - a position and a direction
* CDTriangle - a triangle in 3D space comprised of three vertices
* CDMesh - a collection of triangles and the vertices they reference

# Tests
* CDCollision_ray_triangle() - tests whether a ray intersects with a
  a triangle and returns the intersection point in the triangle and the
  intersection point in the ray if so.
