#include <iostream>
#include "Socio.h"
using namespace std;
#include <cstring>


Socio::Socio(): Persona()
{
}

Socio :: Socio(const char* nombre, const char* apellido, Fecha fechaDeNacimiento, const char* telefono, const char* DNI,const char* direccion,
               const char* mail) : Persona( nombre,apellido, fechaDeNacimiento)
{
    strcpy (_telefono,telefono);
    strcpy (_DNI,DNI);
    strcpy (_direccion,direccion);
    strcpy(_mail,mail);
}


// Getters
const char* Socio::getDireccion()
{
    return _direccion;
}

const char* Socio::getMail()
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
void Socio::setDireccion(const char* direccion)
{
    strncpy(_direccion, direccion, sizeof(_direccion));
    _direccion[sizeof(_direccion)-1] = '\0';
}

void Socio::setMail(const char* mail)
{
    strncpy(_mail, mail, sizeof(_mail));
    _mail[sizeof(_mail)-1] = '\0';
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




