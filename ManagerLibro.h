#ifndef MANAGERLIBRO_H_INCLUDED
#define MANAGERLIBRO_H_INCLUDED
#include "ArchivoLibro.h"


class ManagerLibro{

public:
    void cargarLibroManager(Libro &l1);
    void mostrarInfoManager(Libro l1);
    void agregarLibro();
    void listarLibros();
    void contarRegistros();
    void buscarLibroPorCodigo();
    void bajaLogicaLibro();
    void modificarLibro();
    Libro obtenerLibroPorCodigo(int codLibro);

};


#endif // MANAGERLIBRO_H_INCLUDED
