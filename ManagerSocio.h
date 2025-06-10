#ifndef MANAGERSOCIO_H_INCLUDED
#define MANAGERSOCIO_H_INCLUDED
#include "ArchivoSocio.h"
#include "socio.h"

class ManagerSocio{

public:
    void cargarSocio();
    void listarSocios();
    void contarRegistrosSocios();
    void bajaSocio();
    void modificarSocio();
    void buscarSocioPorDni();
    void mostrarInfo(Socio socio);
};

#endif // MANAGERSOCIO_H_INCLUDED
