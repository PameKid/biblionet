#include <iostream>
#include <locale.h>

using namespace std;

char Libro::setISBN(char isbn[13]){
    strcpy(this->_isbn, isbn);
}

char Libro::setNombreDeLibro(char nombreDelLibro){
    strcpy(this->_nombreDelLibro,nombreDelLibro);
}

char Libro::setGenero(char genero){
    strcpy(this->_genero, genero);
}

int Libro::setCodLibro(int codLibro){
    _codLibro = codLibro;
}
int Libro::setCodAutor(int codAutor){
    _codAutor = codAutor;
}
int Libro::setCantidadEjemplares(int cantidadEjemplares){
    _cantidadEjemplares = cantidadEjemplares;
}

// Fecha::Libro setFechaDePublicacion(Fecha FechaDePublicacion);

bool Libro::setEstado(bool estado){
     _estado = estado;
}

//getters
char* Libro::getISBN(){
    return _isbn;
}

char* Libro::getNombreDeLibro(){
    return _NombreDeLibro;
}

int Libro::getCodLibro(){
    return _codLibro;
}

int Libro::getCodAutor(){
    return _codAutor;
}
int getCantidadEjemplares(){
    return _cantidadEjemplares;
}
//Fecha Libro:: getFechaDePublicacion(){}
bool Libroo::getEstado(){
    return _estado;
}

//metodos
void Libro::mostrarInfo(){}
void Libro::disponible(){}

