#ifndef MANAGERSOCIO_H_INCLUDED
#define MANAGERSOCIO_H_INCLUDED
#include "ArchivoSocio.h"
#include "socio.h"
#include "ArchivoPrestamos.h"
#include "ArchivoPagos.h"

class ManagerSocio{

public:
    void cargarSocio();
    void listarSocios();
    void contarRegistrosSocios();
    void bajaSocio();
    void modificarSocio();
    void buscarSocioPorDni();
    void mostrarInfo(Socio socio);
    void cargarSocioModificado(int opcion, Socio &socioAModificar);
    void mostrarInfoParaModificar(Socio socioAmodificar);
    void listarSociosNoAlDia();

};

#endif // MANAGERSOCIO_H_INCLUDED
