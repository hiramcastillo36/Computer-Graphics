//
// Created by Hiram Castillo on 15/09/23.
//

#include "../include/Animation.h"

Animation::Animation() {

}

vector <Vertex> Animation :: line(float dt, Vertex v1, Vertex v2){
    vector <Vertex> v = {};
    for(float t = 0.0; t <= 1+dt; t += dt) {
        v.push_back(v1 + ((v2 - v1) * t));
    }

    return v;
}