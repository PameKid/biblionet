#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string>
using namespace std;
#include <iostream>
#include "fecha.h"



class Persona
{

    private:

    char _nombre[20];
    char _apellido[20];
    Fecha _fechaDeNacimiento;
    bool _estado;

    public:
    Persona();
    Persona ( const char* nombre, const char*  apellido, Fecha fechaDeNacimiento, bool estado =false);

    string getNombre();
    string getApellido();
    Fecha getFecaDeNacimiento();
    bool getEstado();

    void setNombre (char nombre[]);
    void setApellido ( char apellido[]);
    void setEstado (bool estado);
    void setFechaDeNacimiento (Fecha fechaDeNacimiento);
    void cargarPersona();
} ;
        #endif // PERSONA_H_INCLUDED
