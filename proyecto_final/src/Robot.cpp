#include "../include/Robot.h"

Robot::Robot() : Utils() 
{
    this->load();
    this->robot = Model <Ply> ("models/robot.ply", 0.0, 0.0, 0.0);
}


void Robot::load()
{
    cout<<"Loading robot..."<<endl;
    this->scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.2f));
    this->translate = glm::translate(glm::mat4(1.0f), glm::vec3(-0.75f,0.0f,0.0f));
    this->transform =  this->translate * this->scale;
}


void Robot::draw(GLuint programID)
{
    this->robot.draw(programID, this->transform);
}