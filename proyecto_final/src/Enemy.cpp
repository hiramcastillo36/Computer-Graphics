#include "../include/Enemy.h"


Enemy::Enemy()
{
    this->enemy = Model <Obj> ("models/enemy2.obj", 0.0, 0.0, 1.0);

    srand (time(NULL));
    float random_enemy = (float)(rand() % 2 + 1)/10;

    enemy.setScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.4f)));
    enemy.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f, random_enemy)));
}

void Enemy::draw(GLuint programID, glm::mat4 camera)
{
    this->enemy.draw(programID, camera);
}

