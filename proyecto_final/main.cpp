#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "include/OpenGL.h"
#include "include/Simulation.h"

using namespace std;

int key_flag = 0;

//falta implementar
double xpos, ypos;

static void keyboard_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_1 && action == GLFW_PRESS)
        key_flag = 1;
    if (key == GLFW_KEY_2 && action == GLFW_PRESS)
        key_flag = 2;
    if (key == GLFW_KEY_3 && action == GLFW_PRESS)
        key_flag = 3;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) 
    {
       //getting cursor position
       glfwGetCursorPos(window, &xpos, &ypos);
       cout << "Cursor Position at (" << xpos << " : " << ypos << endl;
    }
}


/**
 * @brief 
 *  Main functiond
 * @return int 
 */
int main( void )
{
    OpenGL gl = OpenGL();

    GLFWwindow* window = gl.createWindow( 1000, 500, "Simulation");
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

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glfwSetKeyCallback(window, keyboard_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    Simulation simulation;

    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        
        if(key_flag == 1)
        {
            
            simulation.changeCamera(1);
        }
        else if(key_flag == 2)
        {
            
            simulation.changeCamera(2);
        }
        else if(key_flag == 3)
        {
            
            simulation.changeCamera(3);
        }
        key_flag = 0;
        simulation.init(gl.getProgramID());
        
        glfwSwapBuffers(window);
        glfwPollEvents();

    } while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );

    return 0;
}
