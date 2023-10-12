//
// Created by Hiram Castillo on 15/09/23.
//

#ifndef INC_05_ANIMATION_ANIMATION_H
#define INC_05_ANIMATION_ANIMATION_H

#pragma once

#include <iostream>
#include <vector>
#include "Vertex.h"

using namespace std;

class Animation {
public:
    Animation();
    vector <Vertex> line(float dt, Vertex v1, Vertex v2);
    vector <Vertex> hermite(Vertex P1, Vertex P4, Vertex R1, Vertex R4, float dt);
private:
};

#endif //INC_05_ANIMATION_ANIMATION_H
