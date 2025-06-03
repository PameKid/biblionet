#include "Prestamo.h"

//setters y getters:
void Prestamo::setCodPrestamo(int codPrestamo){
        _codPrestamo = codPrestamo;
    }

void Prestamo::setCodLibro(int codLibro){
        _codLibro = codLibro;
    }

void Prestamo::setCodSocio (int codSocio){
        _codSocio = codSocio;
    }

void Prestamo::setEstado(bool estado){
        _estado = estado;
    }
//void Prestamo::  setFechaEntrega(Fecha fechaPrestamo){
        //_fechaPrestamos = fechaPrestamo;
//}
//void Prestamo::  setFechaDevolucion (Fecha fechaDevolucion){
    //_fechaDevolucion = fechaDevolucion;
//}

int Prestamo::getCodPrestamo(){
    return _codPrestamo;
}

int Prestamo::getCodLibro(){
    return _codLibro;
}

int Prestamo::getCodSocio(){
    return _codSocio;
}

Fecha Prestamo::getFechaEntrega(){
    return _fechaEntrega;
}

Fecha Prestamo::getFechaDevolucion(){
    return _fechaDevolucion;
}

    //metodos

    void Prestamo::cargarPrestamo(){
        cout << "Ingrese el codigo del prestamos: " << endl;
        cin >> _codPrestamo;

        cout << "Ingrese el código del libro: " << endl;
        cin >> _codLibro;

        cout << "Ingrese el codigo del socio:  " << endl;
        cin >> _codSocio;

        cout << "Ingrese la fecha de prestamo: " << endl;
        _fechaEntrega.cargarFechaPrestamo();


//        _fechaDevolucion;

//aca se debería llamar a una funcion para que calcule y muestre la fecha de devolucion.
    }

    void Prestamo::cargarDevolucion(){}
    void Prestamo::mostrarInfo(){}
