#include <iostream>
#include "include/Ply.h"
#include "include/Model.h"

using namespace std;

//include definición de clases
//src implementaciones de clases

int main(){
    Model<Ply> model("models/cube.ply");
    Model<Obj> model2("models/cone.obj");
    cout << endl; // debbuging
    return 0;
}