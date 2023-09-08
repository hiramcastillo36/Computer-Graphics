//
// Created by Hiram Castillo on 31/08/23.
//

#ifndef INC_02_OBJ_OBJ_H
#define INC_02_OBJ_OBJ_H

#pragma once

#include "Object.h"

class Obj : public Object{
    public:
        Obj(string fileName);
        void load() override;   // se debe agregar override para que se
                                // entienda que es una subclase

};


#endif //INC_02_OBJ_OBJ_H
