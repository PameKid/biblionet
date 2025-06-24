#include "ManagerPago.h"
#include<cstring>
#include "ArchivoSocio.h"
#include <cstdio>
#include <iostream>
#include "Validaciones.h"

using namespace std;

void ManagerPago::agregarPago(Pagos &p1)
{
    //variables auxiliares
    int codSocio, mesPagado,  anioPagado;
    float importe;
    char codPago[20],  cadenaAuxiliar[20];;
    Fecha fechaDePago;

    cout << "NUEVO PAGO " << endl;
    cout << "***************" << endl;

    //carga de fecha actual
    fechaDePago.cargarFechaActual();
    p1.setFechaDePago(fechaDePago);
    fechaDePago.mostrarFecha();

    // valida y settea socio

    codSocio = ingresarCodSocio();
    if(codSocio == -1) return;
    p1.setCodSocio(codSocio);

    // valida y setea mes

    mesPagado = ingresarMes();
    if(mesPagado == -1) return;
    p1.setMesPagado(mesPagado);

    //valida y settea anio

    int anioActual = fechaDePago.getAnio();
    anioPagado = ingresarAnio(anioActual);
    if(anioPagado == -1) return;
    p1.setAnioPagado(anioPagado);

    //valida si existe un pago

    if(existePago(codSocio,mesPagado,anioPagado)){

        cout << "El socio ya registra un pago con esa fecha" << endl;
        system("pause");
        return;
    }

    // valida y setea importe

    importe = ingresarImporte();
    if(importe == -1) return;
    p1.setImporte(importe);


    //ARMADO DE CODIGO DE PAGO
    strcat(codPago,"PA");

    //sprintf transforma un entero a cadena. incluir cstdio
    sprintf(cadenaAuxiliar, "%d", fechaDePago.getDia());
    strcat(codPago,cadenaAuxiliar);

    sprintf(cadenaAuxiliar, "%d", fechaDePago.getMes());
    strcat(codPago,cadenaAuxiliar);

    sprintf(cadenaAuxiliar, "%d", fechaDePago.getAnio());
    strcat(codPago,cadenaAuxiliar);

    sprintf(cadenaAuxiliar, "%d", codSocio);
    strcat(codPago,cadenaAuxiliar);
    p1.setCodPago(codPago);

    cout << "Codigo de pago generado: " << codPago << endl << endl;
    cout << "Los datos fueron guardados correctamente: " << endl;
    system("pause");

}

void ManagerPago::altaPago()
{
    ArchivoPagos archivoPago;
    Pagos p1;
    agregarPago(p1);
    archivoPago.AgregarArchivoPago(p1);

}
void ManagerPago::listarpagos()
{
    ArchivoPagos archipago;
    cout << "Listado de pagos activos: " << endl;

    cout << "****************************************" << endl;
    archipago.leerArchivo();
    system("pause");



}
