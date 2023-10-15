#include <iostream>
#include "include/Model.h"
#include "include/Animation.h"
#include <vector>
#include "include/Vertex.h"
#include "include/Face.h"
#include <armadillo>

using namespace std;

//include definición de clases
//src implementaciones de clases

int main() {
    /*
    Animation anm;
    vector <Vertex> lv = anm.line(0.1, Vertex(-3.45, 0.1, -9.8), Vertex(11.24, -0.2, 6.43));

    for(int i = 0; i < lv.size(); i++){
        lv[i].print();
        cout << endl; // debbuging
    }*/

    Model <Obj> cube("models/polygons.obj");


    // Longitud por cada arista de cada cara
    int i = 0;
    for(Face face: cube.getModel().getFaces()){
        cout << "Cara " << ++i << endl;
        cout << "Nombre del poligono " << face.getName() << endl; // "Cara 1
        int j = 0;
        for(Edge edge: face.getEdges()){
            cout << "Arista " << ++j << " ";
            cout << "Longitud: " << edge.getDistance() << endl;
        }

        //perimetro += face.getPerimeter();
    }

    /*
    for(Vertex vertex: cube.getModel().getVertices()){
        vertex.print();
    }
     */
    Animation anm;
    int xp = 5;
    Vertex v1(2, 4, 0);
    Vertex v2(7, 8, 3);

    // x(t) = x1 + t(x2 - x1)
    // y(t) = y1 + t(y2 - y1)
    // z(t) = z1 + t(z2 - z1)

    // x(t) = 2 + t(7 - 2)
    // y(t) = 4 + t(8 - 4)
    // z(t) = 0 + t(3 - 0)

    // L(t) = [ x(t), y(t), z(t) ]

    // L(0) = [ 2, 4, 0 ]

    float t = (xp - v1.getX()) / (v2.getX() - v1.getX());

    float y = v1.getY() + t * (v2.getY() - v1.getY());
    float z = v1.getZ() + t * (v2.getZ() - v1.getZ());

    Vertex v3(xp, y, z);
    cout<<"\n\n";
    // punto de interseccion

    cout << "Punto de interseccion: ";
    v3.print();

    cout << endl; // debbuging

    return 0;
}