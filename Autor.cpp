#include "Autor.h"


Autor:: Autor(): Persona()
{
}

Autor :: Autor (const char* nombre, const char* apellido, Fecha fechaDeNacimiento, const char* nacionalidad) : Persona( nombre,apellido, fechaDeNacimiento)
{
    strcpy (_nacionalidad,nacionalidad);

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







