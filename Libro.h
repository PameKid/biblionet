

class Libro {

private:

    char _isbn[13];
    char _nombreDelLibro[50];
    char _genero[50];
    int _codLibro;
    int _codAutor;
    int cantidadEjemplares;
    //Fecha fechaDePublicacion;
    bool Estado;

public:

    //setters
    char setISBN(char isbn[13]);
    char setNombreDeLibro(char nombreDelLibro);
    char setGenero(char genero);
    int setCodLibro(int codLibro);
    int setCodAutor(int codAutor);
    int setCantidadEjemplares(int cantidadEjemplares);
    // Fecha setFechaDePublicacion(Fecha FechaDePublicacion);
    bool setEstado(bool estado);

    //getters
    char* getISBN();
    char* getNombreDeLibro();
    int getCodLibro();
    int getCodAutor();
    int getCantidadEjemplares();
    //Fecha getFechaDePublicacion();
    bool getEstado();


    //metodos
    void mostrarInfo();
    void disponible();


};

