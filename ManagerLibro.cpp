#include "ManagerLibro.h"
#include <iostream>

using namespace std;

void ManagerLibro::agregarLibro(){
    ArchivoLibro archilibro;
    Libro l1;

    l1.cargarLibro();
    archilibro.agregarArchivoLibro(l1);
}
void ManagerLibro::listarLibros(){ //mostrar la lista de archivos

    ArchivoLibro arhivoLibro;
    int cantReg;
    Libro *vecLibros = nullptr;
    //arhivoLibro.leerArchivo();

    cantReg = arhivoLibro.contarRegistros();
    vecLibros = new Libro[cantReg];

    arhivoLibro.obtenerVectorLibros(cantReg, vecLibros);
    for(int x=0; x<cantReg; x++){
    cout<<"cantidad registros: " << cantReg << endl;
        vecLibros[x].mostrarInfo();
    }

    delete[]vecLibros;
}

void ManagerLibro::contarRegistros(){
    ArchivoLibro archilibro;
    int contadorDeRegistros;

    contadorDeRegistros = archilibro.contarRegistros();

    cout << "Existen en el archivo: " << contadorDeRegistros << " registros " << endl;

}


void ManagerLibro::bajaLibro(){}
void ManagerLibro::modificarLibro(){}



void ManagerLibro::buscarLibroPorCodigo(){

    //PEDIRLE AL USUARIO UN CODIGO
    int ejemploCodig = 3;

    //HACER LA BUSQUEDA
    ArchivoLibro arhivoLibro;
    int cantReg;
    Libro *vecLibros = nullptr;

    cantReg = arhivoLibro.contarRegistros();
    vecLibros = new Libro[cantReg];

    arhivoLibro.obtenerVectorLibros(cantReg, vecLibros);
    for(int x=0; x<cantReg; x++){
        if(vecLibros[x].getCodLibro()==ejemploCodig){
            vecLibros[x].mostrarInfo();
            break;
        }
    }

    delete[]vecLibros;


}


