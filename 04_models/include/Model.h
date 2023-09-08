// Model.h

#ifndef MODEL_H
#define MODEL_H

#include "Obj.h"     // Incluye la definición de la clase Cubo
#include "Ply.h" // Incluye la definición de la clase Triangulo

template <typename T>
class Model {
    public:

    Model(string fileName) : fileName(fileName), model(fileName) {}
    // El constructor de Model ahora crea un objeto de tipo Obj usando fileName.
    // Esto es posible porque Obj y Ply heredan de Object, por lo que pueden
    // ser tratados como Object.
    T getModel() { return model; }

protected:
    string fileName;
    T model;
};

#endif // MODEL_H