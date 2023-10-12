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
    
    return 0;
}