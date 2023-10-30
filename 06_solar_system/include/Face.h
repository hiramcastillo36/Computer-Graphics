#ifndef FACE_H
#define FACE_H

#pragma once

#include "Edge.h"
#include "iostream"
#include <vector>

using namespace std;

class Face {
    private:
        vector <Edge> edges;

    public:
        Face(vector <Edge> edges); //constructor
        // ~Face(vector <Edge> edges); -> destructor
        void print();
        vector <Edge> getEdges();
};


#endif