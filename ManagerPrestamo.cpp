#include "ManagerPrestamo.h"

void ManagerPrestamo::cargarPrestamo(Prestamo objetoPrestamo){
    int codigoLibro;
    int codigoPrestamo;
    int codigoSocio;
    Fecha fechaPrestamo;

    cout << "Ingrese el codigo del prestamo: " << endl;
    cin >> codigoPrestamo;
    objetoPrestamo.setCodPrestamo(codigoPrestamo);

    cout << "Ingrese el código del libro: " << endl;
    cin >> codigoLibro;
    objetoPrestamo.setCodLibro(codigoLibro);

    cout << "Ingrese el codigo del socio:  " << endl;
    cin >> codigoSocio;
    objetoPrestamo.setCodSocio(codigoSocio);

    cout << "Fecha actual : " << endl;
    fechaPrestamo.cargarFechaActual();

    cout << "Los datos fueron guardados correctamente: " << endl;


//aca se debería llamar a una funcion para que calcule y muestre la fecha de devolucion.
// _fechaDevolucion;

    }

void ManagerPrestamo::altaPrestamo(){
    ArchivoPrestamo archivoPrestamo;
    Prestamo p1;

    p1.cargarPrestamo();
    archivoPrestamo.agregarArchivoPrestamo(p1);

    //acá se debería interactuar con libro y restar un ejemplar hasta la fecha de devolucion.

}
void ManagerPrestamo::listarPrestamosActivos(){
    ArchivoPrestamo archiPrestamo;

    cout << "Listado de préstamos activos: " << endl;

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

