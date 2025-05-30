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

    cantReg = arhivoLibro.contarRegistros();
    vecLibros = new Libro[cantReg];

    arhivoLibro.obtenerVectorLibros(cantReg, vecLibros);
    cout<<"cantidad registros: " << cantReg << endl;
    for(int x=0; x<cantReg; x++){
        if(vecLibros[x].getEstado()== true){
        cout << "***************************" << endl;
        vecLibros[x].mostrarInfo();
        }
    }

    delete[]vecLibros;
}

void ManagerLibro::contarRegistros(){
    ArchivoLibro archilibro;
    int contadorDeRegistros;

    contadorDeRegistros = archilibro.contarRegistros();

    cout << "Existen en el archivo: " << contadorDeRegistros << " registros " << endl;
}

void ManagerLibro::buscarLibroPorCodigo(){ //preguntar si esto puede ser un int y devolver el codigo del libro para darlo de baja
    int codLibroSolicitado;
    Libro libroSolicitado;

    cout << "Ingrese el código del libro que desea buscar" << endl;
    cin >> codLibroSolicitado;

    libroSolicitado = obtenerLibroPorCodigo(codLibroSolicitado);

    cout << "Corrobore que los datos sean correctos: " << endl;
    libroSolicitado.mostrarInfo();
}

void ManagerLibro::bajaLogicaLibro(){

    Libro librobaja;
    ArchivoLibro archivobajaestado;
    int codLibroBaja;
    int opcion;


    cout << "Ingrese el código del libro que desea eliminar" << endl;
    cin >> codLibroBaja;

   librobaja = obtenerLibroPorCodigo(codLibroBaja);

   cout << "Presione 1 si el libro que desea dar de baja es el siguiente, 0 en caso contrario: " << endl;
   librobaja.mostrarInfo();

   cin >> opcion;

   if(opcion == 1){
        librobaja.setEstado(false);
        librobaja.setCantidadEjemplares(100);
        archivobajaestado.modificarArchivoLibro(librobaja);
        cout << "Se ha dado de baja correctament" << endl;
   }
   else{
    cout << "Se ha cancelado la baja" << endl;
   }


}
void ManagerLibro::modificarLibro(){}


//metodos auxiliares


Libro ManagerLibro::obtenerLibroPorCodigo(int codLibro){

    ArchivoLibro arhivoLibro;
    int cantReg;
    Libro *vecLibros = nullptr;
    Libro libroobtenido;

    cantReg = arhivoLibro.contarRegistros();
    vecLibros = new Libro[cantReg];

    arhivoLibro.obtenerVectorLibros(cantReg, vecLibros);
    for(int x=0; x<cantReg; x++){
        if(vecLibros[x].getCodLibro()==codLibro && vecLibros[x].getEstado() == true){ //valido que el estado del libro sea activo.
                //modificar solo debe devolcer un libro

            libroobtenido = vecLibros[x];
            libroobtenido.setPosicion(x);
           // vecLibros[x].mostrarInfo();
            break;
        }
    }

    delete[]vecLibros;
    return libroobtenido;
}

