#include "../include/Ball.h"

Ball::Ball(){
    this->ball = Model <Ply> ("models/rock.ply", 1.0, 0.0, 0.0);
    ball.setScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.1f)));
    ball.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(1.2f, 0.0f, 0.0f)));
}



void Ball::draw(GLuint programID, glm::mat4 camera)
{
    this->ball.draw(programID, camera);
}