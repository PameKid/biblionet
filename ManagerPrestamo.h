#include "ArchivoPrestamos.h"

class ManagerPrestamo{

public:

    void cargarPrestamo(Prestamo &objetoPrestamo);
    void altaPrestamo();
    void listarPrestamosActivos();
    void contarPrestamosActivos();
    void buscarPrestamoCodigo();
    void devolverPrestamo();
    void modificarDatosDelPrestamo(); //preguntar si es necesario
    Prestamo obtenerPrestamoPorCodigo(int codPrestamo);


};
