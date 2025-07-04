#include "Persona.h"
#include <string>
using namespace std;
#include <iostream>
#include <cstring>

// Desarrollo constrcutores
Persona::Persona()
{

}
Persona :: Persona (const char* nombre, const char* apellido, Fecha fechaDeNacimiento)
{
    strcpy( _nombre,nombre);
    strcpy( _apellido, apellido);
    _fechaDeNacimiento= fechaDeNacimiento;
    _estado=true;
}

// Desarrollo Getter y Setter.

const char* Persona :: getNombre()
{
    return _nombre;
}

void Persona::setNombre( char nombre[20])
{
    strcpy(this->_nombre, nombre);
}

const char* Persona:: getApellido()
{
    return _apellido;
}

void Persona::setApellido(char apellido[20])
{
    strcpy(this->_apellido, apellido);


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

int Persona::getPosicion()
{
    return _posicion;
}

void Persona::setPosicion(int posicion)
{
    _posicion = posicion;
}




