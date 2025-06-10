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
    //cin.ignore();
    cout << "Ingrese anio de nacimiento: ";
    cin>> _anio;
    cout << "Ingrese mes de nacimiento: ";
    cin>>_mes;
    cout << "Ingrese dia de nacimiento: ";
    cin >> _dia;
}

Fecha Fecha::cargarFechaPrestamo()
{
    cout << "Ingrese el anio de pago: " << endl;
    cin >> _anio;

    cout << "Ingrese el mes de pago: " << endl;
    cin >> _mes;

    cout <<"Ingrese el día de pago: " << endl;
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
    cout << "Fecha: " << _dia << "/" << _mes << "/"<< _anio << endl;
}

Fecha Fecha::calcularVencimiento(Fecha fechaInicial) {
    int diasDeVencimiento = 10;
    // Preparamos una estructura tm con la fecha inicial
    std::tm t = {};
    t.tm_mday = fechaInicial.getDia();
    t.tm_mon  = fechaInicial.getMes() - 1; // tm_mon va de 0 a 11
    t.tm_year = fechaInicial.getAnio() - 1900; // tm_year cuenta desde 1900

    // Convertimos a time_t y sumamos los días en segundos
    std::time_t tiempo = std::mktime(&t);
    tiempo += diasDeVencimiento * 24 * 60 * 60; // sumamos los días como segundos

    // Convertimos de vuelta a tm
    std::tm* nuevaFecha = std::localtime(&tiempo);

    // Creamos la nueva Fecha
    Fecha vencimiento;
    vencimiento.setDia(nuevaFecha->tm_mday);
    vencimiento.setMes(nuevaFecha->tm_mon + 1);
    vencimiento.setAnio(nuevaFecha->tm_year + 1900);

    return vencimiento;
}

