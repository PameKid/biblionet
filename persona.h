#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string>
using namespace std;
#include <iostream>
#include "fecha.h"



class Persona
{

    private:

    string _nombre;
    string _apellido;
    Fecha _fechaDeNacimiento;
    bool _estado;

    public:
    Persona();
    Persona ( string nombre, string apellido, Fecha fechaDeNacimiento, bool estado =false);

    string getNombre();
    string getApellido();
    Fecha getFecaDeNacimiento();
    bool getEstado();

    void setNombre (string nombre);
    void setApellido (string apellido);
    void setEstado (bool estado);
    void setFechaDeNacimiento (Fecha fechaDeNacimiento);
    void cargarPersona();
} ;
        #endif // PERSONA_H_INCLUDED
