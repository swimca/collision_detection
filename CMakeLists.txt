cmake_minimum_required(VERSION 3.10)
set(CMAKE_BUILD_TYPE Debug)

# set the project name and version
project(carwars_client VERSION 0.1.0)

# specify the C standard
set (CMAKE_C_STANDARD 11)
set (CMAKE_C_STANDARD_REQUIRED True)

# define the common source files and headers used by all targets
set(COMMON_SOURCES
    src/mesh.c
    src/collision.c
    src/color.c
    src/kdtree.c
    src/point.c
    src/ray.c
    src/vertex.c
    src/vector.c
    src/triangle.c
    src/test.c)

set(COMMON_LIBS
    m)

set(COMMON_DIRS
    /usr/include)

# define linux target
add_executable(
    test
    ${COMMON_SOURCES})
include_directories(${COMMON_DIRS})
target_link_libraries(test ${COMMON_LIBS})
target_compile_options(test PRIVATE -Wall -Wextra -pedantic)

# needed to support profiling
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")

# to support creation of a compilation database for use by youcompleteme
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_include_directories(test PUBLIC "${PROJECT_BINARY_DIR}")
