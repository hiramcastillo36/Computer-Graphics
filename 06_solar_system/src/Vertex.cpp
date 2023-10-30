#include <iostream>
#include <armadillo>
#include "../include/Vertex.h"

using namespace std;
using namespace arma;

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

Vertex Vertex :: operator-(Vertex op2){
    return Vertex(this -> x - op2.x, this -> y - op2.y, this -> z - op2.z);
}

Vertex Vertex :: operator+(Vertex op2){
    return Vertex(this -> x + op2.x, this -> y + op2.y, this -> z + op2.z);
}

Vertex Vertex :: operator*(float op2){
    return Vertex(this -> x * op2, this -> y * op2, this -> z * op2);
}

Row<float> Vertex :: row(){
    Row<float> r = {this -> x, this -> y, this -> z};
    return r;
}

Col<float> Vertex :: homog(){
    Col<float> h = {this -> x, this -> y, this -> z, 1};
    return h;
}

float Vertex :: getX(){
    return this -> x;
}

float Vertex :: getY(){
    return this -> y;
}

float Vertex :: getZ(){
    return this -> z;
}