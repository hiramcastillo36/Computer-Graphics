//
// Created by Hiram Castillo on 04/09/23.
//

#ifndef OBJECT_H
#define OBJECT_H

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Face.h"
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

class Object {
    public:
        Object(string fileName, float r, float g, float b);
        vector <Vertex> getVertices();
        vector <Face> getFaces();
        virtual void load() = 0;
        void draw(GLuint programID);
        float r, g, b;

    protected:
        string fileName;
        vector<Vertex> vertices = {};
        vector<Face> faces = {};
        vector <string> split(const string& str, const string& delim);
        GLuint vertexbuffer;
        GLuint colorbuffer;
        GLuint datasize;
        void set_data();
        
};


#endif
