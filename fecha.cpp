#include "Fecha.h"
#include <iostream>
#include <ctime>

using namespace std;

Fecha::Fecha()
{
    _dia = 0;
    _mes = 0;
    _anio = 0;
}

Fecha::Fecha(int dia, int mes, int anio)
{
    _dia = dia;
    _mes = mes;
    _anio = anio;
}

int Fecha::getDia()
{
    return _dia;
}

int Fecha::getMes()
{
    return _mes;
}

int Fecha::getAnio()
{
    return _anio;
}

void Fecha::setDia(int dia)
{
    _dia = dia;
}

void Fecha::setMes(int mes)
{
    _mes = mes;
}

void Fecha::setAnio(int anio)
{
    _anio = anio;
}

std::string Fecha::toString()
{
    return std::to_string(_dia) + "/" + std::to_string(_mes) + "/" + std::to_string(_anio);
}


void Fecha :: cargarFecha()

    {
        cout << "Ingrese anio de nacimiento: ";
        cin >> _anio;
        while (validarAnio() == false)
        {
            cout << "Anio incorrecto, Intente de nuevo: ";
            cin >> _anio;
        }

        cout << "Ingrese mes de nacimiento: ";
        cin >> _mes;
        while (validarMes() == false)
        {
            cout << "Mes incorrecto, Intente de nuevo: ";
            cin >> _mes;
        }

        cout << "Ingrese dia de nacimiento: ";
        cin >> _dia;
        while (validarDia() == false)
        {
            cout << "Dia incorrecto, Intente de nuevo: ";
            cin >> _dia;
        }
    }

    Fecha Fecha::cargarFechaPrestamo()
    {

        cout << "Ingrese el anio de pago: " << endl;
        cin >> _anio;
        cout << "Ingrese el mes de pago: " << endl;
        cin >> _mes;

        cout <<"Ingrese el d�a de pago: " << endl;
        cin >> _dia;
    }

    Fecha Fecha::cargarFechaActual()
    {
        time_t rawtime;
        struct tm* timeinfo;

        time(&rawtime);
        timeinfo = localtime(&rawtime);

        _anio = timeinfo->tm_year+1900;
        _mes = timeinfo->tm_mon+1;
        _dia = timeinfo->tm_mday;
    }

    void Fecha::mostrarFecha()
    {
        cout  << _dia << "/" << _mes << "/"<< _anio << endl;
    }

    Fecha Fecha::calcularVencimiento(Fecha fechaInicial)
    {
        int diasDeVencimiento = 10;
        // Preparamos una estructura tm con la fecha inicial
        std::tm t = {};
        t.tm_mday = fechaInicial.getDia();
        t.tm_mon  = fechaInicial.getMes() - 1; // tm_mon va de 0 a 11
        t.tm_year = fechaInicial.getAnio() - 1900; // tm_year cuenta desde 1900

        // Convertimos a time_t y sumamos los d�as en segundos
        std::time_t tiempo = std::mktime(&t);
        tiempo += diasDeVencimiento * 24 * 60 * 60; // sumamos los d�as como segundos

        // Convertimos de vuelta a tm
        std::tm* nuevaFecha = std::localtime(&tiempo);

        // Creamos la nueva Fecha
        Fecha vencimiento;
        vencimiento.setDia(nuevaFecha->tm_mday);
        vencimiento.setMes(nuevaFecha->tm_mon + 1);
        vencimiento.setAnio(nuevaFecha->tm_year + 1900);

        return vencimiento;

    }

    bool Fecha :: validarAnio()
    {
        if (_anio > 0 && _anio < 2025)
        {
            return true;
        }
    }


    bool Fecha :: validarMes()
    {

        if (_mes > 0 && _mes <= 12 )
        {

            return true;
        }
    }

    bool Fecha:: validarDia()
    {
        if (_dia < 1)
        {
            return false;
        }
        if (_mes == 1 || _mes == 3 || _mes == 5 || _mes == 7 || _mes == 8 || _mes == 10 || _mes == 12)
        {
            return _dia <= 31;
        }

        else if (_mes == 4 || _mes == 6 || _mes == 9 || _mes == 11)
        {
            return _dia <= 30;
        }
        else if (_mes == 2)
        {
            bool bisiesto = (_anio % 4 == 0 && _anio % 100 != 0) || (_anio % 400 == 0);
            if (bisiesto)
            {
                return _dia <= 29;
            }
            else
            {
                return _dia <= 28;
            }
        }

        return false;

    }
