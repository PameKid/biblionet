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


void ManagerLibro::bajaLogicaLibro(){



}
void ManagerLibro::modificarLibro(){}

void ManagerLibro::buscarLibroPorCodigo(){
    int codLibroSolicitado;
    Libro libroSolicitado;
    ManagerLibro ml;

    cout << "Ingrese el código del libro que desea buscar" << endl;
    cin >> codLibroSolicitado;

    libroSolicitado = ml.obtenerLibroPorCodigo(codLibroSolicitado);

    cout << "Los datos del libro solicitado son los siguientes: " << endl;
    libroSolicitado.mostrarInfo();
}

Libro ManagerLibro::obtenerLibroPorCodigo(int codLibro){

    ArchivoLibro arhivoLibro;
    int cantReg;
    Libro *vecLibros = nullptr;
    Libro libroobtenido;

    cantReg = arhivoLibro.contarRegistros();
    vecLibros = new Libro[cantReg];

    arhivoLibro.obtenerVectorLibros(cantReg, vecLibros);
    for(int x=0; x<cantReg; x++){
        if(vecLibros[x].getCodLibro()==codLibro){
                //modificar solo debe devolcer un libro

            libroobtenido = vecLibros[x];
            //vecLibros[x].mostrarInfo();
            break;
        }
    }

    delete[]vecLibros;
    return libroobtenido;

}


