#include "ManagerPrestamo.h"
#include "ArchivoSocio.h"
#include <cstdio>
#include "ManagerLibro.h"

void ManagerPrestamo::cargarPrestamo(Prestamo &objetoPrestamo){
    //variables auxiliares
    int codigoLibro;
    char codigoPrestamo[20] = "";
    int codigoSocio;
    Fecha fechaPrestamo;
    Fecha fechaDevolucion;
    Fecha fechaVencimiento;
    ManagerLibro managerLibro;
    Libro libroparaValidarEjemplares;

    char cadenaAuxiliar[20];


    bool existeLibro; //se guarda el resultado de la validacion
    ArchivoLibro archiLibro; //para el metodo para validar el codigo

    bool existeSocio;
    ArchivoSocio archiSocio;


    cout << "NUEVO PRÉSTAMO " << endl;
    cout << "***************" << endl;

    //carga de fecha actual
    fechaPrestamo.cargarFechaActual();
    objetoPrestamo.setFechaPrestamo(fechaPrestamo);
    fechaPrestamo.mostrarFecha();

    //fechaDevolucion.mostrarFecha(); Prueba fecha de devolucion en 0
    //system("pause");


    cout << "Ingrese el código del libro: " << endl;
    cin >> codigoLibro;

    //valido que el codigo de libro exista
    existeLibro = archiLibro.existeLibro(codigoLibro);

    while (existeLibro == false){
        cout << "El código ingresado no existe, intente con otro: " << endl;
        cin >> codigoLibro;
        existeLibro = archiLibro.existeLibro(codigoLibro);
    }

    //todo ok settea el codigo en el objeto
    objetoPrestamo.setCodLibro(codigoLibro);

    libroparaValidarEjemplares = managerLibro.obtenerLibroPorCodigo(codigoLibro);
    if(libroparaValidarEjemplares.getCantidadEjemplares() == 0){
        cout << "No hay ejemplares disponibles" << endl;
        system("pause");
        return;
    }

    cout << "Ingrese el codigo del socio:  " << endl;
    cin >> codigoSocio;

    existeSocio = archiSocio.existeSocio(codigoSocio);

    while(existeSocio == false){
        cout << "El codigo ingresado no existe, intente con otro: " << endl;
        cin >> codigoSocio;
        existeSocio = archiSocio.existeSocio(codigoSocio);
    }

    //todo ok settea el objeto Prestamo
    objetoPrestamo.setCodSocio(codigoSocio);

    //valido que haya ejemplares disponibles para el prestamo

    //ARMADO DE CODIGO DE PRESTAMO
    strcat(codigoPrestamo,"PR");

    //sprintf transforma un entero a cadena. incluir cstdio
    sprintf(cadenaAuxiliar, "%d", fechaPrestamo.getDia());
    strcat(codigoPrestamo,cadenaAuxiliar);

    sprintf(cadenaAuxiliar, "%d", fechaPrestamo.getMes());
    strcat(codigoPrestamo,cadenaAuxiliar);
    sprintf(cadenaAuxiliar, "%d", fechaPrestamo.getAnio());
    strcat(codigoPrestamo,cadenaAuxiliar);

    sprintf(cadenaAuxiliar, "%d", codigoLibro);
    strcat(codigoPrestamo,cadenaAuxiliar);
    sprintf(cadenaAuxiliar, "%d", codigoSocio);
    strcat(codigoPrestamo,cadenaAuxiliar);

    objetoPrestamo.setCodPrestamo(codigoPrestamo);

    fechaVencimiento = fechaVencimiento.calcularVencimiento(fechaPrestamo);

    cout << "La fecha de devolucion es: " << endl;
    fechaVencimiento.mostrarFecha();
    objetoPrestamo.setFechaDevolucion(fechaDevolucion);

<<<<<<< HEAD

    //objetoPrestamo.setFechaDevolucion(fechaVencimiento);
=======
    objetoPrestamo.setFechaVencimiento(fechaVencimiento);
>>>>>>> 42c5a8ff62f60324cd1eece3b04dd4de2af4eee3

    cout << "codigo de prestamo generado: " << codigoPrestamo << endl << endl;

    cout << "Los datos fueron guardados correctamente: " << endl;
    system("pause");
}

void ManagerPrestamo::altaPrestamo(){
    ArchivoPrestamo archivoPrestamo;
    Prestamo p1;
    ManagerLibro ml;

    cargarPrestamo(p1);
    archivoPrestamo.agregarArchivoPrestamo(p1);
    ml.descontarEjemplares(p1.getCodLibro());
//acá se debería interactuar con libro y restar un ejemplar hasta la fecha de devolucion.

}


void ManagerPrestamo::listarPrestamosActivos(){
    ArchivoPrestamo archiPrestamo;

    cout << "Listado de préstamos activos: " << endl;

    cout << "****************************************" << endl;
    archiPrestamo.leerArchivoPrestamos();

    system("pause");
}

void ManagerPrestamo::buscarPrestamoCodigo(){

    char codPrestamoSolicitado[20];
    Prestamo prestamoConsultado;

    cout << "Ingrese el código del prestamo buscar" << endl;
    cin >> codPrestamoSolicitado;


    cout << "Corrobore que los datos sean correctos: " << endl;
    prestamoConsultado.mostrarInfo();
}

void ManagerPrestamo::devolverPrestamo(){
    ArchivoPrestamo archiPrestamo;
    Prestamo prestamoDevuelto;
    char codigoPrestamo[20];

    cout << "Ingrese el codigo del prestamo para la devolucion: " << endl;
    cin.getline(codigoPrestamo, 20);

    prestamoDevuelto = archiPrestamo.devolverArchivoPrestamoPorCodigo(codigoPrestamo);
    //para corroborar si esta vacio pregunto por la cantidad de caracteres

    //si no recibe nada debe devolver mensaje
} //guardo la fecha de devolucion y setteo la fecha de devolucion del prestamo
//llamar a modificar archivo libro para pasarle el nuevo prestamoc con la fecha setteada

Prestamo ManagerPrestamo:: obtenerPrestamoPorCodigo(int codPrestamo){}
void ManagerPrestamo::contarPrestamosActivos(){}
void ManagerPrestamo::modificarDatosDelPrestamo(){};
