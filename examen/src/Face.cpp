#include <iostream>
#include <vector>
#include "../include/Face.h"
#include "../include/Line.h"

using namespace std;

Face::Face(vector <Edge> edges){
    this -> edges = edges;
    float distance = 0;

    for(Edge &e: this -> edges){
        Line l(e);
        distance += l.getLongitud();
        this -> lines.push_back(l);
    }

    // nombre del poligono dependiendo del numero de lados
    switch (this -> lines.size()){
        case 3:
            this -> name = "Triangulo";
            break;
        case 4:
            this -> name = "Cuadrilatero";
            break;
        case 5:
            this -> name = "Pentagono";
            break;
        case 6:
            this -> name = "Hexagono";
            break;
        case 7:
            this -> name = "Heptagono";
            break;
        case 8:
            this -> name = "Octagono";
            break;
        default:
            this -> name = "Ngon";
            break;
    }


    this -> perimeter = distance;
}

void Face::print(){
    int i=1;
    for(Edge &e: this -> edges){
        cout<<"Edge_"<<i++<<" = ";
        e.print();
    }
    cout<<endl;
}

float Face::getPerimeter(){
    return this -> perimeter;
}

vector <Edge> Face::getEdges(){
    return this -> edges;
}

string Face::getName(){
    return this -> name;
}