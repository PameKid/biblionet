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
void Persona:: setNombre(string nombre)
{
    _nombre=nombre;

}
string Persona :: getApellido()
{
    return _apellido;
}

void Persona ::setApellido(string apellido)
{
    _apellido= apellido;

}
bool Persona :: getEstado()
{
    return _estado;
}
void Persona::setEstado(bool estado)
{
    _estado=estado;
}

Fecha Persona:: getFecaDeNacimiento()
{
    return _fechaDeNacimiento;
}

void Persona :: setFechaDeNacimiento(Fecha fechaDeNacimiento)
{
    _fechaDeNacimiento= fechaDeNacimiento;
}

void Persona:: cargarPersona()
{

    cout << "Nombre del socio: " ;
    cin >>  _nombre;
    cout << "Apellido del socio: ";
    cin >> _apellido;
    _fechaDeNacimiento.cargarFecha();

}
