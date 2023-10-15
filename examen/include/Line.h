//
// Created by Hiram Castillo on 20/09/23.
//

#ifndef LINE_H
#define LINE_H

#pragma once

#include "Edge.h"
#include "iostream"
#include <vector>

using namespace std;

class Line {
    private:
        float magnitude;
    public:
        Line(Edge edge); //constructor
        float getLongitud();
};

#endif //LINE_H
