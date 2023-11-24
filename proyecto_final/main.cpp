#include <iostream>
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale

#include "include/Animation.h"
#include "include/Model.h"
#include "include/OpenGL.h"
#include "include/Simulation.h"
#include "include/Triangle.h"
 
using namespace std;

//include definición de clases
//src implementaciones de clases

/**
 * @brief 
 *  Main functiond
 * @return int 
 */
int main( void )
{
    OpenGL gl = OpenGL();

    GLFWwindow* window = gl.createWindow( 1024, 768, "Triangle");
    if( window == NULL )
        return -1;

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	glClearColor(0.2f, 0.2f, 0.2f ,0.0f);
	
    Model <Ply> ball_sim("models/rock.ply", 1.0, 0.0, 0.0);

    Triangle tr1(ball_sim.vertex_buffer_data(),
                    ball_sim.color_buffer_data());

    Model <Obj> robot_sim("models/nube.obj", 1.0, 1.0, 0.0);
    Model <Obj> enemy_sim("models/nube.obj", 1.0, 0.0, 0.0);

    Triangle tr2(robot_sim.vertex_buffer_data(),
                    robot_sim.color_buffer_data());
        
    Triangle tr3(enemy_sim.vertex_buffer_data(),
                    enemy_sim.color_buffer_data());

    
    glm::mat4 scale_ball = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
    glm::mat4 translate_ball = glm::translate(glm::mat4(1.0f), glm::vec3(0.2f,0.7f,0.0f));   
    glm::mat4 transform_ball = translate_ball * scale_ball;

    glm::mat4 scale_robot = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
    glm::mat4 translate_robot = glm::translate(glm::mat4(1.0f), glm::vec3(-0.75f,0.0f,0.0f));
    glm::mat4 rotate_robot = glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 transform_robot =  rotate_robot * translate_robot * scale_robot;

    glm::mat4 scale_enemy = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
    glm::mat4 translate_enemy = glm::translate(glm::mat4(1.0f), glm::vec3(0.75f,0.0f,0.0f));
    glm::mat4 rotattion_enemy = glm::rotate(glm::mat4(1.0f), glm::radians(-90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
    glm::mat4 transform_enemy =  rotattion_enemy * translate_enemy * scale_enemy;

    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        //tr1.draw(gl.getProgramID(), transform_robot);

        tr2.draw(gl.getProgramID(), transform_ball);

        //tr3.draw(gl.getProgramID(), transform_enemy);

        glfwSwapBuffers(window);
        glfwPollEvents();

    } while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );

    return 0;
}
