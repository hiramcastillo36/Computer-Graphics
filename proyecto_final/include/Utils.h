#ifndef UTILS_H
#define UTILS_H

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

#include "Object.h"
#include "Model.h"
#include "Ply.h"
#include "Obj.h"

using namespace std;

class Utils
{
public:
    virtual void load() = 0;
    virtual void draw(GLuint programID) = 0;
protected:
    glm::mat4 scale;
    glm::mat4 translate;
    glm::mat4 rotate;
    glm::mat4 transform;

public:
    void setScale(float x, float y, float z);
    void setTranslate(float x, float y, float z);
    void setTransform(glm::mat4 scale, glm::mat4 translate);
    glm::mat4 getTransform();

};

#endif