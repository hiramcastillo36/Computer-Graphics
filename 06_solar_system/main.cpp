#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <armadillo>

#include "include/Model.h"
#include "include/Animation.h"
#include "include/Vertex.h"
#include "include/OpenGL.h"
#include "include/Triangle.h"

using namespace std;
using namespace arma;

//include definición de clases
//src implementaciones de clases

/**
 * @brief 
 *  Main function
 * @return int 
 */

int main(void) {
    //Proceso para que funcione la renderizacion
    OpenGL gl = OpenGL(); //Instancia de clase

    //Preparacion de ventana
    GLFWwindow* window = gl.createWindow( 600, 600, "Solar system"); 
    if( window == NULL )
        return -1;

    glfwMakeContextCurrent(window);
    glewExperimental=true;
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
	glClearColor(0.05f, 0.0f, 0.1f ,0.0f); //Color del fondo
	
    Model<Ply> m1("models/rock.ply", 1.0, 1.0, 0.0);
    Model<Ply> m2("models/rock.ply", 0.0, 1.0, 1.0);

    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        m1.draw(gl.getProgramID());
        

        glfwSwapBuffers(window);
        glfwPollEvents();

    } while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );
    return 0;
}   