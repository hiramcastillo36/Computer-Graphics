#ifndef SIMULATION_H
#define SIMULATION_H

#pragma once

#include <iostream>
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "Robot.h"
#include "Ball.h"
#include "Enemy.h"
#include "Animation.h"
#include "Model.h"
#include "OpenGL.h"
#include "Scene.h"
#include "Ply.h"
#include "Obj.h"
#include "Vertex.h"


using namespace std;

/**
 * @brief 
 *  This class is used to generate the simulation
 */

class Simulation
{
public:
    Simulation();
    void init(GLuint programID);
    void changeCamera(int camera);

private:
    
    Robot robot;
    Ball ball;
    Enemy enemy;

    glm::mat4 camera;
    Scene scene;


};

#endif