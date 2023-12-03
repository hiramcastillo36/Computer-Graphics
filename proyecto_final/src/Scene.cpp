#include "../include/Scene.h"

/**
 * @brief Construct a new Scene:: Scene object
 * 
 */

Scene::Scene(){
    this->view_principal = glm::lookAt(
        glm::vec3(6,2,6), // Camera is at (0,0,2), in World Space
        glm::vec3(-1,0,0), // and looks at the oribgin
        glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    this->view_z = glm::lookAt(
        glm::vec3(0,0,6), // Camera is at (0,0,2), in World Space
        glm::vec3(0,0,0), // and looks at the oribgin
        glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    this->view_y = glm::lookAt(
        glm::vec3(0,6,-1.3), // Camera is at (0,0,2), in World Space
        glm::vec3(0,0,0), // and looks at the origin
        glm::vec3(0,0, -1)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    this->projection = glm::perspective(glm::radians(45.0f), (float) 1024 / (float) 500, 0.1f, 100.0f);
}

/**
 * @brief 
 * This method returns the principal camera.
 * @return glm::mat4 
 */

glm::mat4 Scene::getCameraPrincipal(){
    return this->projection * this->view_principal;
}

/**
 * @brief 
 * This method returns the camera in the z axis.
 * @return glm::mat4 
 */

glm::mat4 Scene::getCameraZ(){
    return this->projection * this->view_z;
}

/**
 * @brief 
 * This method returns the camera in the y axis.
 * @return glm::mat4 
 */

glm::mat4 Scene::getCameraY(){
    return this->projection * this->view_y;
}
