#ifndef ARCHIVOAUTOR_H_INCLUDED
#define ARCHIVOAUTOR_H_INCLUDED
#include "Autor.h"

     class ArchivoAutor
{

public:
    int agregarAutor(Autor autorNuevo);
    //int leerArchivoSocio();
    int contarRegistrosAutor();
    void obtenerVectorAutores(int cantRegistros, Autor* autor);
    //bool bajaArchivoSocio(int codigo);
    //int modificarArchivoSocio(Socio socio);
   // int buscarArchivoSocio(int codigo);
    Autor obtenerAutorArchivo(int pos) ;
    int buscarAutorPorNombre(char nombre[]);
    //Socio obtenerSocioPorCodigo(int codSocio);
    //bool existeSocio(int codSocio); //interactua con prestamo para validarlo
};



#endif // ARCHIVOAUTOR_H_INCLUDED
