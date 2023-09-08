//
// Created by Hiram Castillo on 04/09/23.
//

#ifndef OBJECT_H
#define OBJECT_H

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"

using namespace std;

class Object {
    public:
        Object(string fileName);
    virtual void load() = 0;

    protected:
        string fileName;
        vector<Vertex> vertices = {};
        vector<Face> faces = {};
        vector <string> split(const string& str, const string& delim);
};


#endif
