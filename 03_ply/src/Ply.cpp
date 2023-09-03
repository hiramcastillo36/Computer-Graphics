//
// Created by Hiram Castillo on 31/08/23.
//

#include "Ply.h"

Ply :: Ply(string fileName) {
    this -> fileName = fileName;
    string line;
    ifstream PLYfile(this -> fileName);
    vector <string> elems;
    unsigned int prev_vertice;
    // leer el header, obtener el numero de vertices y de caras
    while(getline(PLYfile, line) && line != "end_header") {
        elems = split(line, " ");
        if(!elems.empty()){
            split(line, " ");
            if(elems[0] == "element"){
                if(elems[1] == "vertex"){
                    this -> size_vertices = stoi(elems[2]) ;
                }
                if(elems[1] == "face"){
                    this -> size_faces = stoi(elems[2]) + 1;
                }
            }
        }
    }

    // leer vertices y caras
    while(getline(PLYfile, line)) {
        if(this -> size_vertices > 0){
            elems = split(line, " ");
            Vertex v(stof(elems[0]), stof(elems[1]), stof(elems[2]));
            this -> vertices.push_back(v);
            this -> size_vertices --;
        } else {
            elems = split(line, " ");
            prev_vertice = stoi(split(elems[1], " ")[0]) ;
            vector <Edge> edges = {};
            vector <string> temp_edges_slides;
            for(int i=2; i<elems.size(); i++){
                temp_edges_slides = split(elems[i], " ");
                unsigned int actual_vertice = stoi(temp_edges_slides[0]);
                Edge e(vertices[prev_vertice], vertices[actual_vertice]);
                prev_vertice = actual_vertice;
                edges.push_back(e);
            }
            Edge e(vertices[prev_vertice], vertices[stoi(split(elems[1], " ")[0]) ]);
            edges.push_back(e);
            Face face(edges);
            this -> faces.push_back(face);
        }
    }
}

vector <string> Ply :: split(const string& str, const string& delim){
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