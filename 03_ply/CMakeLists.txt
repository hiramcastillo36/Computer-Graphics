cmake_minimum_required(VERSION 3.26)
project(03_ply)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(src)
include_directories(models)

add_executable(03_ply
        include/Edge.h
        include/Face.h
        include/Vertex.h
        src/Edge.cpp
        src/Face.cpp
        src/Vertex.cpp
        main.cpp
        include/Ply.h
        src/Ply.cpp
        ../03_ply/main.cpp)
