cmake_minimum_required(VERSION 3.26)
project(01_models)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(01_models
        include/Edge.h
        include/Face.h
        include/Vertex.h
        src/Edge.cpp
        src/Face.cpp
        src/Vertex.cpp
        main.cpp)
