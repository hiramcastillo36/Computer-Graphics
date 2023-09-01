#ifndef VERTEX_H
#define VERTEX_H

#pragma once

class Vertex{
    public:
        Vertex(); //constructor default
        Vertex(float vx, float vy, float vz); //constructor
        // ~Vertex(); -> destructor
        void print();
    
    private:
        float x, y, z;
};

#endif