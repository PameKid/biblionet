
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

// Fecha::Libro setFechaDePublicacion(Fecha FechaDePublicacion);

void Libro::setEstado(bool estado){
     _estado = estado;
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
//Fecha Libro:: getFechaDePublicacion(){}
bool Libro::getEstado(){
    return _estado;
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
    //cout << "Ingrese la fecha de publicación << endl;

}

void Libro::mostrarInfo(){
    cout << "Los datos ingresados son los siguientes: " << endl;
    cout << "Nombre del Libro: " << _nombreDeLibro << endl;
    cout << "Nombre del autor del libro: " << _nombreDelAutor << endl;
    cout << "Código del libro:" <<  _codLibro << endl;
    cout << "Código del autor: " << _codAutor << endl;
    cout << " ISBN del libro " << _isbn << endl;
    cout << "Género del libro: " <<  _genero << endl;
    cout << "Cantidad de ejemplares del libro: " << _cantidadEjemplares << endl;

}
