#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "include/Vertex.h"
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

    GLFWwindow* window = gl.createWindow( 1024, 500, "Simulation");
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
/*
    Model <Ply> ball_sim("models/rock.ply", 1.0, 0.0, 0.0);
    Model <Ply> robot_sim("models/robot.ply", 1.0, 0.0, 1.0);
    Model <Obj> enemy_sim("models/enemy2.obj", 0.0, 0.0, 1.0);

	glClearColor(0.0f, 0.0f, 0.0f ,0.0f);
	
    srand (time(NULL));
    float random_enemy = (float)(rand() % 2 + 1)/10;
    cout << random_enemy << endl;

    //Transformaciones
    glm::mat4 scale_robot = glm::scale(glm::mat4(1.0f), glm::vec3(0.4f));
    glm::mat4 translate_robot = glm::translate(glm::mat4(1.0f), glm::vec3(-1.0f,0.0f,0.0f));    
    
    // ball
    glm::mat4 scale_enemy = glm::scale(glm::mat4(1.0f), glm::vec3(0.4f));
    glm::mat4 translate_ball = glm::translate(glm::mat4(1.0f), glm::vec3(1.2f,0.0f,0.0f));

    // enemy
    //Transformation for ball
    glm::mat4 scale_ball = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));
    glm::mat4 translate_enemy = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f,0.0f, random_enemy));
    
    Animation an;

    Vertex P1(-1.0,0.0,0.0);
    Vertex P2(-0.8,0.0,1.5);
    Vertex P3(0.5,0.0,0.5);
    Vertex P4(1.0,0.0,0.0);

    vector<Vertex> robot_path = an.bezier(P1, P2, P3, P4, 0.009);

    unsigned int star_position = 0;
*/
/*
    // Desde arriba
    glm::mat4 View = glm::lookAt(
        glm::vec3(0,2,0), // Camera is at (0,0,2), in World Space
        glm::vec3(0,0,0), // and looks at the origin
        glm::vec3(0,0, -1)  // Head is up (set to 0,-1,0 to look upside-down)
    );
    // Desde abajo
    
    glm::mat4 View = glm::lookAt(
        glm::vec3(2,1,1), // Camera is at (0,0,2), in World Space
        glm::vec3(0,0,0), // and looks at the oribgin
        glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    glm::mat4 View = glm::lookAt(
        glm::vec3(0,0,2), // Camera is at (0,0,2), in World Space
        glm::vec3(0,0,0), // and looks at the origingggggggggg
        glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
    */
/*
    glm::mat4 View = glm::lookAt(
        glm::vec3(2,1,2), // Camera is at (0,0,2), in World Space
        glm::vec3(-1,0,0), // and looks at the oribgin
        glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
    );

    glm::mat4 Projection = glm::perspective(glm::radians(45.0f), (float) 1024 / (float) 500, 0.1f, 100.0f);

    //Rotation for ball
    
    glm::mat4 transform_ball = translate_ball * scale_ball;
*/
    Simulation simulation;
    do {
        
/*
        glm::mat4 translate_robot = glm::translate(glm::mat4(1.0f), glm::vec3(robot_path[star_position].getX(), 0.0, robot_path[star_position].getZ()));
        glm::mat4 transform_robot = translate_robot * scale_robot;

        //cout<<robot_path[star_position].getX()<<" "<<robot_path[star_position].getY()<< " " << robot_path[star_position].getZ()<<endl;

        if(star_position < robot_path.size() - 1)
            star_position++;
        else
            star_position = 0;

        // Clear the screen
        
        glm::mat4 mvp = Projection * View * translate_enemy * scale_enemy;
        glm::mat4 mvp2 = Projection * View * transform_ball;
        glm::mat4 mvp3 = Projection * View * transform_robot;
        ball_sim.draw(gl.getProgramID(), mvp2);
        robot_sim.draw(gl.getProgramID(), mvp3);
        enemy_sim.draw(gl.getProgramID(), mvp);
*/
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        simulation.init(gl.getProgramID());
        glfwSwapBuffers(window);
        glfwPollEvents();

    } while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );

    return 0;
}
