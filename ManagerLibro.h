#ifndef MANAGERLIBRO_H_INCLUDED
#define MANAGERLIBRO_H_INCLUDED
#include "ArchivoLibro.h"


class ManagerLibro{

public:
    void agregarLibro();
    void listarLibros();
    void contarRegistros();
    void bajaLibro();
    void modificarLibro();
    void buscarLibroPorCodigo();

};


#endif // MANAGERLIBRO_H_INCLUDED
