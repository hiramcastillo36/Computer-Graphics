//
// Created by Hiram Castillo on 31/08/23.
//

#ifndef INC_02_OBJ_OBJ_H
#define INC_02_OBJ_OBJ_H

#pragma once

#include "Object.h"

/**
 * @brief 
 *  This class is used to create objects using the obj file.
 */

class Obj : public Object {
public:
    Obj(string fileName, float r, float g, float b);

    // se debe agregar override para que se
    // entienda que es una subclase
    void load();

};


#endif //INC_02_OBJ_OBJ_H
