#include <iostream>
#include <vector>
#include "../include/Face.h"
#include "../include/Edge.h"
using namespace std;

Face::Face(vector <Edge> edges){
    this -> edges = edges;
}

void Face::print(){
    int i=1;
    for(Edge &e: this -> edges){
        cout<<"Edge "<<i++<<" = ";
        e.print();
        cout<<endl;
    }
}