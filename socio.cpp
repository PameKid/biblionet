#include <iostream>
#include "Socio.h"
using namespace std;
#include <cstring>


Socio::Socio(): Persona()
{
}


//Socio :: Socio() : Persona(string nombre, string apellido, Fecha fechaDeNacimiento, bool Estado)

Socio :: Socio(string nombre, string apellido, Fecha fechaDeNacimiento, bool estado, const char* telefono, const char* DNI,string direccion,
               string mail,int codSocio) : Persona( nombre,apellido, fechaDeNacimiento, estado)
{
    strcpy (_telefono,telefono);
    strcpy (_DNI,DNI);
    _direccion=direccion;
    _mail=mail;
    _codSocio=codSocio;

}


// Getters
string Socio::getDireccion()
{
    return _direccion;
}

string Socio::getMail()
{
    return _mail;
}

int Socio::getCodSocio()
{
    return _codSocio;
}

const char* Socio::getTelefono()
{
    return _telefono;
}

const char* Socio::getDNI()
{
    return _DNI;
}

// Setters
void Socio::setDireccion(string direccion)
{
    _direccion = direccion;
}

void Socio::setMail(string mail)
{
    _mail = mail;
}

void Socio::setCodSocio(int codSocio)
{
    _codSocio = codSocio;
}

void Socio::setTelefono(const char* telefono)
{
    strncpy(_telefono, telefono, sizeof(_telefono));
    _telefono[sizeof(_telefono)-1] = '\0';
}

void Socio::setDNI(const char* DNI)
{
    strncpy(_DNI, DNI, sizeof(_DNI));
    _DNI[sizeof(_DNI)-1] = '\0';
}

void Socio::cargarSocio()
{
    cargarPersona();
    cout <<"Ingrese un numero de telefono: ";
    cin.ignore();
    cin.getline(_telefono, 30);
    cout << "Ingrese su numero de DNI: ";
    cin.ignore();
    cin.getline(_DNI, 8);
    cout << "Ingrese un mail: ";
    cin >> _mail;
    cout << "Ingrese una direccion: ";
    cin >> _direccion;
}

void Socio::mostrarInfo()
{

    cout << "Los datos ingresados son los siguientes: " << endl;
    cout << "Nombre del Socio: " << getNombre()<< endl;
    cout << "Apellido Socio: " << getApellido() << endl;
    cout << "Fecha de nacimiento:" << getFecaDeNacimiento().toString()<< endl;
    cout << "Telefono: " << _telefono<< endl;
    cout << "DNI: " << _DNI << endl;
    cout << "Mail: " <<  _mail << endl;
    cout << "Direccion: " << _direccion << endl;
    cout << "Codigo de Socio: "  << _codSocio << endl;
};
