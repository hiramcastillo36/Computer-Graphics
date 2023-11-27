#include "../include/Robot.h"

/**
 * @brief Construct a new Robot:: Robot object
 * 
 */

Robot::Robot() {
    this->robot = Model <Ply> ("models/robot.ply", 1.0, 0.0, 1.0);

    robot.setScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.7f)));
    robot.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(-4.0f, 0.0f, 0.0f)));

    Animation an;

    this->P1 = Vertex (-4.0, 0.0, 0.0);
    this->P2 = Vertex (-0.2, 0.0, -1.5);
    this->P3 = Vertex (0.9, 0.0, 0.5);
    this->P4 = Vertex (4.0, 0.0, 0.0);

    this->t = 0.001;

    this->path = an.bezier(this-> P1, this -> P2, this-> P3, this->P4, 0.009);
    this->pathIndex = 0;

}

/**
 * @brief 
 * This method draws the robot with the animation.
 * @param programID 
 * @param camera 
 */

void Robot::draw(GLuint programID, glm::mat4 camera) {
    
    this->robot.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(path[pathIndex].getX(), path[pathIndex].getY(), path[pathIndex].getZ())));

    if (pathIndex < path.size() - 1) {
        pathIndex++;
    } else {
        pathIndex = 0;
    }

    robot.draw(programID, camera);
}

/**
 * @brief 
 * This method sets the P2 vertex.
 * @param P2 
 */

void Robot::setP2(Vertex P2) {
    Animation an;
    this->P2 = P2;
    this->path = an.bezier(this-> P1, this -> P2, this-> P3, this->P4, 0.003);
}

/**
 * @brief 
 * This method sets the P3 vertex.
 * @param P3 
 */

void Robot::setP3(Vertex P3) {
    this->P3 = P3;
    Animation an;
    this->path = an.bezier(this-> P1, this -> P2, this-> P3, this->P4, 0.009);
}
