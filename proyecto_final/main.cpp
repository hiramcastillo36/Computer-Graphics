#include <iostream>
#include <vector>
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale

#include "include/Animation.h"
#include "include/Model.h"
#include "include/OpenGL.h"
#include "include/Simulation.h"

using namespace std;

//include definición de clases
//src implementaciones de clases

/**
 * @brief 
 *  Main functiond
 * @return int 
 */

int main() {
    
    //Proceso para que funcione la renderizacion
    OpenGL gl = OpenGL(); //Instancia de clase

    //Preparacion de ventana
    GLFWwindow* window = gl.createWindow( 1024, 768, "Simulación RCJ"); 
    if( window == NULL )
        return -1;

    glfwMakeContextCurrent(window);
    glewExperimental = true; // Needed for core profile
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
	glClearColor(0.5f, 0.5f, 0.5f ,0.0f); //Color del fondo
      
    Simulation simulation;
    
    do {
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

        simulation.init(gl.getProgramID());

        glfwSwapBuffers(window);
        glfwPollEvents();

    } while ( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
        glfwWindowShouldClose(window) == 0 );
        
    return 0;
}   