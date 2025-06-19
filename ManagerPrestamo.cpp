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

    bool existeSocio; //para validar socio
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

    //validacion de cantidad de ejemplares disponibles
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

    objetoPrestamo.setFechaVencimiento(fechaVencimiento);
    objetoPrestamo.setDevolucion(true);

    cout << "Codigo de prestamo generado: " << codigoPrestamo << endl << endl;

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
//acá se  interactua con libro y resta un ejemplar hasta la fecha de devolucion.

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
    ArchivoPrestamo archiPrestamo;

    cout << "Ingrese el código del prestamo buscar" << endl;
    cin >> codPrestamoSolicitado;

    prestamoConsultado = archiPrestamo.devolverArchivoPrestamoPorCodigo(codPrestamoSolicitado);
    cout << "Corrobore que los datos sean correctos: " << endl;
    prestamoConsultado.mostrarInfo();

    system("pause");
}

void ManagerPrestamo::devolverPrestamo(){
    ArchivoPrestamo archiPrestamo;
    Prestamo prestamoDevuelto;
    char codigoPrestamo[20];
    Fecha fechaDeDevolucion;

    cout << "Ingrese el codigo del prestamo para la devolucion: " << endl;
    cin.ignore();
    cin.getline(codigoPrestamo, 20);


    prestamoDevuelto = archiPrestamo.devolverArchivoPrestamoPorCodigo(codigoPrestamo);
    if (prestamoDevuelto.getCodSocio()== 0){
        cout << "No se encontraron datos con ese codigo. " << endl; //pregunta
        system("pause");
        return;
     }
     fechaDeDevolucion.cargarFechaActual();
     prestamoDevuelto.setFechaDevolucion(fechaDeDevolucion);
     archiPrestamo.modificarArchivoPrestamo(prestamoDevuelto);

     cout << "Devolucion procesada. " << endl;
     system("pause");

}

