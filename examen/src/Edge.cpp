#include <iostream>
#include "../include/Edge.h"
using namespace std;

Edge :: Edge(Vertex vi, Vertex vf){
    this -> vi = vi;
    this -> vf = vf;
}

void Edge::print(){
    cout<< "vi: ";
    this -> vi.print();
    cout<< ", vf: ";
    this -> vf.print();
    cout<<endl;
}

float Edge::getDistance(){
    return sqrt(
                    pow(vf.getX() - vi.getX(), 2) +
                    pow(vf.getY() - vi.getY(), 2) +
                    pow(vf.getZ() - vi.getZ(), 2)
                );
}
