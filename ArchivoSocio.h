#ifndef ARCHIVOSOCIO_H_INCLUDED
#define ARCHIVOSOCIO_H_INCLUDED
#include "socio.h"

class ArchivoSocio
{

public:
    int agregarArchivoSocio(Socio socioNuevo);
    int leerArchivoSocio();
    int contarRegistrosArchivoSocio();
    void obtenerVectorSocios(int cantRegistros, Socio* socios); //recibe un vector de libros y lo carga desde el archivo
    bool bajaArchivoSocio(int codigo);
    int modificarArchivoSocio(Socio socio);
    int buscarArchivoSocio(int codigo);
    Socio obtenerSocioArchivo(int pos) ;
    int buscarSocioDni(char dni[]);
    Socio obtenerSocioPorCodigo(int codSocio);
    bool existeSocio(int codSocio); //interactua con prestamo para validarlo
};

#endif // ARCHIVOSOCIO_H_INCLUDED
