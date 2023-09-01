cmake_minimum_required(VERSION 3.26)
project(02_obj)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(src)
include_directories(models)

add_executable(02_obj
        include/Edge.h
        include/Face.h
        include/Vertex.h
        src/Edge.cpp
        src/Face.cpp
        src/Vertex.cpp
        main.cpp
        include/Obj.h
        src/Obj.cpp)
