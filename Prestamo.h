#include <iostream>
#include<string.h>
#include "Fecha.h"

using namespace std;

class Prestamo{

private:
    char _codPrestamo[20];
    int _codLibro;
    int _codSocio;
    bool _estado = true;
    Fecha _fechaPrestamo;
    Fecha _fechaDevolucion;

public:

    //setters y getters:
    void setCodPrestamo(char codPrestamo[20]);
    void setCodLibro(int codLibro);
    void setCodSocio (int codSocio);
    void setEstado(bool estado);
    void setFechaEntrega(Fecha fechaEntrega);
    void setFechaDevolucion (Fecha fechaDevolucion);


    char* getCodPrestamo();
    int getCodLibro();
    int getCodSocio();
    bool getEstado();
    Fecha getFechaEntrega();
    Fecha getFechaDevolucion();

    //metodos

    void cargarPrestamo();
    void cargarDevolucion();
    void mostrarInfo();
};
