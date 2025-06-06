#ifndef MANAGERSOCIO_H_INCLUDED
#define MANAGERSOCIO_H_INCLUDED
#include "ArchivoSocio.h"
#include "socio.h"

class ManagerSocio{

public:
    void agregarSocio();
    void listarSocios();
    void contarRegistrosSocios();
    void bajaSocio();
    void modificarSocio();
    void buscarSocioPorDni();

};

#endif // MANAGERSOCIO_H_INCLUDED
