#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#pragma once
#include <string>


class Fecha
{
private:
    int _dia, _mes, _anio;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    std::string toString();

    void cargarFecha();

};



#endif // FECHA_H_INCLUDED
