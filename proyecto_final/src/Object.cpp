//
// Created by Hiram Castillo on 04/09/23.
//

#include "../include/Object.h"

using namespace std;

/**
 * @brief Construct a new Object:: Object object
 * 
 * @param string fileName 
 * @param float r 
 * @param float g 
 * @param float b 
 */


Object::Object(string fileName, float r, float g, float b) {
    this->fileName = fileName;
    this->r = r;
    this->g = g;
    this->b = b;
}


/**
 * @brief 
 * This method split a string with a delimiter.
 * @param str 
 * @param delim 
 * @return vector < string > 
 */

vector<string> Object::split(const std::string &str, const std::string &delim) {
    vector<string> tokens;
    size_t prev = 0, pos = 0;
    do {
        pos = str.find(delim, prev);
        if (pos == string::npos) pos = str.length();
        string token = str.substr(prev, pos - prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    } while (pos < str.length() && prev < str.length());
    return tokens;
}

/**
 * @brief 
 * This method returns the vertices.
 * @return vector < Vertex > 
 */

vector<Vertex> Object::getVertices() {
    return vertices;
}

/**
 * @brief 
 * This method returns the faces.
 * @return vector < Face > 
 */

vector<Face> Object::getFaces() {
    return faces;
}

/**
 * @brief 
 * This method is used to draw the object.
 * @param programID 
 * @param translate 
 */

void Object::draw(GLuint programID, glm::mat4 translate) {
    
    this->transform = translate;

    // Enviar al shader
    GLuint MatrixID = glGetUniformLocation(programID, "Transform");
    glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &this->transform[0][0]);

    // 1rst attribute buffer : vertices
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

    glBindVertexArray(this->vao);
    // Draw the triangle !
    glDrawArrays(GL_TRIANGLES, 0, this->datasize); // Starting from vertex 0; 3 vertices total -> 1 triangle    
}

/**
 * @brief 
 * This method is used to set the data of the object.
 */

void Object::set_data() {
    cout << "Object::set_data()" << endl;
    
    vector<GLfloat> vertex_buffer_data = {};
    vector<GLfloat> color_buffer_data = {};

    cout<<"vertex_buffer_data.size() = "<<vertex_buffer_data.size()<<endl;

    for (Face face: this->faces) {
        vector<Vertex> vertices;
        for (Edge edge: face.getEdges()) {
            Vertex vi = edge.getVi();
            Vertex vf = edge.getVf();
            vertices.push_back(vi);
            vector<float> viVector = vi.getXYZ();
            vertex_buffer_data.push_back(viVector[0]);
            vertex_buffer_data.push_back(viVector[1]);
            vertex_buffer_data.push_back(viVector[2]);
            color_buffer_data.push_back(this->r);
            color_buffer_data.push_back(this->g);
            color_buffer_data.push_back(this->b);
        }
    }

    cout<<"vertex_buffer_data.size() = "<<vertex_buffer_data.size()<<endl;

    glGenVertexArrays(1, &vao);

    
    glGenBuffers(1, &this->vbo);
    glGenBuffers(1, &this->colorbuffer);
    
    glBindVertexArray(this->vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertex_buffer_data.size()*sizeof(GLfloat), &vertex_buffer_data[0], GL_STATIC_DRAW);
	this->datasize = vertex_buffer_data.size();

    glBindVertexArray(this->vao);
	
	glBindBuffer(GL_ARRAY_BUFFER, this->colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, color_buffer_data.size()*sizeof(GLfloat), &color_buffer_data[0], GL_STATIC_DRAW);

    cout<<"vertex_buffer_data.size() = "<<vertex_buffer_data.size()<<endl;
    

    cout << "Object::set_data() end" << endl;

}