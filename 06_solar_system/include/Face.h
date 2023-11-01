#ifndef FACE_H
#define FACE_H

#pragma once

#include "Edge.h"
#include "iostream"
#include <vector>

using namespace std;

/**
 * @brief 
 *  This class is used to create faces using edges.
 */

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