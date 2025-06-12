#ifndef MANAGERAUTOR_H_INCLUDED
#define MANAGERAUTOR_H_INCLUDED
#include "Autor.h"
#include "ArchivoAutor.h"

class ManagerAutor
{

public:
    void buscarAutorPorNombre();
    void listarAutores();
   // void agregarAutor();
    void bajaAutor();
    void modificarAutor();
    void cargarAutor();
    void mostrarInfo(Autor autor) ;
};







#endif // MANAGERAUTOR_H_INCLUDED
