#include <iostream>
#include "include/Model.h"

using namespace std;

//include definición de clases
//src implementaciones de clases

int main() {
    Model<Ply> cube_ply("models/cube.ply");
    Model<Obj> cone_obj("models/cone.obj");

    //duda, es correcto el método getModel()?


        int i = 1;

        for (Face &f: cube_ply.getModel().getFaces()) {
            cout << "Face " << i++ << endl;
            f.print();
        }
        i = 1;
        for (Face &f: cone_obj.getModel().getFaces()) {
            cout << "Face " << i++ << endl;
            f.print();
        }


    cout << endl; // debbuging
    return 0;
}