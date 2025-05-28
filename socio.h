#ifndef SOCIO_H_INCLUDED
#define SOCIO_H_INCLUDED
#include "Persona.h"
#include <string>
using namespace std;
#include <iostream>


class Socio : public Persona
{

private:
    char _telefono [30];
    char _DNI [8];
    string _direccion;
    string _mail;
    int _codSocio;


public:
    Socio();
    Socio(string nombre, string apellido, Fecha fechaDeNacimiento, bool estado, const char* telefono, const char* DNI,string direccion,
                string mail,int codSocio) ;


    // Getters
    string getDireccion();
    string getMail();
    int getCodSocio();
    const char* getTelefono();
    const char* getDNI();

    // Setters
    void setDireccion(string direccion);
    void setMail(string mail);
    void setCodSocio(int codSocio);
    void setTelefono(const char* telefono);
    void setDNI(const char* DNI);


    void mostrarInfo();
    void cargarSocio();


};
#endif // SOCIO_H_INCLUDED
