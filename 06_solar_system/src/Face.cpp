#include "../include/Face.h"

using namespace std;

/**
 * @brief Construct a new Face:: Face object
 * 
 * @param vector < Edge > 
 */

Face::Face(vector <Edge> edges){
    this -> edges = edges;
}

/**
 * @brief 
 * This method prints the face.
 */

void Face::print(){
    int i=1;
    for(Edge &e: this -> edges){
        cout<<"Edge_"<<i++<<" = ";
        e.print();
    }
    cout<<endl;
}

/**
 * @brief 
 * This method returns the edges of the face.
 * @return vector <Edge> 
 */

vector <Edge> Face::getEdges(){
    return this -> edges;
}