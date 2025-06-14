#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED
#include "Persona.h"
#include <string>
#include <iostream>

using namespace std;

class Socio : public Persona
{

private:
    char _telefono [30];
    char _DNI [9];
    char _direccion[50];
    char _mail[30];
    int _codSocio;


public:
    Socio();
    Socio(const char* nombre, const char* apellido, Fecha fechaDeNacimiento, const char* telefono, const char* DNI,const char* direccion,
          const char* mail) ;


    // Getters
    const char*getDireccion();
    const char* getMail();
    int getCodSocio();
    const char* getTelefono();
    const char* getDNI();


    // Setters
    void setDireccion(const char*direccion);
    void setMail(const char* mail);
    void setCodSocio(int codSocio);
    void setTelefono(const char* telefono);
    void setDNI(const char* DNI);


};
#endif // SOCIO_H_INCLUDED
