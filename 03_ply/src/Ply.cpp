//
// Created by Hiram Castillo on 31/08/23.
//

#include "Ply.h"
#include "../include/Vertex.h"
#include "../include/Edge.h"
using namespace std;

Ply :: Ply(string fileName) {
    this -> fileName = fileName;
    read_header();
    cout<< "size_vertices: " << size_vertices << endl;
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

void Ply :: read_header() {
    string line;
    ifstream PLYfile(fileName);
    while(getline(PLYfile, line) && line != "end_header") {
        vector <string> elems = split(line, " ");
        // cambiar por switch
        if(!elems.empty()){
            split(line, " ");
            if(elems[0] == "element"){
                if(elems[1] == "vertex"){
                    size_vertices = stoi(elems[2]) ;
                }
                if(elems[1] == "face"){
                    size_faces = stoi(elems[2]) + 1;
                }
            }
        }
    }

    while(getline(PLYfile, line)) {
        if(size_vertices > 0){
            cout<<line<<endl;
            vector <string> elems = split(line, " ");
            Vertex v(stof(elems[0]), stof(elems[1]), stof(elems[2]));
            this -> vertices.push_back(v);
            size_vertices --;
        } else {
            cout<<line<<endl;
            vector <string> elems = split(line, " ");
            unsigned int prev_vertice;
            prev_vertice = stoi(split(elems[1], " ")[0]) ;
            vector <Edge> edges = {};
            vector <string> temp_edges_slides;
            for(int i=2; i<elems.size(); i++){
                temp_edges_slides = split(elems[i], " ");
                unsigned int actual_vertice = stoi(temp_edges_slides[0]);
                Edge e(vertices[prev_vertice], vertices[actual_vertice]);
                prev_vertice = actual_vertice;
                edges.push_back(e);
                cout<<endl;
            }
            Edge e(vertices[prev_vertice], vertices[stoi(split(elems[1], " ")[0]) ]);
            edges.push_back(e);
            Face face(edges);
            this -> faces.push_back(face);
        }
    }
    cout<<endl;
}