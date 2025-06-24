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

void Prestamo::setDevolucion(bool devuelto){
    _devuelto = devuelto;
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

bool Prestamo::getDevuelto(){
    return _devuelto;
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

    //VIEJO. El nuevo pasó al manager
//    cout << "Ingrese el codigo del prestamos: " << endl;
//    cin >> _codPrestamo;
//
//    cout << "Ingrese el código del libro: " << endl;
//    cin >> _codLibro;
//
//    cout << "Ingrese el codigo del socio:  " << endl;
//    cin >> _codSocio;
//
//    cout << "Ingrese la fecha de prestamo: " << endl;
//    _fechaPrestamo.cargarFechaPrestamo();


    }

    void Prestamo::mostrarInfo(){

    cout << "DATOS DEL PRESTAMO : " << endl;
    cout << "********************" << endl;
    cout << "Fecha prestamo: ";
    _fechaPrestamo.mostrarFecha();
    cout << "Codigo del prestamo: " << _codPrestamo << endl;
    cout << "Codigo del libro: " << _codLibro << endl;
    cout << "Código del socio:" <<  _codSocio << endl;
    cout << "Fecha de vencimiento: " ;
    _fechaVencimiento.mostrarFecha();
    cout << "Fecha de devolucion ";
    _fechaDevolucion.mostrarFecha();

    //cout << "Estado: " << _estado;
    cout << "----------------------------------------------" << endl;
}

bool Prestamo::devolucionVencida(Fecha fechaVencimiento,Fecha fechaDevolucion){
    if(fechaDevolucion.getAnio()> fechaVencimiento.getAnio()){
        return true;
    }
    else if(fechaDevolucion.getAnio() == fechaVencimiento.getAnio()){
        if(fechaDevolucion.getMes()> fechaVencimiento.getMes()){
            return true;
        }
        else if(fechaDevolucion.getMes() == fechaVencimiento.getMes()){
            if(fechaDevolucion.getDia()> fechaVencimiento.getDia()){
                return true;
            }

        }
    }
    return false;
}


