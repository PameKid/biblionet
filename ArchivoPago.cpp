#include <iostream>
#include "ArchivoPagos.h"
#include <cstring>
using namespace std;

int ArchivoPagos::AgregarArchivoPago(Pagos pagonuevo)
{
    FILE* ppago;

    ppago = fopen("Pagos.dat", "ab");

    if(ppago == nullptr)
    {
        cout << "no se pudo abrir el archivo." << endl;
        return -1;
    }

    fwrite(&pagonuevo, sizeof(Pagos),1,ppago);
    fclose(ppago);

    return 2;
}

int ArchivoPagos::leerArchivo()
{
    Pagos p1;
    FILE* ppago;

    ppago = fopen("Pagos.dat","rb");

    if(ppago == nullptr)
    {
        cout << "no se pudo leer el archivo." << endl;
        return -1;
    }

    while((fread(&p1,sizeof(Pagos),1,ppago))== 1)
    {
        if(p1.getEstado() == true)
        {

            p1.mostrarDatos();
        }
    }

    fclose(ppago);
}

bool ArchivoPagos :: socioAlDia(int codSocio)
{


    Pagos pago;
    FILE* Ppago;
    Fecha fechaActual;
    fechaActual.cargarFechaActual();

    Ppago = fopen("Pagos.dat","rb");

    if(Ppago == nullptr)
    {
        cout << "no se pudo leer el archivo." << endl;
        return -1;
    }

    while((fread(&pago,sizeof(Pagos),1,Ppago))== 1)
    {
        if(pago.getEstado()==true && pago.getCodSocio()==codSocio)
        {
            if(pago.getMesPagado()== fechaActual.getMes()&& pago.getAnioPagado()== fechaActual.getAnio())
            {
                fclose(Ppago);
                return true;
            }
        }
    }

    fclose(Ppago);
    return false;
}

Pagos ArchivoPagos::devolverArchivoPagoPorCodigo(char* codPago){
    Pagos p1;
    Pagos pagoVacio;
    FILE* pPago;


    pPago = fopen("Pagos.dat", "rb");

    if(pPago == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return p1;
    }

    while((fread(&p1,sizeof(Pagos),1,pPago))== 1){
        if(strcmp(codPago,p1.getCodPago()) == 0){ //devuelve 0 si son iguales
            fclose(pPago);
            return p1;
        }
     fclose(pPago);
     return pagoVacio;

    }
}
