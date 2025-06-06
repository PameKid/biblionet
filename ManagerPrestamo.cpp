#include "ManagerPrestamo.h"



void ManagerPrestamo::altaPrestamo(){
    ArchivoPrestamo archivoPrestamo;
    Prestamo p1;

    p1.cargarPrestamo();
    archivoPrestamo.agregarArchivoPrestamo(p1);

    //acá se debería interactuar con libro y restar un ejemplar hasta la fecha de devolucion.

}
void ManagerPrestamo::listarPrestamosActivos(){
    ArchivoPrestamo archiPrestamo;
    int cantPrestamosRegistrados;
    Prestamo prestamo;

}
void ManagerPrestamo::contarPrestamosActivos(){

}
void ManagerPrestamo::buscarPrestamosCodigo(){}
void ManagerPrestamo::devolucionPrestamo(){} //guardo la fecha de devolucion
void ManagerPrestamo::modificarDatosDelPrestamo(){}; //preguntar si es necesario
Prestamo ManagerPrestamo:: obtenerPrestamoPorCodigo(int codPrestamo){}

