#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string>
#include <iostream>
#include "fecha.h"

using namespace std;

class Persona
{

    private:

    char _nombre[20];
    char _apellido[20];
    Fecha _fechaDeNacimiento;
    bool _estado;
    int _posicion;

    public:
    Persona();
    Persona ( const char* nombre, const char*  apellido, Fecha fechaDeNacimiento);

    const char* getNombre();
    const char* getApellido();
    Fecha getFecaDeNacimiento();
    bool getEstado();
    int getPosicion();

    void setNombre (char nombre[]);
    void setApellido ( char apellido[]);
    void setEstado (bool estado);
    void setFechaDeNacimiento (Fecha fechaDeNacimiento);
    void setPosicion(int posicion);
};

#endif // PERSONA_H_INCLUDED
