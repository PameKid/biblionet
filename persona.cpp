#include "Persona.h"
#include <string>
using namespace std;
#include <iostream>
#include <cstring>

// Desarrollo constrcutores
Persona::Persona()
{
    _fechaDeNacimiento = Fecha();
    _estado = true;
}
Persona :: Persona (const char* nombre, const char* apellido, Fecha fechaDeNacimiento, bool Estado)
{
    strcpy( _nombre,nombre);
    strcpy( _apellido, apellido);
    _fechaDeNacimiento= fechaDeNacimiento;
    _estado=Estado;
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

void Persona::cargarPersona()
{
    cin.ignore();

    cout << "Ingrese Nombre: ";
    cin.getline(_nombre, 20);

    cout << "Ingrese Apellido: ";
    cin.getline(_apellido, 20);

    _fechaDeNacimiento.cargarFecha();
}

void Persona::mostrartInfoPersona()
{
    cout<<endl;
    cout << "Nombre: " <<getNombre()<< endl;
    cout << "Apellido: " << getApellido() << endl;
    cout << "Fecha de nacimiento:" << getFecaDeNacimiento().toString()<< endl;
}

