#ifndef FACE_H
#define FACE_H

#pragma once

#include "Edge.h"
#include "iostream"
#include <vector>
#include "Line.h"

using namespace std;

class Face {
    private:
        vector <Edge> edges;
        vector <Line> lines;
        int perimeter;
        string name;
    public:
        Face(vector <Edge> edges); //constructor
        // ~Face(vector <Edge> edges); -> destructor
        void print();
        vector <Edge> getEdges();
        float getPerimeter();
        string getName();
};

// pen hep tri tri cua
#endif