#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED
#include "Persona.h"
#include <string>
#include <iostream>
#include <cstring>
using namespace std;



class Autor : public Persona
{

private:
    char _nacionalidad [20];
    int _codAutor;

public:
    Autor();
    Autor(const char* nombre, const char* apellido, Fecha fechaDeNacimiento, bool estado, const char* nacionalidad, int codAutor);

    // Getters
    const char*getNacionalidad();
    int getCodAutor();

    //Setter
    void setNacionalidad(const char*nacionalidad);
    void setCodAutor(int codAutor);

    void mostrarInfo();
    void cargarAutor();
};
#endif // AUTOR_H_INCLUDED
