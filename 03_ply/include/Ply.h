//
// Created by Hiram Castillo on 31/08/23.
//

#ifndef PLY_H
#define PLY_H

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"

using namespace std;

class Ply {
    public:
        Ply(string fileName);

    private:
        vector<Vertex> vertices = {};
        vector<Face> faces = {};
        int size_vertices;
        int size_faces;
        string fileName;

        vector<string> split(const string &str, const string &delim);
};


#endif //PLY_H
