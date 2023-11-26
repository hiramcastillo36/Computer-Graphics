#ifndef ROBOT_H
#define ROBOT_H

#pragma once

#include <iostream>
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/glm.hpp>
#include <GL/glew.h>
#include "Animation.h"
#include "Model.h"
#include "OpenGL.h"
#include "Scene.h"

using namespace std;

/**
 * @brief 
 *  This class is used to create and draw the robot
 */

class Robot {
public:
    Robot();
    void draw(GLuint programID, glm::mat4 camera);

private:
    Model <Ply> robot;
    unsigned int pathIndex = 0;
    vector <Vertex> path;
};

#endif