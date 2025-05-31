#include "Libro.h"

class ArchivoLibro{

public:

    //les agregu� la palabra Archivo para no confundirnos con los m�todos del manager
    int agregarArchivoLibro(Libro libronuevo);
    int leerArchivo();
    int contarRegistros();
    void obtenerVectorLibros(int cantRegistros, Libro* libros); //recibe un vector de libros y lo carga desde el archivo
    void bajaArchivoLibro();
    void modificarArchivoLibro();
    void buscarArchivoPorCodigo();



};
