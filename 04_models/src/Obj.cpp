//
// Created by Hiram Castillo on 31/08/23.
//

#include "../include/Obj.h"

Obj::Obj(string fileName) : Object(fileName) {
    string line;
    ifstream OBJfile(fileName);
    bool isHaveNormals = false;
    // Verificar si el archivo se abrio correctamente
    if (!OBJfile.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    while (getline(OBJfile, line)) {
        vector<string> elems = split(line, " ");
        // cambiar por switch
        if (!elems.empty()) {
            if (elems[0] == "v") {
                float x = stof(elems[1]);
                float y = stof(elems[2]);
                float z = stof(elems[3]);
                Vertex v(x, y, z);
                this->vertices.push_back(v);
            }
            if (elems[0] == "vn") {
                isHaveNormals = true;
            }
            if (elems[0] == "f") {
                //cout << line << endl;
                // -1 porque los indices empiezan en 1 de la lectura de nuestro obj, en el caso de los vectores empiezan en 0
                unsigned int prev_vertice = stoi(split(elems[1], "//")[0]) - 1;
                if (isHaveNormals) {
                    prev_vertice = stoi(split(elems[1], "//")[0]) - 1;
                } else {
                    prev_vertice = stoi(split(elems[1], " ")[0]) - 1;
                }
                vector<Edge> edges = {};
                vector<string> temp_edges_slides;
                for (int i = 2; i < elems.size(); i++) {
                    if (isHaveNormals) {
                        temp_edges_slides = split(elems[i], "//");
                    } else {
                        temp_edges_slides = split(elems[i], " ");
                    }
                    unsigned int actual_vertice = stoi(temp_edges_slides[0]) - 1;
                    Edge e(vertices[prev_vertice], vertices[actual_vertice]);
                    prev_vertice = actual_vertice;
                    edges.push_back(e);
                }
                Edge e(vertices[prev_vertice], vertices[stoi(split(elems[1], "//")[0]) - 1]);
                edges.push_back(e);
                Face face(edges);
                this->faces.push_back(face);
            }
        }
    }
    /*for (int i = 0; i < faces.size(); i++) {
        faces[i].print();
    }*/
}

void Obj::load() {
    cout << "Ply::load()" << endl;
}