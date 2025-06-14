#ifndef PRESTAMO_H
#define PRESTAMO_H

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
    Fecha _fechaDevolucion; //fecha en la que efectivamente devuelve el libro permite calcular morosos
    Fecha _fechaVencimiento; //fecha que guarda el plazo limite de vencimiento

public:

    //setters y getters:
    void setCodPrestamo(char codPrestamo[20]);
    void setCodLibro(int codLibro);
    void setCodSocio (int codSocio);
    void setEstado(bool estado);
    void setFechaPrestamo(Fecha fechaPrestamo);
    void setFechaDevolucion (Fecha fechaDevolucion);
    void setFechaVencimiento(Fecha fechaVencimiento);


    char* getCodPrestamo();
    int getCodLibro();
    int getCodSocio();
    bool getEstado();
    Fecha getFechaPrestamo();
    Fecha getFechaDevolucion();
    Fecha getFechaVencimiento();

    //metodos

    void cargarPrestamo();
    void cargarDevolucion();
    void mostrarInfo();
};

#endif // PRESTAMO_H
