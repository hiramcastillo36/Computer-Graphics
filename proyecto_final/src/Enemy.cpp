#include "../include/Enemy.h"


Enemy::Enemy() : Utils()
{
    this->load();
    this->enemy = Model <Obj> ("models/enemy.obj", 0.0, 0.0, 0.0);
}

void Enemy::load()
{
    cout<<"Loading enemy..."<<endl;
    this->scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.2f));    
    this->translate = glm::translate(glm::mat4(1.0f), glm::vec3(-0.75f,0.0f,0.0f));
    this->rotate = glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    this->transform =  this->rotate * this->translate * this->scale;
}

void Enemy::draw(GLuint programID)
{
    this->enemy.draw(programID, this->transform);
}