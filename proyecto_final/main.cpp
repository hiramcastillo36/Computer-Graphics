#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale

#include "include/Animation.h"
#include "include/Model.h"
#include "include/OpenGL.h"
#include "include/Simulation.h"
#include "include/Triangle.h"
#include <time.h>    /* time */

using namespace std;

/**
 * @brief 
 *  Main functiond
 * @return int 
 */
int main( void )
{
    OpenGL gl = OpenGL();

    GLFWwindow* window = gl.createWindow( 1024, 500, "Triangle");
    if( window == NULL )
        return -1;

    glfwMakeContextCurrent(window);
    glewExperimental=true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    Model <Ply> ball_sim("models/rock.ply", 1.0, 0.0, 0.0);
    sleep(1);
    Model <Obj> robot_sim("models/kuro.obj", 1.0, 0.0, 1.0);
    sleep(1);
    Model <Obj> enemy_sim("models/avion.obj", 0.0, 0.0, 1.0);
    sleep(1);

	glClearColor(0.0f, 0.0f, 0.0f ,0.0f);
	
    
    
    //Transformaciones
    glm::mat4 scale_earth = glm::scale(glm::mat4(1.0f), glm::vec3(0.2f));
    glm::mat4 translate_earth = glm::translate(glm::mat4(1.0f), glm::vec3(-0.75,0.0f,0.0f));    
    
    glm::mat4 scale_sun = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
    glm::mat4 rotate_sun = glm::rotate(glm::mat4(1.0f), glm::radians(90.0f), glm::vec3(1.0f,0.0f,0.0f));
    glm::mat4 translate_sun = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f,0.0f));

    //Transformation for mars
    glm::mat4 scale_mars = glm::scale(glm::mat4(1.0f), glm::vec3(0.2f));
    glm::mat4 translate_mars = glm::translate(glm::mat4(1.0f), glm::vec3(0.4,0.0f,0.0f));

    //Transformation for moon
    glm::mat4 scale_moon = glm::scale(glm::mat4(1.0f), glm::vec3(0.3f));
    glm::mat4 translate_moon = glm::translate(glm::mat4(1.0f), glm::vec3(0.4,0.0f,0.0f));

    float angle_mars = 0.0f;
    float angle = 0.0f;
    float angle_moon = 0.0f;
    
    Animation an;
    Vertex P1(-0.9,0.9,0.0);
    Vertex P2(-0.5,0.8,0.0);
    Vertex P3(0.3,0.0,0.0);
    Vertex P4(0.7,-0.8,0.0);

// trayectoria de la estrella
    vector<Vertex> star_path = an.bezier(P1, P2, P3, P4, 0.001);

    unsigned int star_position = 0;

    //Transformation for star
    glm::mat4 scale_star = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

    do {
        glm::mat4 rotation_earth = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f,0.1f,0.0f));
        glm::mat4 transform_earth =  rotation_earth * translate_earth * scale_earth;

        if(angle<360.0f){
            angle += 0.5;
        }else{
            angle = 0.0f;
        }

        //Rotation for mars
        glm::mat4 rotation_mars = glm::rotate(glm::mat4(1.0f), glm::radians(angle_mars), glm::vec3(0.0f,0.1f,0.0f));
        glm::mat4 transform_mars = rotation_mars * translate_mars * scale_mars;

        if(angle_mars<360.0f){
            angle_mars += 0.2;
        }else{
            angle_mars = 0.0f;
        }

        //Rotation for moon
        glm::mat4 rotation_moon = glm::rotate(glm::mat4(1.0f), glm::radians(angle_moon), glm::vec3(0.0f,0.1f,0.0f));
        glm::mat4 transform_moon = translate_moon * scale_moon * transform_earth;

        if(angle_moon<360.0f){
            angle_moon += 0.5;
        }else{
            angle_moon = 0.0f;
        }

        glm::mat4 translate_star = glm::translate(glm::mat4(1.0f), glm::vec3(star_path[star_position].getX(), star_path[star_position].getY(), star_path[star_position].getX()));
        glm::mat4 transform_star = translate_star * scale_star;

        if(star_position < star_path.size()-1){
            star_position++;
        }else{
            star_position = 0;
        }

        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        //ball_sim.draw(gl.getProgramID(), translate_sun * scale_sun);
        robot_sim.draw(gl.getProgramID(), transform_earth);
        //enemy_sim.draw(gl.getProgramID(), transform_mars);

        glfwSwapBuffers(window);
        glfwPollEvents();

    } while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );

    return 0;
}
