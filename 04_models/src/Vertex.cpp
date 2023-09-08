#include <iostream>
#include "../include/Vertex.h"

using namespace std;

Vertex :: Vertex(){
    this -> x = 0.0;
    this -> y = 0.0;
    this -> z = 0.0;
}

Vertex :: Vertex(float vx, float vy, float vz){
    this -> x = vx;
    this -> y = vy;
    this -> z = vz;
}

void Vertex::print(){
    cout<<"("<< this -> x<<", "<< this -> y<<", "<< this -> z<<")";
}
