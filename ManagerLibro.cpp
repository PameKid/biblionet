#include "ManagerLibro.h"
#include "ManagerAutor.h"
#include "ArchivoPrestamos.h"
//#include "ArchivoAutor.h"
#include <iostream>
#include <iomanip> //libreria para usar setw y hacer la ubicacion de la tabla

using namespace std;
//cargar libro

void ManagerLibro::cargarLibroManager(Libro &l1){
    //variables auxiliares
    ArchivoLibro archivoLibro;
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


    //utiliza la cantidad de registros para asignarle un codigo
    codLibro = archivoLibro.contarRegistros();
    cout << codLibro << endl;
    //system("pause");

    l1.setCodLibro(codLibro+100);

    //cout << l1.getCodLibro();
    //system("pause");

    cout << "Ingrese el código del autor: " << endl;
    cin >>codAutor;
    l1.setCodAutor(codAutor);

    existeCodAutor = archivoAutor.existeCodigoAutor(codAutor);

    while (existeCodAutor == false){
        int opc;
        cout << "El codigo ingresado no existe, presione 1 para ingresar otro o 0 volver al menu " << endl;
        cin >>  opc;
        if(opc == 1){
            cout << "Ingrese el codigo de autor: " << endl;
            cin >> codAutor;
            existeCodAutor = archivoAutor.existeCodigoAutor(codAutor);
        }
        else{return;}

        l1.setCodAutor(codAutor);
        existeCodAutor = archivoAutor.existeCodigoAutor(codAutor);
    }

    cout << "Ingrese el ISBN del libro " << endl;
    cin.ignore();
    cin.getline(isbn, 20);
    l1.setISBN(isbn);

    cout << "Ingrese el género del libro: " << endl;
    //cin.ignore();
    cin.getline(genero,50);
    l1.setGenero(genero);

    cout << "Ingrese la cantidad de ejemplares del libro: " << endl;
    cin >> cantidadEjemplares;
    while (cantidadEjemplares < 0){
        cout << "Ingrese un valor mayor a 0:" << endl;
        cin >> cantidadEjemplares;
    }
    l1.setCantidadEjemplares(cantidadEjemplares);

    cout << "Ingrese el año de publicación del libro: " << endl;
    cin >> anioDePublicacion;

    while (anioDePublicacion < 0){
        cout << "Ingrese un valor correcto:" << endl;
        cin >> anioDePublicacion;
    }

    l1.setAnioDePublicacion(anioDePublicacion);

    cout << "Los datos se han cargado correctamente" << endl;
    system("pause");


}

void ManagerLibro::mostrarInfoManager(Libro l1){
    cout << "Datos del libro: " << endl;
    cout << "Nombre del Libro: " << l1.getNombreDeLibro() << endl;
    cout << "Código del libro:" <<  l1.getCodLibro() << endl;
    cout << "Código del autor: " << l1.getCodAutor() << endl;
    cout << "ISBN del libro " << l1.getISBN() << endl;
    cout << "Género del libro: " << l1.getGenero() << endl;
    cout << "Cantidad de ejemplares del libro: " << l1.getCantidadEjemplares() << endl;
    cout << "Año de publicación: " << l1.getAnioDePublicacion() << endl;
    //cout << "Estado: " << _estado;
}

void ManagerLibro::mostrarTablaLibros(Libro* l, int cantidadDeRegistros){

    //Libro l;
    cout << "+------+---------------------+--------+-------------+----------+------+" << endl;
    cout << "| Cod  | Título              | Autor  | Género      | Cant.      Año  |" << endl;
    cout << "+------+---------------------+--------+-------------+----------+------+" << endl;

    for(int x = 0; x < cantidadDeRegistros; x++){
       if (l[x].getEstado()== true){
        cout << "| " << setw(4) << l[x].getCodLibro()
            << " | " << setw(20) << left << string(l[x].getNombreDeLibro()).substr(0,25)
            << " | " << setw(4) << l[x].getCodAutor()
            << " | " << setw(10) << string(l[x].getGenero()).substr(0,10)
            << " | " << setw(6) << l[x].getCantidadEjemplares()
            << " | " << setw(10) << l[x].getAnioDePublicacion()
            << " |" << endl;
        }
    }

    cout << "+------+---------------------+--------+-------------+----------+------+" << endl;

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
//    cout<<"cantidad registros: " << cantReg << endl;
//
//    for(int x=0; x<cantReg; x++){
//        if(vecLibros[x].getEstado()== true){
//        cout << "***************************" << endl;
//        mostrarInfoManager(vecLibros[x]);
//        }
//    }
    mostrarTablaLibros(vecLibros,cantReg);
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

    //validar que el codigo de libro exista en archivo libro
    libroSolicitado = obtenerLibroPorCodigo(codLibroSolicitado);

    cout << "Corrobore que los datos sean correctos: " << endl;
    mostrarInfoManager(libroSolicitado);
    //libroSolicitado.mostrarInfo();
}

void ManagerLibro::bajaLogicaLibro(){

    Libro librobaja;
    ArchivoLibro archivobajaestado;
    int codLibroBaja;
    int opcion;


    cout << "Ingrese el código del libro que desea eliminar" << endl;
    cin >> codLibroBaja;

   librobaja = obtenerLibroPorCodigo(codLibroBaja);

   cout << "***********************SELECCIONE LA OPCION CORRECTA ******************************************" << endl;
   cout << endl;
   cout << "Presione 1 si el libro que desea dar de baja es el siguiente. " <<  endl;
   cout << "Presione 0 en caso contrario " << endl;
   cout << "***********************************************************************************************" << endl;

   //librobaja.mostrarInfo();
   mostrarInfoManager(librobaja);

   cin >> opcion;

   if(opcion == 1){
        librobaja.setEstado(false);
        //librobaja.setCantidadEjemplares(100);
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

    cout << "Ingrese el código del libro que desea modificar: " << endl;
    cin >> codLibro;

    libroModificado = obtenerLibroPorCodigo(codLibro);

    cout << "Elija el dato que quiere modificar: " << endl;
    //libroModificado.mostrarInfoParaModificar();
    mostrarInfoParaModificarNUEVO(libroModificado);

    cin >> opcion;

    while (opcion != 0){

        //libroModificado.cargarLibroModificado(opcion);
        cargarLibroModificadoNUEVO(libroModificado, opcion);

        system("cls");

        mostrarInfoParaModificarNUEVO(libroModificado);
        //libroModificado.mostrarInfoParaModificar();
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
                //modificar solo debe devolver un libro

            libroobtenido = vecLibros[x];
            libroobtenido.setPosicion(x);
           // vecLibros[x].mostrarInfo();
            break;
        }
    }

    delete[]vecLibros;
    return libroobtenido;
}

void ManagerLibro::descontarEjemplares(int codLibro){
    ArchivoLibro archiLibro;
    Libro libroPrestado;
    int cantidadEjemplares;

    libroPrestado = obtenerLibroPorCodigo(codLibro);
    cantidadEjemplares = libroPrestado.getCantidadEjemplares() - 1;

    libroPrestado.setCantidadEjemplares(cantidadEjemplares);

    archiLibro.modificarArchivoLibro(libroPrestado);
}

void ManagerLibro::listarLibrosPorAutor(){
    Autor autorbuscado;
    ManagerAutor managerAutor;
    ArchivoAutor archivoAutor;
    char nombreAutor[20];
    int vecPosiciones[5];
    int posicion;
    int codAutor;
    ArchivoLibro arhivoLibro;
    int cantLibros;
    Libro *vecLibros = nullptr;
    Libro libroobtenido;


    cout << "Ingrese el nombre del autor que desea buscar: " << endl;
    cin.ignore();
    cin.getline(nombreAutor, 20);


    int cantidadAutores = archivoAutor.buscarAutorPorNombre(nombreAutor, vecPosiciones);    // De archivoAutor

    if (cantidadAutores <= 0 )
    {
        cout << "No existe el Autor"<< endl;
        system("pause");
        return;
    }

    cantLibros = arhivoLibro.contarRegistros();
    vecLibros = new Libro[cantLibros];

    arhivoLibro.obtenerVectorLibros(cantLibros, vecLibros);


    for (int z = 0; z < cantidadAutores; z++){
    /////////////////
        autorbuscado = archivoAutor.obtenerAutorArchivo(vecPosiciones[z]);
        managerAutor.mostrarInfo(autorbuscado);

        cout << endl << "Listado de Libros del Autor: " << endl << endl;

        for(int x=0; x<cantLibros; x++){
            if(vecLibros[x].getCodAutor()==autorbuscado.getCodAutor() && vecLibros[x].getEstado() == true){
                //vecLibros[x].mostrarInfo();
                mostrarInfoManager(vecLibros[x]);
                cout << "*******************" << endl;
            }
        }
///////////////////
    }
    delete[]vecLibros;
    system("pause");

    //llamar a un metodo de archivo libro que reciba autor buscado.get codigo autor.
}

void ManagerLibro::listarRankingLibro(){
    //dos vectores dinamicos para ordenar los libros prestados
    Libro *vecLibrosRankeados = nullptr;
    int *vecCantidadesPrestadas = nullptr;

    ArchivoLibro arhivoLibro;
    int cantRegLibros; //cantidad para asignar a los vectores.
    int codLibro;
    int indiceLibro;

    ArchivoPrestamo archivoPrestamo;
    int cantRegPrestamos;
    Prestamo p1;

    cantRegLibros= arhivoLibro.contarRegistros();
    //asigno a ambos vectores la cantidad de registros iguales
    vecLibrosRankeados = new Libro[cantRegLibros];
    vecCantidadesPrestadas = new int [cantRegLibros]();

    //necesito la cantidad de registros de prestamo para poder recorrerlo con un for
    arhivoLibro.obtenerVectorLibros(cantRegLibros, vecLibrosRankeados);

    cantRegPrestamos = archivoPrestamo.contarRegistrosdePrestamos();

    for(int x = 0; x < cantRegPrestamos; x++){
        p1 = archivoPrestamo.obtenerPrestamoPorPosicion(x);
        codLibro = p1.getCodLibro();
        //me guardo la posicion para poder sumar en el vector vacio.
        indiceLibro = buscarIndiceLibro(vecLibrosRankeados,cantRegLibros,codLibro);
        vecCantidadesPrestadas[indiceLibro]++;

    }

    ordenarRanking(vecLibrosRankeados,cantRegLibros,vecCantidadesPrestadas);
    mostrarTablaDeVectores(vecLibrosRankeados,vecCantidadesPrestadas);

    delete[]vecLibrosRankeados;
    delete[]vecCantidadesPrestadas;
}
//Recibe el vector de libros, la cantidad y el codigo de libro lo recorre y devuelve la posicion de ese codigo de libro
//para guardarlo en el vector vacio.
int ManagerLibro::buscarIndiceLibro(Libro* libro, int cantidadRegistro, int codLibro){

    for (int x = 0; x < cantidadRegistro; x++){
        if(libro[x].getCodLibro() == codLibro)
            return x;
    }
}

void ManagerLibro::ordenarRanking(Libro* vecLibros, int cantidadDeRegistros, int* vecTorCantidadPrestamos){
    //metodo de burbujeo
    //variables auxiliares
    int cantidadPrestamosAuxiliar;
    Libro libroAuxiliar;

    for(int y = 0; y < cantidadDeRegistros; y++){
        for(int x = 0; x < cantidadDeRegistros -1; x++){
            if(vecTorCantidadPrestamos[x] < vecTorCantidadPrestamos[x+1]){
                cantidadPrestamosAuxiliar = vecTorCantidadPrestamos[x+1];
                vecTorCantidadPrestamos[x+1] =vecTorCantidadPrestamos[x];
                vecTorCantidadPrestamos[x] = cantidadPrestamosAuxiliar;
                libroAuxiliar = vecLibros[x+1];
                vecLibros[x+1]= vecLibros[x];
                vecLibros[x]= libroAuxiliar;
            }
        }

    }
}
//funcion de prueba

void ManagerLibro::mostrarTablaDeVectores(Libro* listaDeLibros, int* vecCantidadesPrestamos){


    cout << "+------+---------------------+--------+----------+" << endl;
    cout << "| Cod  | Título              | Cantidad Prestada  |" << endl;
    cout << "+------+---------------------+--------+----------+" << endl;

    for(int x = 0; x < 5 ; x++){
        cout << "| " << setw(4) << listaDeLibros[x].getCodLibro()
            << " | " << setw(20) << left << string(listaDeLibros[x].getNombreDeLibro()).substr(0,25)
            << " | " << setw(4) << vecCantidadesPrestamos[x]
            << " |" << endl;
    }

    cout << "+------+---------------------+--------+----------+" << endl;
    system("pause");
    }

  void ManagerLibro::mostrarInfoParaModificarNUEVO(Libro libroParaModificar){

    cout << "Datos del libro: " << endl;
    cout << "1. nombre del Libro: " << libroParaModificar.getNombreDeLibro() << endl;
    cout << "2. código del libro: " << libroParaModificar.getCodLibro() << endl;
    cout << "3. código del autor:  " << libroParaModificar.getCodAutor() << endl;
    cout << "4. ISBN del libro " << libroParaModificar.getISBN()<< endl;
    cout << "5. género del libro: " << libroParaModificar.getGenero() << endl;
    cout << "6. cantidad de ejemplares del libro:  " << libroParaModificar.getCantidadEjemplares() << endl;
    cout << "7. año de publicación " << libroParaModificar.getAnioDePublicacion() << endl << endl;
    //cout << "Estado: " << _estado;

    cout << "0. para guardar los cambios.  " << endl;
}

void ManagerLibro::cargarLibroModificadoNUEVO(Libro &libroModificado, int opcion){
    //variables auxiliares
    char isbn[20];
    char nombreDeLibro[50];
    char genero[50];
    int codLibro;
    int codAutor;
    int cantidadEjemplares;
    int anioDePublicacion;


    switch(opcion)
        {
    case 1:
        cout << "Ingrese el nuevo nombre del Libro: " << endl;
        cin.ignore();
        cin.getline(nombreDeLibro, 50);
        libroModificado.setNombreDeLibro(nombreDeLibro);

        break;
    case 2:
        cout << "Ingrese el nuevo código de libro: " << endl;
        //cin.ignore();
        cin >> codLibro;
        libroModificado.setCodLibro(codLibro);

        break;

    case 3:

        cout << "Ingrese el código de autor" << endl;
        cin >> codAutor;
        libroModificado.setCodAutor(codAutor);
        break;

    case 4:
        cout << "Ingrese el ISBN: " << endl;
        cin.getline(isbn,20);
        libroModificado.setISBN(isbn);
        break;
    case 5:

        cout << "Ingrese género " << endl;
        cin.ignore();
        cin.getline(genero, 20);
        libroModificado.setGenero(genero);

        break;

    case 6:
        cout << "Ingrese cantidad de ejemplares: " << endl;
        //cin.ignore();
        cin >>(cantidadEjemplares);
        libroModificado.setCantidadEjemplares(cantidadEjemplares);
        break;

    case 7:

        cout << "Ingrese el año de publicación del libro: " << endl;
        cin >> anioDePublicacion;
        libroModificado.setAnioDePublicacion(anioDePublicacion);

        break;

    case 0:
        return ;
        break;

    default:
            cout<< "LA SELECCION ES INCORRECTA"<<endl;

    }
}

