#include "Prestamo.h"

//setters y getters:
void Prestamo::setCodPrestamo(char codPrestamo[20]){
       strcpy(this->_codPrestamo,codPrestamo);
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

void Prestamo::setFechaPrestamo(Fecha fechaPrestamo){
    _fechaPrestamo = fechaPrestamo;
}

void Prestamo::setFechaDevolucion (Fecha fechaDevolucion){
    _fechaDevolucion = fechaDevolucion;
}

void Prestamo::setFechaVencimiento (Fecha fechaVencimiento){
    _fechaVencimiento = fechaVencimiento;
}

char* Prestamo::getCodPrestamo(){
    return _codPrestamo;
}

int Prestamo::getCodLibro(){
    return _codLibro;
}

int Prestamo::getCodSocio(){
    return _codSocio;
}

bool Prestamo::getEstado(){
    return _estado;
}

Fecha Prestamo::getFechaPrestamo(){
    return _fechaPrestamo;
}

Fecha Prestamo::getFechaDevolucion(){
    return _fechaDevolucion;
}

Fecha Prestamo::getFechaVencimiento(){
    return _fechaVencimiento;
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
    _fechaPrestamo.cargarFechaPrestamo();


//aca se debería llamar a una funcion para que calcule y muestre la fecha de devolucion.
// _fechaDevolucion;

    }

    void Prestamo::mostrarInfo(){

    cout << "DATOS DEL PRESTAMO : " << endl;
    cout << "********************" << endl;
    cout << "Codigo del prestamo: " << _codPrestamo << endl;
    cout << "Codigo del libro: " << _codLibro << endl;
    cout << "Código del socio:" <<  _codSocio << endl;
     _fechaPrestamo.mostrarFecha();
     _fechaDevolucion.mostrarFecha();

    //calcular y mostrar la fecha de devolucion a partir de fecha actual
    //cout << "Estado: " << _estado;
    cout << "----------------------------------------------" << endl;
}

void Prestamo::cargarDevolucion(){}
