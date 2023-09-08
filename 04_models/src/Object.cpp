//
// Created by Hiram Castillo on 04/09/23.
//

#include "../include/Object.h"
using namespace std;

Object::Object(string fileName) : fileName(fileName) {}

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

void Object::load() {
    cout << "Obj::load()" << endl;
}