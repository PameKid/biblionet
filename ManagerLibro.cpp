#include "ManagerLibro.h"
#include "ArchivoAutor.h"
#include <iostream>

using namespace std;
//cargar libro

void ManagerLibro::cargarLibroManager(Libro &l1){
    //variables auxiliares

    char isbn[20];
    char nombreDeLibro[50];
    //char nombreDelAutor[50];
    char genero[50];
    int codLibro;
    int codAutor;
    int cantidadEjemplares;
    int anioDePublicacion;

    bool existeCodAutor; //se guarda el dato de la validacion
    ArchivoAutor archivoAutor;


    cout << "Ingrese el nombre del Libro: " << endl;
    cin.ignore();
    cin.getline(nombreDeLibro, 50);
    l1.setNombreDeLibro(nombreDeLibro);

    cout << "Ingrese el c�digo del libro:" << endl;
    cin >> codLibro;
    l1.setCodLibro(codLibro);

    cout << "Ingrese el c�digo del autor: " << endl;
    cin >>codAutor;
    l1.setCodAutor(codAutor);

    existeCodAutor = archivoAutor.existeCodigoAutor(codAutor);

    while (existeCodAutor == false){
        cout << "El c�digo ingresado no existe, intente con otro: " << endl;
        cin >> codAutor;
        l1.getCodAutor();
        existeCodAutor = archivoAutor.existeCodigoAutor(codAutor);
    }

    cout << "Ingrese el ISBN del libro " << endl;
    cin.ignore();
    cin.getline(isbn, 20);
    l1.setISBN(isbn);

    cout << "Ingrese el g�nero del libro: " << endl;
    //cin.ignore();
    cin.getline(genero,50);
    l1.setGenero(genero);

    cout << "Ingrese la cantidad de ejemplares del libro: " << endl;
    cin >> cantidadEjemplares;
    l1.setCantidadEjemplares(cantidadEjemplares);

    cout << "Ingrese el a�o de publicaci�n del libro: " << endl;
    cin >> anioDePublicacion;
    l1.setAnioDePublicacion(anioDePublicacion);

}

void ManagerLibro::mostrarInfoManager(Libro l1){
    cout << "Datos del libro: " << endl;
    cout << "Nombre del Libro: " << l1.getNombreDeLibro() << endl;
    cout << "C�digo del libro:" <<  l1.getCodLibro() << endl;
    cout << "C�digo del autor: " << l1.getCodAutor() << endl;
    cout << "ISBN del libro " << l1.getISBN() << endl;
    cout << "G�nero del libro: " << l1.getGenero() << endl;
    cout << "Cantidad de ejemplares del libro: " << l1.getCantidadEjemplares() << endl;
    cout << "A�o de publicaci�n: " << l1.getAnioDePublicacion() << endl;
    //cout << "Estado: " << _estado;
}

void ManagerLibro::agregarLibro(){
    ArchivoLibro archilibro;
    Libro l1;

    cargarLibroManager(l1);
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
        mostrarInfoManager(vecLibros[x]);
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

    cout << "Ingrese el c�digo del libro que desea buscar" << endl;
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


    cout << "Ingrese el c�digo del libro que desea eliminar" << endl;
    cin >> codLibroBaja;

   librobaja = obtenerLibroPorCodigo(codLibroBaja);

   cout << "Presione 1 si el libro que desea dar de baja es el siguiente. Presione 0 en caso contrario: " << endl;
   librobaja.mostrarInfo();

   cin >> opcion;

   if(opcion == 1){
        librobaja.setEstado(false);
        librobaja.setCantidadEjemplares(100);
        archivobajaestado.modificarArchivoLibro(librobaja);
        cout << "Se ha dado de baja correctamenta. " << endl;
   }
   else{
    cout << "Se ha cancelado la baja. " << endl;
   }

}
void ManagerLibro::modificarLibro(){

    Libro libroModificado;
    ArchivoLibro archivoLibro;
    int codLibro;
    int opcion;

    cout << "Ingrese el c�digo del libro que desea modificar: " << endl;
    cin >> codLibro;

    libroModificado = obtenerLibroPorCodigo(codLibro);

    cout << "Elija el dato que quiere modificar: " << endl;
    libroModificado.mostrarInfoParaModificar();

    cin >> opcion;

    while (opcion != 0){

        libroModificado.cargarLibroModificado(opcion);

        system("cls");

        libroModificado.mostrarInfoParaModificar();
        cin >>opcion;
    }

    archivoLibro.modificarArchivoLibro (libroModificado);



    cout << "Modificado correctamente " << endl;
    system("pause");

}


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

