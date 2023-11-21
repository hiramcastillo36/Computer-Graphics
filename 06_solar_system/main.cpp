#include <iostream>
#include <vector>
#include "include/Animation.h"
#include "include/Vertex.h"

using namespace std;
using namespace arma;

//include definición de clases
//src implementaciones de clases

/**
 * @brief 
 * 
 * @return int 
 */

int main(void) {
    Vertex P1(8, 12, -1);
    Vertex P2(-2, 3, 4);
    Vertex P3(12, -1, 2);
    //traslate the vertex p1, p2, p3 to XZ

    

    Animation an;

    Col<float> P1h = P1.homog();
    Col<float> P2h = P2.homog();
    Col<float> P3h = P3.homog();

    Mat<float> v1p = an.T(-8, -12, 1) * P1h; //traslate a XZ
    Mat<float> v2p = an.T(-8, -12, 1) * P2h; //traslate a XZ
    Mat<float> v3p = an.T(-8, -12, 1) * P3h; //traslate a XZ

    float angle = -77.01;

    v1p = an.Rx(angle) * v1p;
    v2p = an.Rx(angle) * v2p;
    v3p = an.Rx(angle) * v3p;
    
    cout<<"P1: "<<v1p<<endl;
    cout<<"P2: "<<v2p<<endl;
    cout<<"P3: "<<v3p<<endl;

    angle = 15.9;

    v1p = an.Rz(angle) * v1p;
    v2p = an.Rz(angle) * v2p;
    v3p = an.Rz(angle) * v3p;

    cout<<"P1: "<<v1p<<endl;
    cout<<"P2: "<<v2p<<endl;
    cout<<"P3: "<<v3p<<endl;

    return 0;
}   