#include <iostream>
#include "include/Model.h"
#include "include/Animation.h"
#include <vector>
#include "include/Vertex.h"
#include <armadillo>
#include <math.h>

using namespace std;
using namespace arma;

//include definición de clases
//src implementaciones de clases

int main() {
    /*
        Animation anm;
        vector <Vertex> lv = anm.line(0.1, Vertex(-3.45, 0.1, -9.8), Vertex(11.24, -0.2, 6.43));

        for(int i = 0; i < lv.size(); i++){
            lv[i].print();
            cout << endl; // debbuging
        }
    */
    /*
    Vertex P1(1, 0, 0);
    Vertex P4(5, 3, 2);
    Vertex R1(3, 3, 0);
    Vertex R4(-1, 5, 1);


    Animation anm;
    // hermite
    vector <Vertex> curva_hermite = anm.hermite(P1, P4, R1, R4, 0.1);

    // bezier
    // Q en funcion de t es un segmento curvo
    // Q(t) = T * MB * GB
    
    vector <Vertex> curva_bezier = anm.bezier(P1, P4, R1, R4, 0.1);

    Animation anm2;

    Vertex v1(2, 4, 6);

    Col<float> v1h = v1.homog();

    Mat<float> v1p = anm2.T(-2.0, -4.0, -6.0) * v1h;
    Mat<float> v1pp = anm2.S(1.0, 2.0, 3.0) * v1h;

    cout << v1p << endl;
    cout << v1pp << endl; 

    Animation an;
    Vertex v1(5, 0, 0);
    Vertex v2(10, 0, 0);
    Col<float> v1h = v1.homog();
    Col<float> v2h = v2.homog();

    Mat<float> Ry1 = an.Ry(180);
    
    Mat<float> v1p = Ry1 * v1h;
    Mat<float> v2p = Ry1 * v2h;

    cout << v1p << endl;
    cout << v2p << endl;*/

    Animation an;

    return 0;
}   