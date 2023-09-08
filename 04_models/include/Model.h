// Model.h

#ifndef MODEL_H
#define MODEL_H

#include "Obj.h"     // Incluye la definición de la clase Cubo
#include "Ply.h" // Incluye la definición de la clase Triangulo

template <typename T>
class Model {
    public:

    Model(const std::string& fileName) : fileName(fileName), objecto(fileName) {
        // El constructor de Model ahora crea un objeto de tipo Obj usando fileName.
    }

protected:
    string fileName;
    T objecto;

};

#endif // MODEL_H