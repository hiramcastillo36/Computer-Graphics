//
// Created by Hiram Castillo on 31/08/23.
//

#include "../include/Obj.h"

/**
 * @brief Construct a new Obj:: Obj object
 * 
 * @param string fileName 
 * @param float r 
 * @param float g 
 * @param float b 
 */

Obj::Obj(string fileName, float r, float g, float b) : Object(fileName, r, g, b) {
    this->load();
    this->set_data();
}

/**
 * @brief 
 * This method is used to load in memory the obj file.
 */

void Obj::load() {
    string line;
    ifstream OBJfile(fileName);
    bool isHaveNormals = false;
    cout<<"File name: "<<fileName<<endl;
    // Verificar si el archivo se abrio correctamente
    if (!OBJfile.is_open()) {
        cout << "No se pudo abrir el archivo obj" << endl;
        return;
    }
    while (getline(OBJfile, line)) {
        vector<string> elems = this->split(line, " ");
        if (!elems.empty())
        {
            if(elems[0] == "v")
            {
                float x = stof(elems[1]);
                float y = stof(elems[2]);
                float z = stof(elems[3]);
                Vertex v(x, y, z);
                this->vertices.push_back(v);
            }
                if (elems[0] == "f")
            {
                vector<Edge> edges;
                int n = elems.size() - 1;

                for (int i = 1; i < n; i++)
                {
                    unsigned int vi1 = stoi(split(elems[i], "/")[0]) - 1;
                    unsigned int vi2 = stoi(split(elems[i + 1], "/")[0]) - 1;

                    Edge e(vertices[vi1], vertices[vi2]);
                    edges.push_back(e);
                }

                // Conectamos el último vértice con el primer vértice
                unsigned int vi1 = stoi(split(elems[n], "/")[0]) - 1;
                unsigned int vi2 = stoi(split(elems[1], "/")[0]) - 1;
                Edge e(vertices[vi1], vertices[vi2]);
                edges.push_back(e);

                Face f(edges);
                this->faces.push_back(f);
            }
        }
    }
}