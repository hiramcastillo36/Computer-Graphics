//
// Created by Hiram Castillo on 20/09/23.
//

#include "../include/Line.h"

Line::Line(Edge edge){
    this -> magnitude = edge.getDistance();
}

float Line::getLongitud(){
    return this -> magnitude;
}