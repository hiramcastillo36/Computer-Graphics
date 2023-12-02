#ifndef MESSAGE_H
#define MESSAGE_H

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

class Message
{
public:
    Message();
    void draw(GLuint programID, glm::mat4 camera, bool status);

private:
    Model <Obj> message;
};

#endif