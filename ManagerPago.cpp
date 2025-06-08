#include "ManagerPago.h"
#include <iostream>
#include "ArchivoSocio.h"
using namespace std;

void ManagerPago::agregarPago(Pagos p1){

    int codSocio;
    int codPago;
    Fecha fechaDePago;
    int mesPagado;
    int anioPagado;
    int importe;

    bool existeSocio;
    ArchivoSocio archiSocio;

    cout << "NUEVO PRÉSTAMO " << endl;
    cout << "***************" << endl;

    //carga de fecha actual
    fechaDePago.cargarFechaActual();
    p1.setFechaDePago(fechaDePago);
    fechaDePago.mostrarFecha();

   cout << "Ingrese el codigo del socio:  " << endl;
    cin >> codSocio;

    existeSocio = archiSocio.existeSocio(codSocio);

    while(existeSocio == false){
        cout << "El codigo ingresado no existe, intente con otro: " << endl;
        cin >> codSocio;
        existeSocio = archiSocio.existeSocio(codSocio);
    }

    //todo ok settea el objeto Prestamo
    p1.setCodSocio(codSocio);

   cout << "Ingrese el codigo de pago:" << endl;
   cin >> codPago;

   cout << "Ingrese numero del mes de pago:" << endl;
   cin >> mesPagado;
   cout << "Ingrese numero del anio de pago:" << endl;
   cin >> anioPagado;
   cout << "Ingrese el importe de pago:" << endl;
   cin >> importe;

    ArchivoPagos archivopago;
    //Pagos p1;

    p1.cargarPago();
    archivopago.AgregarArchivoPago(p1);
}

void ManagerPago::altaPago(){
    ArchivoPagos archivoPago;
    Pagos p1;


    p1.cargarPago();
    archivoPago.AgregarArchivoPago(p1);
}
 void ManagerPago::leerArchivo(){
     Pagos pago;
     FILE* p = fopen("pago.dat", "rb");


 }
