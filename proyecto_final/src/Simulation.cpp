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