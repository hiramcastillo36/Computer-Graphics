//
// Created by Hiram Castillo on 15/09/23.
//

#ifndef INC_05_ANIMATION_ANIMATION_H
#define INC_05_ANIMATION_ANIMATION_H

#pragma once

#include <iostream>
#include <vector>
#include "Vertex.h"
#include <armadillo>

using namespace std;
using namespace arma;

/**
    * Clase Animation
    * Se encarga de realizar las animaciones
    * de los objetos
*/

class Animation {
    public:
        Animation();
        vector <Vertex> line(float dt, Vertex v1, Vertex v2);
        vector <Vertex> hermite(Vertex P1, Vertex P4, Vertex R1, Vertex R4, float dt);
        vector <Vertex> bezier(Vertex P1, Vertex P2, Vertex P3, Vertex P4, float dt);
        Mat<float> T (float dx, float dy, float dz);
        Mat<float> S (float sx, float sy, float sz);
        Mat<float> Rx (float theta);
        Mat<float> Ry (float theta);
        Mat<float> Rz (float theta);

};

#endif //INC_05_ANIMATION_ANIMATION_H
