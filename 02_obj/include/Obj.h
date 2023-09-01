//
// Created by Hiram Castillo on 31/08/23.
//

#ifndef INC_02_OBJ_OBJ_H
#define INC_02_OBJ_OBJ_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"

using namespace std;

class Obj {
    public:
        Obj(string fileName);

    private:
        vector<Vertex> vertices = {};
        vector<Face> faces = {};
        vector <string> split(const string& str, const string& delim);
};


#endif //INC_02_OBJ_OBJ_H
