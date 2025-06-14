#ifndef ARCHIVOAUTOR_H_INCLUDED
#define ARCHIVOAUTOR_H_INCLUDED
#include <cctype>
#include "Autor.h"

class ArchivoAutor
{

public:
    int agregarAutor(Autor autorNuevo);
    //int leerArchivoSocio();
    int contarRegistrosAutor();
    void obtenerVectorAutores(int cantRegistros, Autor* autor);
    bool bajaArchivoAutor(int codigo);
    int modificarArchivoAutor(Autor autor);
    // int buscarArchivoSocio(int codigo);
    Autor obtenerAutorArchivo(int pos) ;
    int buscarAutorPorNombre(char nombre[],int vecPosiciones[]);
    Autor obtenerAutorPorCodigo(int codAutor) ;
    //bool existeSocio(int codSocio); //interactua con prestamo para validarlo
    bool compararNombres(const char* nombre1, const char* nombre2) ;

    bool existeCodigoAutor(int codAutor);
};



#endif // ARCHIVOAUTOR_H_INCLUDED
