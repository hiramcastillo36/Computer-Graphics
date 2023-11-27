#include "../include/Ball.h"

/**
 * @brief Construct a new Ball:: Ball object
 * 
 */

Ball::Ball(){
    this->ball = Model <Ply> ("models/rock.ply", 1.0, 0.0, 0.0);
    ball.setScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.1f)));
    ball.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(1.2f, 0.0f, 0.0f)));
}

/**
 * @brief 
 * This method draws the ball.
 * @param programID 
 * @param camera 
 */

void Ball::draw(GLuint programID, glm::mat4 camera)
{
    this->ball.draw(programID, camera);
}

/**
 * @brief 
 * 
 */

void Ball::setTranslate(glm::mat4 translate){
    this->ball.setTranslate(translate);
}