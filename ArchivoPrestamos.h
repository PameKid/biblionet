#ifndef ARCHIVOPRESTAMO_H
#define ARCHIVOPRESTAMO_H

#include "Prestamo.h"

class ArchivoPrestamo{

public:

    int agregarArchivoPrestamo(Prestamo prestamonuevo);
    int leerArchivoPrestamos();
    int contarRegistrosdePrestamos();
    void buscarArchivoPrestamoPorCodigo();
    //int modificarArchivoPrestamo(Prestamo prestamoModificar); preguntar al profe

    // validacion para la baja de socio ( socio moroso)

    bool prestamoInconclusoPorSocio(int codSocio);

};

#endif // ARCHIVOPRESTAMO_H
