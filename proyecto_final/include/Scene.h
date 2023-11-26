#ifndef SCENE_H
#define SCENE_H

#pragma once

#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <glm/gtc/matrix_transform.hpp>

class Scene
{
public:
    Scene();

    glm::mat4 getCameraPrincipal();
    glm::mat4 getCameraZ();
    glm::mat4 getCameraY();
    
private:
    glm::mat4 view_principal;
    glm::mat4 view_z;
    glm::mat4 view_y;
    glm::mat4 projection;
};

#endif