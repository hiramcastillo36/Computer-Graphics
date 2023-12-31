//
// Created by Hiram Castillo on 04/09/23.
//

#ifndef OBJECT_H
#define OBJECT_H

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <glm/vec3.hpp> // glm::vec3
//#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
//#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

using namespace std;

/**
 * @brief 
 *  This class is used to create objects using vertices and faces.
 */

class Object {
public:
    Object(string fileName, float r, float g, float b);

    vector<Vertex> getVertices();

    vector<Face> getFaces();

    virtual void load() = 0;

    void draw(GLuint programID, glm::mat4 transform);

    float r, g, b;

protected:
    string fileName;
    vector<Vertex> vertices = {};
    vector<Face> faces = {};

    vector<string> split(const string &str, const string &delim);

    GLuint vertexbuffer;
    GLuint colorbuffer;
    GLuint datasize;
    GLuint MatrixID;
    glm::mat4 transform;

    void set_data();

};


#endif
