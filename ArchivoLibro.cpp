#include "ArchivoLibro.h"
#include <iostream>

using namespace std;

int ArchivoLibro::agregarArchivoLibro(Libro libronuevo){
    FILE* plibro;

    plibro = fopen("libro.dat", "ab");

    if(plibro == nullptr){
        cout << "No se pudo abrir el archivo" << endl;
        return -1; //regresa -1 si no se pudo abrir
    }

    fwrite(&libronuevo, sizeof(Libro),1,plibro);
    fclose(plibro);

    return 2; //regresa 2 si se guardó correctamente
}

int ArchivoLibro::leerArchivo(){
    Libro l1;
    FILE* plibro;

    plibro = fopen("libro.dat", "rb");

    if(plibro == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return -1;
    }

    while((fread(&l1,sizeof(Libro),1,plibro))== 1){
        if(l1.getEstado() == true){

        l1.mostrarInfo();
        }
    }
    fclose(plibro);
}
int ArchivoLibro::contarRegistros(){
    FILE* plibro;

    plibro = fopen("libro.dat", "rb");

    if(plibro == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return -1;
    }

    fseek(plibro,0,SEEK_END);
    int tamanio = ftell(plibro);
    fclose(plibro);

    int cantRegistosLibros;

    cantRegistosLibros = tamanio/sizeof(Libro);

}

//recibe vector de libros vacío y lo llena. Devuelve la cantidad encontrada o -1 si no pudo leer.
void ArchivoLibro::obtenerVectorLibros(int cantRegistros, Libro *vecLibros){

    FILE* plibro;
    plibro = fopen("libro.dat", "rb");

    if(plibro == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return;
    }

    for(int x=0; x<cantRegistros; x++){
        fread(&vecLibros[x],sizeof(Libro),1,plibro);
    }

    fclose(plibro);

}

void ArchivoLibro::bajaArchivoLibro(){}
void ArchivoLibro::modificarArchivoLibro(){}



