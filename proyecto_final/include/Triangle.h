#ifndef TRIANGLE_H
#define TRIANGLE_H

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>
#include <string>

#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4

using namespace std;

/**
 * @brief 
 *  This class is used to create the window and load the shaders.
 */

class Triangle {
public:
    Triangle(vector<GLfloat> vertex_buffer_data, vector<GLfloat> color_buffer_data);

    void draw(GLuint programID,glm::mat4 transform);

private:
    GLuint vertexbuffer;
    GLuint colorbuffer;
    GLuint datasize;
};

#endif