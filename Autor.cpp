#include "Autor.h"


Autor:: Autor(): Persona()
{
}

Autor :: Autor (const char* nombre, const char* apellido, Fecha fechaDeNacimiento, bool estado, const char* nacionalidad,int codAutor) : Persona( nombre,apellido, fechaDeNacimiento)
{
    strcpy (_nacionalidad,nacionalidad);
    _codAutor=codAutor;
}
//getters

const char* Autor::getNacionalidad()
{
    return _nacionalidad;
}

int Autor::getCodAutor()
{
    return _codAutor;
}


// setter

void Autor::setNacionalidad(const char* nacionalidad)
{
    strncpy(_nacionalidad,nacionalidad, sizeof(_nacionalidad));
    _nacionalidad[sizeof(_nacionalidad)-1] = '\0';
}

void Autor::setCodAutor(int codAutor)
{
    _codAutor = codAutor;
}

void Autor :: cargarAutor(){
    cargarPersona();
    cin.ignore();

    cout << "Ingrese la nacionalidad del autor: ";
    cin.getline(_nacionalidad, 20);
}

void Autor::mostrarInfo()
{
    mostrartInfoPersona();
    cout << "Direccion: " << _nacionalidad << endl;
    cout << "Codigo de Autor: "  << _codAutor << endl;
}




