#include "Persona.h"
#include <string>
using namespace std;
#include <iostream>

// Desarrollo constrcutores
Persona::Persona()
{

    _nombre = "" ;
    _apellido = "";
    _fechaDeNacimiento = Fecha();
    _estado = false;
}
Persona :: Persona (string nombre, string apellido, Fecha fechaDeNacimiento, bool Estado)
{

    _nombre=nombre;
    _apellido=apellido;
    _fechaDeNacimiento= fechaDeNacimiento;
    _estado=Estado;
}

// Desarrollo Getter y Setter.
string Persona ::getNombre()
{
    return _nombre;
}

void Persona ::setApellido(string apellido)
{
    _apellido= apellido;

}
bool Persona :: getEstado()
{
    return _estado;
}
void Persona::setEstado(bool Estado)
{
    _estado= 0;
}

Fecha Persona:: getFecaDeNacimiento()
{
    return _fechaDeNacimiento;
}
void Persona :: setFechaDeNacimiento(Fecha fechaDeNacimiento)
{

    _fechaDeNacimiento= fechaDeNacimiento;
}
