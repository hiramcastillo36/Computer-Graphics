#ifndef SIMULATION_H
#define SIMULATION_H

#pragma once

#include <iostream>
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
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

    glm::mat4 scale_ball;
    glm::mat4 translate_ball;
    glm::mat4 transform_ball;

    glm::mat4 scale_robot;
    glm::mat4 translate_robot;
    glm::mat4 rotate_robot;
    glm::mat4 transform_robot;

    glm::mat4 scale_enemy;
    glm::mat4 translate_enemy;
    glm::mat4 rotation_enemy;
    glm::mat4 transform_enemy;  

    vector<Vertex> robot_path;
    unsigned int robot_path_index;

};

#endif