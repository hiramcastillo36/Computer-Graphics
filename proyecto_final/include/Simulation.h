#ifndef SIMULATION_H
#define SIMULATION_H

#pragma once

#include <iostream>
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale

#include "Animation.h"
#include "Model.h"
#include "OpenGL.h"
#include "Simulation.h"

#include "Robot.h"
#include "Ball.h"
#include "Enemy.h"

using namespace std;

class Simulation
{
public:
    Simulation();
    void init(GLuint programID);

private:
    Model<Ply> robot;
    Model<Ply> ball;
    Model<Obj> enemy;

};

#endif