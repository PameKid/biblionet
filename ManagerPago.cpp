#include "ManagerPago.h"
#include<cstring>
#include "ArchivoSocio.h"
#include <cstdio>

using namespace std;

void ManagerPago::agregarPago(Pagos &p1)
{

    //variables auxiliares
    int codSocio;
    char codPago[20];
    Fecha fechaDePago;
    int mesPagado;
    int anioPagado;
    int importe;

    char cadenaAuxiliar[20];

    bool existeSocio;
    ArchivoSocio archiSocio;

    cout << "NUEVO PAGO " << endl;
    cout << "***************" << endl;

    //carga de fecha actual
    fechaDePago.cargarFechaActual();
    p1.setFechaDePago(fechaDePago);
    fechaDePago.mostrarFecha();

    cout << "Ingrese el codigo del socio:  " << endl;
    cin >> codSocio;

    existeSocio = archiSocio.existeSocio(codSocio);
    while(existeSocio == false)
    {
        int opc;
        cout << "El codigo ingresado no existe, presione 1 para ingresar otro o 0 volver al menu " << endl;
        cin >>  opc;
        if(opc == 1)
        {
            cout << "Ingrese el codigo de socio: " << endl;
            cin >> codSocio;
            existeSocio = archiSocio.existeSocio(codSocio);
        }
        else
        {
            return;
        }

    }
    //todo ok settea el objeto Pago
    p1.setCodSocio(codSocio);

    // falta validar estos datos
    cout << "Ingrese numero del mes de pago:" << endl;
    cin >> mesPagado;
    p1.setMesPagado(mesPagado);

    cout << "Ingrese  el anio de pago:" << endl;
    cin >> anioPagado;
    p1.setAnioPagado(anioPagado);

    cout << "Ingrese el importe de pago:" << endl;
    cin >> importe;
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

    cout << "codigo de pago generado: " << codPago << endl << endl;
    cout << "Los datos fueron guardados correctamente: " << endl;
    system("pause");



    //TERMINA ARMADO DE CODIGO DE PRESTAMO













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
