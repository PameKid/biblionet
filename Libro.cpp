
#include <iostream>
#include<string.h>
#include "Libro.h"

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

void Libro::cargarLibro(){
    cout << "Ingrese el nombre del Libro: " << endl;
    cin.ignore();
    cin.getline(_nombreDeLibro, 50);

    cout << "Ingrese el nombre del autor del libro: " << endl;
    //cin.ignore();
    cin.getline(_nombreDelAutor,50);

    cout << "Ingrese el código del libro:" << endl;
    cin >> _codLibro;

    cout << "Ingrese el código del autor: " << endl;
    cin >>_codAutor;

    cout << "Ingrese el ISBN del libro " << endl;
    cin.ignore();
    cin.getline(_isbn, 20);

    cout << "Ingrese el género del libro: " << endl;
    //cin.ignore();
    cin.getline(_genero,50);

    cout << "Ingrese la cantidad de ejemplares del libro: " << endl;
    cin >> _cantidadEjemplares;

    cout << "Ingrese el año de publicación del libro: " << endl;
    cin >> _anioDePublicacion;

}

void Libro::mostrarInfo(){
    cout << "Datos del libro: " << endl;
    cout << "Nombre del Libro: " << _nombreDeLibro << endl;
    cout << "Nombre del autor del libro: " << _nombreDelAutor << endl;
    cout << "Código del libro:" <<  _codLibro << endl;
    cout << "Código del autor: " << _codAutor << endl;
    cout << "ISBN del libro " << _isbn << endl;
    cout << "Género del libro: " <<  _genero << endl;
    cout << "Cantidad de ejemplares del libro: " << _cantidadEjemplares << endl;
    //cout << "Estado: " << _estado;
}

void Libro::mostrarInfoParaModificar(){
    cout << "Datos del libro: " << endl;
    cout << "Si desea modificar el nombre del Libro: 1 " << _nombreDeLibro << endl;
    cout << "Si desea modificar el nombre del autor del libro: 2 " << _nombreDelAutor << endl;
    cout << "Si desea modificar el código del libro: 3 " <<  _codLibro << endl;
    cout << "Si desea modificar el código del autor:  4 " << _codAutor << endl;
    cout << "Si desea modificar el ISBN del libro 5 " << _isbn << endl;
    cout << "Si desea modificar el género del libro:  6 " <<  _genero << endl;
    cout << "Si desea modigicar la cantidad de ejemplares del libro: 7 " << _cantidadEjemplares << endl;
    //cout << "Estado: " << _estado;

    cout << "Elija cero si desea volver al menú anterior.  " << endl;
}

