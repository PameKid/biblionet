#include <iostream>
#include<string.h>
#include "Fecha.h"

using namespace std;

class Prestamo{

private:
    int _codPrestamo;
    int _codLibro;
    int _codSocio;
    bool _estado;
    Fecha _fechaPrestamo;
    Fecha _fechaDevolucion;

public:

    //setters y getters:
    void setCodPrestamo(int codPrestamo);
    void setCodLibro(int codLibro);
    void setCodSocio (int codSocio);
    void setEstado(bool estado);
    void setFechaEntrega(Fecha fechaEntrega);
    void setFechaDevolucion (Fecha fechaDevolucion);


    int getCodPrestamo();
    int getCodLibro();
    int getCodSocio();
    Fecha getFechaEntrega();
    Fecha getFechaDevolucion();

    //metodos

    void cargarPrestamo();
    void cargarDevolucion();
    void mostrarInfo();
};
