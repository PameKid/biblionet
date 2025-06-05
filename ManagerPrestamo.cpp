#include "ManagerPrestamo.h"



void ManagerPrestamo::altaPrestamo(){
    ArchivoPrestamo archivoPrestamo;
    Prestamo p1;

    p1.cargarPrestamo();
    archivoPrestamo.agregarArchivoPrestamo(p1);

}
void ManagerPrestamo::listarPrestamosActivos(){}
void ManagerPrestamo::contarPrestamosActivos(){}
void ManagerPrestamo::buscarPrestamosCodigo(){}
void ManagerPrestamo::devolucionPrestamo(){} //guardo la fecha de devolucion
void ManagerPrestamo::modificarDatosDelPrestamo(){}; //preguntar si es necesario
Prestamo ManagerPrestamo:: obtenerPrestamoPorCodigo(int codPrestamo){}

