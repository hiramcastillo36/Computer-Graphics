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
#include "Model.h"
#include "Object.h"

using namespace std;

class Ply : public Object {
    public:
        Ply(string fileName);
        void load();

};


#endif //PLY_H
