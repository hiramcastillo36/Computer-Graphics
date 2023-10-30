#include <iostream>
#include <vector>
#include "../include/Face.h"

using namespace std;

Face::Face(vector <Edge> edges){
    this -> edges = edges;
}

void Face::print(){
    int i=1;
    for(Edge &e: this -> edges){
        cout<<"Edge_"<<i++<<" = ";
        e.print();
    }
    cout<<endl;
}