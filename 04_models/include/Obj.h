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
#include "Model.h"
#include "Object.h"
#include "Model.h"

using namespace std;

class Obj : public Object{
    public:
        Obj(string fileName);
        void load() override;

};


#endif //INC_02_OBJ_OBJ_H
