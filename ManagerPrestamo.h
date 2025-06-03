#include "Prestamo.h"

class ManagerPrestamo{

public:

    void altaPrestamo();
    void listarPrestamosActivos();
    void contarPrestamosActivos();
    void buscarPrestamosCodigo();
    void devolucionPrestamo(); //guardo la fecha de devolucion
    void modificarDatosDelPrestamo(); //preguntar si es necesario
    Prestamo obtenerPrestamoPorCodigo(int codPrestamo);

};
