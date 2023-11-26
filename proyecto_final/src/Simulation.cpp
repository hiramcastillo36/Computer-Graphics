#include "../include/Simulation.h"

using namespace std;

Simulation::Simulation()
{
    this->scene = Scene();

    this -> camera = this->scene.getCameraPrincipal();

    cout<<"Simulation created"<<endl;
}

void Simulation::init(GLuint programID)
{
    ball.draw(programID, camera);   
    robot.draw(programID, camera);
    enemy.draw(programID, camera);    
}