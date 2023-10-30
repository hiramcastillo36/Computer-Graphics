//
// Created by Hiram Castillo on 04/09/23.
//

#include "../include/Object.h"
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi
using namespace std;

Object::Object(string fileName, float r, float g, float b) {
    this->fileName = fileName;
    this->r = r;
    this->g = g;
    this->b = b;
}

vector<string> Object::split(const std::string &str, const std::string &delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do{
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }while (pos < str.length() && prev < str.length());
    return tokens;
}

vector <Vertex> Object::getVertices() {
    return vertices;
}

vector <Face> Object::getFaces() {
    return faces;
}

void Object::draw(GLuint programID)
{
    //Transformaciones
    glm::mat4 scale1 = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));

    GLuint MatrixID = glGetUniformLocation(programID, "Transform");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &scale1[0][0]);

    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
    glVertexAttribPointer(
        0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
        3,                  // size
        GL_FLOAT,           // type
        GL_FALSE,           // normalized?
        0,                  // stride
        (void*)0            // array buffer offset
    );
	// 2nd attribute buffer : colors
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, this->colorbuffer);
	glVertexAttribPointer(
		1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
		3,                                // size
		GL_FLOAT,                         // type
		GL_FALSE,                         // normalized?
		0,                                // stride
		(void*)0                          // array buffer offset
	);
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, this->datasize); // Starting from vertex 0; 3 vertices total -> 1 triangle
    glDisableVertexAttribArray(0);
}

void Object::set_data(){
    vector <GLfloat> vertex_buffer_data={};
    vector <GLfloat> color_buffer_data ={};
    

    for(Face face : this->faces){
        for(Edge edge : face.getEdges()){
            vertex_buffer_data.push_back(edge.getVi().getX());
            vertex_buffer_data.push_back(edge.getVi().getY());
            vertex_buffer_data.push_back(edge.getVi().getZ());
            color_buffer_data.push_back(this->r);
            color_buffer_data.push_back(this->g);
            color_buffer_data.push_back(this->b);
        }
    }

    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    glGenBuffers(1, &this->vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, this->vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size()*sizeof(GLfloat), &vertex_buffer_data[0], GL_STATIC_DRAW);
	this->datasize = vertex_buffer_data.size();

	glGenBuffers(1, &this->colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, color_buffer_data.size()*sizeof(GLfloat), &color_buffer_data[0], GL_STATIC_DRAW);
}

