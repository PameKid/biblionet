
#include <iostream>
#include<string.h>
#include "Libro.h"
#include "ArchivoAutor.h"

using namespace std;

void Libro::setISBN(char isbn[20]){
    strcpy(this->_isbn, isbn);
}

void Libro::setNombreDeLibro(char nombreDelLibro[50]){
    strcpy(this->_nombreDeLibro,nombreDelLibro);
}

void Libro::setGenero(char genero[50]){
    strcpy(this->_genero, genero);
}

void Libro::setCodLibro(int codLibro){
    _codLibro = codLibro;
}
void Libro::setCodAutor(int codAutor){
    _codAutor = codAutor;
}
void Libro::setCantidadEjemplares(int cantidadEjemplares){
    _cantidadEjemplares = cantidadEjemplares;
}

void Libro::setAnioDePublicacion(int anio){
    _anioDePublicacion = anio;
}

void Libro::setEstado(bool estado){
     _estado = estado;
}

void Libro::setPosicion(int posicion){
    _posicion = posicion;
}

//getters
char* Libro::getISBN(){
    return _isbn;
}

char* Libro::getNombreDeLibro(){
    return _nombreDeLibro;
}

int Libro::getCodLibro(){
    return _codLibro;
}

int Libro::getCodAutor(){
    return _codAutor;
}

char*Libro::getGenero(){
    return _genero;
}

int Libro::getCantidadEjemplares(){
    return _cantidadEjemplares;
}

int Libro::getAnioDePublicacion(){
    return _anioDePublicacion;
}

bool Libro::getEstado(){
    return _estado;
}

int Libro::getPosicion(){
    return _posicion;
    }




