#include "Libro.h"

class ArchivoLibro{

public:

    //les agregué la palabra Archivo para no confundirnos con los métodos del manager
    int agregarArchivoLibro(Libro libronuevo);
    int leerArchivo();
    int contarRegistros();
    void obtenerVectorLibros(int cantRegistros, Libro* libros); //recibe un vector de libros y lo carga desde el archivo
    void bajaArchivoLibro();
    void modificarArchivoLibro();
    void buscarArchivoPorCodigo();



};
