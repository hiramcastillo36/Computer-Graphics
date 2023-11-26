#include "../include/Simulation.h"

Simulation::Simulation()
{
    this->ball = Model<Ply>("models/rock.ply", 1.0, 0.0, 0.0);
    this->robot = Model<Ply>("models/robot.ply", 1.0, 0.0, 1.0);
    this->enemy = Model<Obj>("models/enemy2.obj", 0.0, 0.0, 1.0);

    srand (time(NULL));
    float random_enemy = (float)(rand() % 2 + 1)/10;

    this->scale_ball = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
    this->translate_ball = glm::translate(glm::mat4(1.0f), glm::vec3(1.2f,0.0f,0.0f));
    this->transform_ball = translate_ball * scale_ball;

    this->scale_robot = glm::scale(glm::mat4(1.0f), glm::vec3(0.4f));
    this->translate_robot = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f,0.0f,0.0f));
    this->transform_robot =  translate_robot * scale_robot;

    this->scale_enemy = glm::scale(glm::mat4(1.0f), glm::vec3(0.4f));
    this->translate_enemy = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f, random_enemy));
    this->transform_enemy = rotation_enemy * scale_enemy;

    Animation an;

    Vertex P1(-1.0,0.0,0.0);
    Vertex P2(-0.8,0.0,1.5);
    Vertex P3(0.5,0.0,0.5);
    Vertex P4(1.0,0.0,0.0);

    this -> robot_path = an.bezier(P1, P2, P3, P4, 0.009);
    this -> robot_path_index = 0;

    cout<<"Simulation created"<<endl;
}

void Simulation::init(GLuint programID)
{
    this-> translate_robot = glm::translate(glm::mat4(1.0f), glm::vec3(robot_path[robot_path_index].getX(), robot_path[robot_path_index].getY(),robot_path[robot_path_index].getZ()));
    this-> transform_robot = translate_robot * scale_robot;

    if(robot_path_index < robot_path.size()-1){
        robot_path_index++;
    }
    else{
        robot_path_index = 0;
    }

    glm::mat4 View = glm::lookAt(
        glm::vec3(2,1,2), // Camera is at (0,0,2), in World Space
        glm::vec3(-1,0,0), // and looks at the oribgin
        glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float) 1024 / (float) 500, 0.1f, 100.0f);

    glm::mat4 mvp = Projection * View * translate_enemy * scale_enemy;
    glm::mat4 mvp2 = Projection * View * transform_ball;
    glm::mat4 mvp3 = Projection * View * transform_robot;

    ball.draw(programID, mvp2);   
    robot.draw(programID, mvp3);
    enemy.draw(programID, mvp);    
}