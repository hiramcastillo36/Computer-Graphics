#include "../include/Ball.h"

Ball::Ball() : Utils(){
    this->load();
    this->ball = Model <Ply> ("models/ball.ply", 0.0, 0.0, 0.0);
}


void Ball::load()
{
    cout<<"Loading ball..."<<endl;
    this->scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
    this->translate = glm::translate(glm::mat4(1.0f), glm::vec3(0.7f,0.7f,0.0f));
    this->transform = this->translate * this->scale;
}

void Ball::draw(GLuint programID)
{
    this->ball.draw(programID, this->transform);
}