#pragma once
#include "ArchivoLibro.h"


class ManagerLibro{

public:
    void cargarLibroManager(Libro &l1);
    void mostrarInfoManager(Libro l1);
    void mostrarTablaLibros(Libro* libros, int cantidadDeRegistros);
    void agregarLibro();
    void listarLibros();
    void contarRegistros();
    void buscarLibroPorCodigo();
    void bajaLogicaLibro();
    void modificarLibro();
    Libro obtenerLibroPorCodigo(int codLibro);
    void descontarEjemplares(int codLibro);
    void sumarEjemplares(int codLibro);
    void listarLibrosPorAutor();
    void listarRankingLibro();
    int buscarIndiceLibro(Libro* libro, int cantidadRegistro, int codLibro);
    void ordenarRanking(Libro* vecLibros,int cantidadRegistros, int* vecTorCantidadPrestamos);
    void mostrarTablaDeVectores(Libro* listaDeLibros, int* vecCantidadesPrestamos);
    void mostrarInfoParaModificarNUEVO(Libro libroParaModificar);
    void cargarLibroModificadoNUEVO(Libro &libroModificado, int opcion);
};



