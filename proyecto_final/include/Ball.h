#ifndef BALL_H
#define BALL_H

#pragma once

#include "Utils.h"
#include "Model.h"
#include "Ply.h"

using namespace std;

class Ball : public Utils
{
public:
    Ball();
    void load();    
    void draw(GLuint programID);

private:
    Model <Ply> ball;

};

#endif