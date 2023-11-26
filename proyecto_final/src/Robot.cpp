#include "../include/Robot.h"

/**
 * @brief Construct a new Robot:: Robot object
 * 
 */

Robot::Robot() {
    this->robot = Model <Ply> ("models/robot.ply", 1.0, 0.0, 1.0);

    robot.setScale(glm::scale(glm::mat4(1.0f), glm::vec3(0.4f)));
    robot.setTranslate(glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f, 0.0f, 0.0f)));

    Animation an;

    Vertex P1(-1.0, 0.0, 0.0);
    Vertex P2(-0.2, 0.0, -1.5);
    Vertex P3(0.9, 0.0, 0.5);
    Vertex P4(1.0, 0.0, 0.0);

    this->path = an.bezier(P1, P2, P3, P4, 0.009);
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
