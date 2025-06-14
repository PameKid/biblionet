#include "ManagerPrestamo.h"
#include "ArchivoLibro.h"
#include "ArchivoSocio.h"
#include <cstdio>

void ManagerPrestamo::cargarPrestamo(Prestamo &objetoPrestamo){
    //variables auxiliares
    int codigoLibro;
    char codigoPrestamo[20];
    int codigoSocio;
    Fecha fechaPrestamo;
    Fecha fechaVencimiento;

    char cadenaAuxiliar[20];


    bool existeLibro; //se guarda el resultado de la validacion
    ArchivoLibro archiLibro; //para el metodo para validar el codigo

    bool existeSocio;
    ArchivoSocio archiSocio;


    cout << "NUEVO PR�STAMO " << endl;
    cout << "***************" << endl;

    //carga de fecha actual
    fechaPrestamo.cargarFechaActual();
    objetoPrestamo.setFechaPrestamo(fechaPrestamo);
    fechaPrestamo.mostrarFecha();

    //carga y creacion del codigo prestamo: concatenar cod libro, codsocio y fecha
    //cout << "Ingrese el c�digo del prestamo: " << endl;
    //cin >> codigoPrestamo;
    //objetoPrestamo.setCodPrestamo(codigoPrestamo);


    cout << "Ingrese el c�digo del libro: " << endl;
    cin >> codigoLibro;

    existeLibro = archiLibro.existeLibro(codigoLibro);

    while (existeLibro == false){
        cout << "El c�digo ingresado no existe, intente con otro: " << endl;
        cin >> codigoLibro;
        existeLibro = archiLibro.existeLibro(codigoLibro);
    }

    //todo ok settea el codigo en el objeto
    objetoPrestamo.setCodLibro(codigoLibro);

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

    objetoPrestamo.setFechaVencimiento(fechaVencimiento);

    cout << "codigo de prestamo generado: " << codigoPrestamo << endl << endl;
    system("pause");

    //TERMINA ARMADO DE CODIGO DE PRESTAMO

    cout << "Los datos fueron guardados correctamente: " << endl;

}

void ManagerPrestamo::altaPrestamo(){
    ArchivoPrestamo archivoPrestamo;
    Prestamo p1;

    cargarPrestamo(p1);
    archivoPrestamo.agregarArchivoPrestamo(p1);

    //ac� se deber�a interactuar con libro y restar un ejemplar hasta la fecha de devolucion.

}
void ManagerPrestamo::listarPrestamosActivos(){
    ArchivoPrestamo archiPrestamo;

    cout << "Listado de pr�stamos activos: " << endl;

    cout << "****************************************" << endl;
    archiPrestamo.leerArchivoPrestamos();

    system("pause");
}

void ManagerPrestamo::buscarPrestamoCodigo(){

    char codPrestamoSolicitado[20];
    Prestamo prestamoConsultado;

    cout << "Ingrese el c�digo del prestamo buscar" << endl;
    cin >> codPrestamoSolicitado;


    cout << "Corrobore que los datos sean correctos: " << endl;
    prestamoConsultado.mostrarInfo();
}

void ManagerPrestamo::devolucionPrestamo(char *codPrestamoSolicitado){



} //guardo la fecha de devolucion
Prestamo ManagerPrestamo:: obtenerPrestamoPorCodigo(int codPrestamo){}
void ManagerPrestamo::contarPrestamosActivos(){}
//void ManagerPrestamo::modificarDatosDelPrestamo(){}; //preguntar si es necesario
