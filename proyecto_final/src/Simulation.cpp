#include "../include/Simulation.h"

Simulation::Simulation()
{
    this->ball = Model<Ply>("models/ball.ply", 1.0, 0.0, 0.0);
    this->robot = Model<Ply>("models/robot.ply", 1.0, 1.0, 0.0);
    this->enemy = Model<Obj>("models/enemy.obj", 1.0, 0.0, 0.0);

    cout<<"Simulation created"<<endl;
}

void Simulation::init(GLuint programID)
{
    glm::mat4 scale_ball = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
    glm::mat4 translate_ball = glm::translate(glm::mat4(1.0f), glm::vec3(0.2f,0.7f,0.0f));   
    glm::mat4 transform_ball = translate_ball * scale_ball;
    
    glm::mat4 scale_robot = glm::scale(glm::mat4(1.0f), glm::vec3(0.2f));
    glm::mat4 translate_robot = glm::translate(glm::mat4(1.0f), glm::vec3(-0.75f,0.0f,0.0f));
    glm::mat4 rotate_robot = glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 transform_robot =  rotate_robot * translate_robot * scale_robot;

    glm::mat4 scale_enemy = glm::scale(glm::mat4(1.0f), glm::vec3(0.2f));    
    glm::mat4 rotattion_enemy = glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
/*
    Model <Ply> ball_sim("models/ball.ply", 1.0, 0.0, 0.0);
    Model <Ply> robot_sim("models/robot.ply", 1.0, 1.0, 0.0);
    Model <Obj> enemy_sim("models/enemy.obj", 1.0, 0.0, 0.0);
  */  
    ball.draw(programID, transform_ball);   
    robot.draw(programID, transform_robot);
    enemy.draw(programID, scale_enemy);    
}