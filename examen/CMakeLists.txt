cmake_minimum_required(VERSION 3.26)
project(examen)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
include_directories(src)
include_directories(models)

add_executable(examen
        include/Edge.h
        include/Face.h
        include/Vertex.h
        src/Edge.cpp
        src/Face.cpp
        src/Vertex.cpp
        models/cone.ply
        models/cube.ply
        models/cone.obj
        models/cube2.obj
        include/Ply.h
        src/Ply.cpp
        include/Obj.h
        src/Obj.cpp
        include/Object.h
        include/Model.h
        src/Object.cpp
        main.cpp
        include/Animation.h
        src/Animation.cpp
        include/Line.h
        src/Line.cpp
        src/Line.cpp)
