#ifndef VERTEX_H
#define VERTEX_H

#pragma once

#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

/**
 * @brief
 * This class is used to create vertices.
 */

class Vertex {
public:
    Vertex(); //constructor default
    Vertex(float vx, float vy, float vz); //constructor
    // ~Vertex(); -> destructor
    void print();

    Vertex operator-(Vertex op2);

    Vertex operator+(Vertex op2);

    Vertex operator*(float op2);

    Row<float> row();

    Col<float> homog();

    float getX();

    float getY();

    float getZ();

private:
    float x, y, z;
};

#endif