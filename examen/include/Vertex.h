#ifndef VERTEX_H
#define VERTEX_H

#pragma once

class Vertex{
    public:
        Vertex(); //constructor default
        Vertex(float vx, float vy, float vz); //constructor
        // ~Vertex(); -> destructor
        void print();
        Vertex operator-(Vertex op2);
        Vertex operator+(Vertex op2);
        Vertex operator*(float op2);
        float getX();
        float getY();
        float getZ();

private:
        float x, y, z;
};

#endif