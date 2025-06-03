
#include <iostream>
#include<string.h>
#include "fecha.h"
#include "socio.h"
#include "Pagos.h"
using namespace std;

void Pagos::setCodSocio(int codSocio){
     _codSocio = codSocio;
}

void Pagos::setCodPago(int codPago){
    _codPago = codPago;
}

void Pagos::setFechaDePago(Fecha fechaDePago){
    _fechaDePago = fechaDePago;
}

void Pagos::setMesPagado(int mesPagado){
    _mesPagado = mesPagado;
}

void Pagos::setAnioPagado(int anioPagado){
    _anioPagado = anioPagado;
}

void Pagos::setImporte(float importe){
    _importe = importe;
}

void Pagos::setEstado(bool estado){
    _estado = estado;
}

void Pagos::cargarPago(){

   cout << "Ingrese el codigo de socio:" << endl;
   cin >> _codSocio;
   cout << "Ingrese el codigo de pago:" << endl;
   cin >> _codPago;
   //cout << "Ingrese la fecha de pago:" << endl;
   //cin >> _fechaDePago;
   cout << "Ingrese numero del mes de pago:" << endl;
   cin >> _mesPagado;
   cout << "Ingrese numero del anio de pago:" << endl;
   cin >> _anioPagado;
   cout << "Ingrese el importe de pago:" << endl;
   cin >> _importe;
}

void Pagos::mostrarDatos(){

   cout << "Los datos ingresados son los siguientes: " << endl;
    cout << "Nombre del Socio: " << _codSocio << endl;
    cout << "El codigo de pago es: " << _codPago << endl;
   // cout << "La fecha de pago es:" <<  _fechaDePago << endl;
    cout << "El mes pagado es: " << _mesPagado << endl;
    cout << " El anio de pago es : " << _anioPagado << endl;
    cout << "El importe pagado es: " <<  _importe << endl;

}
