// Model.h

#ifndef MODEL_H
#define MODEL_H

#include "Obj.h"     // Incluye la definición de la clase Cubo
#include "Ply.h" // Incluye la definición de la clase Triangulo

/**
 * @brief 
 *  This class is used to create models using Obj and Ply.
 * @tparam T 
 */

template<typename T>

class Model : public T {
public:

    Model(string fileName, float r, float g, float b) : T(fileName, r, g, b) {
        // El constructor de Model ahora crea un objeto de tipo Obj usando fileName.
        // Esto es posible porque Obj y Ply heredan de Object, por lo que pueden
        // ser tratados como Object.
    }
    // El constructor de Model ahora crea un objeto de tipo Obj usando fileName.
    // Esto es posible porque Obj y Ply heredan de Object, por lo que pueden
    // ser tratados como Object.
    Model() : T("", 0.0, 0.0, 0.0) {}
};

#endif // MODEL_H