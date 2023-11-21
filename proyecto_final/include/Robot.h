#ifndef ROBOT_H
#define ROBOT_H

#pragma once

#include "Utils.h"
#include "Model.h"
#include "Ply.h"

using namespace std;

class Robot : public Utils
{
public:
    Robot();
    void load();
    void draw(GLuint programID);

private:
    Model <Ply> robot;

};

#endif