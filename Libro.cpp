
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

//void Libro::mostrarInfo(){
//    cout << "Datos del libro: " << endl;
//    cout << "Nombre del Libro: " << _nombreDeLibro << endl;
//    cout << "C�digo del libro:" <<  _codLibro << endl;
//    cout << "C�digo del autor: " << _codAutor << endl;
//    cout << "ISBN del libro " << _isbn << endl;
//    cout << "G�nero del libro: " <<  _genero << endl;
//    cout << "Cantidad de ejemplares del libro: " << _cantidadEjemplares << endl;
//    cout << "A�o de publicaci�n: " << _anioDePublicacion << endl;
//    //cout << "Estado: " << _estado;
//}

//void Libro::mostrarInfoParaModificar(){
//    cout << "Datos del libro: " << endl;
//    cout << "1. nombre del Libro: " << _nombreDeLibro << endl;
//    cout << "2. c�digo del libro: " <<  _codLibro << endl;
//    cout << "3. c�digo del autor:  " << _codAutor << endl;
//    cout << "4. ISBN del libro " << _isbn << endl;
//    cout << "5. g�nero del libro: " <<  _genero << endl;
//    cout << "6. cantidad de ejemplares del libro:  " << _cantidadEjemplares << endl;
//    cout << "7. a�o de publicaci�n " << _anioDePublicacion << endl << endl;
//    //cout << "Estado: " << _estado;
//
//    cout << "0. para guardar los cambios.  " << endl;
//}

//void Libro::cargarLibroModificado(int opcion){
//
//    switch(opcion)
//        {
//    case 1:
//        cout << "Ingrese el nuevo nombre del Libro: " << endl;
//        cin.ignore();
//        cin.getline(_nombreDeLibro, 50);
//
//        break;
//    case 2:
//        cout << "Ingrese el nuevo c�digo de libro: " << endl;
//        //cin.ignore();
//        cin >> _codLibro;
//        break;
//
//    case 3:
//
//        cout << "Ingrese el c�digo de autor" << endl;
//        cin >> _codAutor;
//        break;
//
//    case 4:
//        cout << "Ingrese el ISBN: " << endl;
//        cin.getline(_isbn,20);
//        break;
//    case 5:
//
//        cout << "Ingrese g�nero " << endl;
//        cin.ignore();
//        cin.getline(_genero, 20);
//        break;
//
//    case 6:
//        cout << "Ingrese cantidad de ejemplares: " << endl;
//        //cin.ignore();
//        cin >>(_cantidadEjemplares);
//        break;
//
//    case 7:
//
//        cout << "Ingrese el a�o de publicaci�n del libro: " << endl;
//        cin >> _anioDePublicacion;
//        break;
//
//    case 0:
//        return ;
//        break;
//
//    default:
//            cout<< "LA SELECCION ES INCORRECTA"<<endl;
//
//    }
//}

