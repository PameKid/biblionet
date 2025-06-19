#include "Prestamo.h"

class ArchivoPrestamo{

public:

    int agregarArchivoPrestamo(Prestamo prestamonuevo);
    int leerArchivoPrestamos();
    int contarRegistrosdePrestamos();
    Prestamo devolverArchivoPrestamoPorCodigo(char* codigoPrestamo);
    int modificarArchivoPrestamo(Prestamo prestamoModificar); //necesario para cambiar el estado del prestamo

};
