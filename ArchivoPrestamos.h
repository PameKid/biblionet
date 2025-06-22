#ifndef ARCHIVOPRESTAMO_H
#define ARCHIVOPRESTAMO_H

#include "Prestamo.h"

class ArchivoPrestamo{

public:

    int agregarArchivoPrestamo(Prestamo prestamonuevo);
    int leerArchivoPrestamos();
    int contarRegistrosdePrestamos();
    Prestamo devolverArchivoPrestamoPorCodigo(char* codigoPrestamo);
    int modificarArchivoPrestamo(Prestamo prestamoModificar); //necesario para cambiar el estado del prestamo

    // validacion para la baja de socio ( socio moroso)

    bool prestamoInconclusoPorSocio(int codSocio);
    int buscarPosicionPrestamo(Prestamo prestamo);
    int cantidadLibrosPorSocio(int codSocio);
    Prestamo obtenerPrestamoPorPosicion(int posicion);

};

#endif // ARCHIVOPRESTAMO_H
