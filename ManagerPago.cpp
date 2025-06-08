#include "ManagerPago.h"
#include <iostream>

using namespace std;

void ManagerPago::agregarPago(){
    ArchivoPagos archivopago;
    Pagos p1;

    p1.cargarPago();
    archivopago.AgregarArchivoPago(p1);
}

 void ManagerPago::leerArchivo(){
     Pagos pago;
     FILE* p = fopen("pago.dat", "rb");


 }
