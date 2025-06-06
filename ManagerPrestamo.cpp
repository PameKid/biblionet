#include "ManagerPrestamo.h"

void ManagerPrestamo::cargarPrestamo(Prestamo objetoPrestamo){
    int codigoLibro;
    int codigoPrestamo;
    int codigoSocio;
    Fecha fechaPrestamo;

    cout << "NUEVO PR�STAMO " << endl;
    cout << "***************" << endl;

    fechaPrestamo.cargarFechaActual();
    objetoPrestamo.setFechaEntrega(fechaPrestamo);
    fechaPrestamo.mostrarFecha();


    cout << "Ingrese el codigo del prestamo: " << endl;
    cin >> codigoPrestamo;
    objetoPrestamo.setCodPrestamo(codigoPrestamo);


    cout << "Ingrese el c�digo del libro: " << endl;
    cin >> codigoLibro;
    objetoPrestamo.setCodLibro(codigoLibro);

    cout << "Ingrese el codigo del socio:  " << endl;
    cin >> codigoSocio;
    objetoPrestamo.setCodSocio(codigoSocio);


    cout << "Los datos fueron guardados correctamente: " << endl;


//aca se deber�a llamar a una funcion para que calcule y muestre la fecha de devolucion.
// _fechaDevolucion;

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
void ManagerPrestamo::contarPrestamosActivos(){

}
void ManagerPrestamo::buscarPrestamosCodigo(){}
void ManagerPrestamo::devolucionPrestamo(){} //guardo la fecha de devolucion
void ManagerPrestamo::modificarDatosDelPrestamo(){}; //preguntar si es necesario
Prestamo ManagerPrestamo:: obtenerPrestamoPorCodigo(int codPrestamo){}

