#include <iostream>
#include<string.h>

using namespace std;

class Prestamo{

private:
    int _codPrestamo;
    int _codLibro;
    int _codSocio;
    bool _estado;
    //Fecha fechaPrestamo;
    //Fecha fechaDevolucion;

public:

    //setters y getters:
    void setCodPrestamo(int codPrestamo);
    void setCodLibro(int codLibro);
    void setCodSocio (int codSocio);
    void setEstado(bool estado);
    //void setFechaEntrega(Fecha fechaPrestamo);
    //void setFechaDevolucion (Fecha fechaDevolucion);


    int getCodPrestamo();
    int getCodLibro();
    int getCodSocio();
    //Fecha getFechaEntrega();
    //Fecha getFechaDevolucion();

    //metodos

    void cargarPrestamo();
    void cargarDevolucion();
    void mostrarInfo();
};
