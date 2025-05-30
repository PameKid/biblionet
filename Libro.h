


class Libro {

private:

    char _isbn[20];
    char _nombreDeLibro[50];
    char _nombreDelAutor[50];
    char _genero[50];
    int _codLibro;
    int _codAutor;
    int _cantidadEjemplares;
    //Fecha fechaDePublicacion;
    bool _estado = true;
    int _posicion;

public:

    //setters
    void setISBN(char isbn[13]);
    void setNombreDeLibro(char nombreDelLibro[50]);
    void setnombreDelAutor(char nnombreDelAutor[50]);
    void setGenero(char genero[30]);
    void setCodLibro(int codLibro);
    void setCodAutor(int codAutor);
    void setCantidadEjemplares(int cantidadEjemplares);
    // Fecha setFechaDePublicacion(Fecha FechaDePublicacion);
    void setEstado(bool estado);
    void setPosicion(int posicion);

    //getters
    char* getISBN();
    char* getNombreDeLibro();
    char* getNombreDelAutor();
    char* getGenero();
    int getCodLibro();
    int getCodAutor();
    int getCantidadEjemplares();
    //Fecha getFechaDePublicacion();
    bool getEstado();
    int getPosicion();


    //metodos
    void cargarLibro();
    void mostrarInfo();
    void disponible();

};

