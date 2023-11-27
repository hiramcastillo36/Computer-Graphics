#include "../include/Simulation.h"

using namespace std;

/**
 * @brief Construct a new Simulation:: Simulation object
 * 
 */

Simulation::Simulation()
{
    this->scene = Scene();

    this -> camera = this->scene.getCameraPrincipal();

    cout<<"Simulation created"<<endl;
}

/**
 * @brief 
 * This method initializes the simulation.
 * @param GLuint programID 
*/

void Simulation::init(GLuint programID)
{
    ball.draw(programID, camera);   
    robot.draw(programID, camera);
    enemy.draw(programID, camera);  
    ballPoint.draw(programID, camera);
    ballPoint2.draw(programID, camera);  
}

/**
 * @brief 
 * This method changes the camera.
 * @param int camera 
*/

void Simulation::changeCamera(int camera)
{
    if(camera == 1)
    {
        this->camera = this->scene.getCameraPrincipal();
    }
    else if(camera == 2)
    {
        this->camera = this->scene.getCameraY();
    }
    else if(camera == 3)
    {
        this->camera = this->scene.getCameraZ();
    }
}

/**
 * @brief 
 * This method sets the point.
 * @param float x 
 * @param float y 
*/

void Simulation::setPoint(float x, float y)
{
    glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f));
    ballPoint.setTranslate(translate);
}

/**
 * @brief 
 * This method sets the second point.
 * @param float x 
 * @param float y 
*/

void Simulation::setPoint2(float x, float y)
{
    glm::mat4 translate = glm::translate(glm::mat4(1.0f), glm::vec3(x, y, 0.0f));
    ballPoint2.setTranslate(translate);
}