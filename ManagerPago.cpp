#include "ManagerPago.h"
#include<cstring>
//#include "ArchivoSocio.h"
#include <cstdio>
#include <iostream>
#include "Validaciones.h"
#include "ArchivoPrestamos.h"
using namespace std;

void ManagerPago::agregarPago(Pagos &p1) {
    int codSocio, mesPagado, anioPagado, importe;
    char codPago[20], cadenaAuxiliar[20];
    Fecha fechaDePago;

    cout << "*************************" << endl;
    cout << "*      NUEVO PAGO       *" << endl;
    cout << "*************************" << endl << endl;

    // Fecha actual
    fechaDePago.cargarFechaActual();
    cout << "Fecha actual:" << endl;
    p1.setFechaDePago(fechaDePago);
    fechaDePago.mostrarFecha();

    // C�digo de socio
    codSocio = ingresarCodSocio();
    if (codSocio == -1) return;
    p1.setCodSocio(codSocio);

    // Mes
    mesPagado = ingresarMes();
    if (mesPagado == -1) return;
    p1.setMesPagado(mesPagado);

    // A�o
    int anioActual = fechaDePago.getAnio();
    anioPagado = ingresarAnio(anioActual);
    if (anioPagado == -1) return;
    p1.setAnioPagado(anioPagado);

    // Validar si ya pag�
    if (existePago(codSocio, mesPagado, anioPagado)) {
        cout << "El socio ya registra un pago con esa fecha." << endl;
        system("pause");
        return;
    }

    // Importe
    importe = ingresarImporte();
    if (importe == -1) return;
    cout << "Importe ingresado: " << importe << endl;

    ArchivoPrestamo archiPrestamo;
    Pagos pago1;

    // Penalizaci�n
    if (archiPrestamo.consultarPenalidades(codSocio, mesPagado)) {
        cout << "Aplicando penalizaci�n del 5% sobre el importe base." << endl;
        importe = pago1.calcularPenalidad(importe);
        cout << " El importe final es: " << importe;
        cout << endl;
    } else {
        cout << "No se detect� penalizaci�n. Importe normal aplicado." << endl;
    }

    p1.setImporte(importe);

    // C�digo de pago
    codPago[0] = '\0'; // inicializa vac�o para strcat
    strcat(codPago, "PA");

    sprintf(cadenaAuxiliar, "%d", fechaDePago.getDia());
    strcat(codPago, cadenaAuxiliar);

    sprintf(cadenaAuxiliar, "%d", fechaDePago.getMes());
    strcat(codPago, cadenaAuxiliar);

    sprintf(cadenaAuxiliar, "%d", fechaDePago.getAnio());
    strcat(codPago, cadenaAuxiliar);

    sprintf(cadenaAuxiliar, "%d", codSocio);
    strcat(codPago, cadenaAuxiliar);

    cout << "C�digo de pago final generado: " << codPago << endl;
    p1.setCodPago(codPago);
    p1.setEstado(true);

    cout << "***************************************" << endl;
    cout << "*                                     *" << endl;
    cout << "*      PAGO REGISTRADO CON �XITO      *" << endl;
    cout << "*                                     *" << endl;
    cout << "***************************************" << endl;

    system("pause");
}

void ManagerPago::altaPago()
{
    ArchivoPagos archivoPago; // se crea archivo pago
    Pagos p1; // creamos objeto pago
    agregarPago(p1); // llamamos funcion
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
