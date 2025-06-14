#include <iostream>
#include "socio.h"
#include "ArchivoSocio.h"
#include "Pagos.h"
using namespace std;

int ingresarCodSocio(){
    int codSocio;
    ArchivoSocio archisocio;

    cout << "Ingrese el codigo de socio: " << endl;
    cin >> codSocio;

    while(!archisocio.existeSocio(codSocio)){
        int opc;
        cout << "El codigo ingresado no existe. ¿Desea seguir intentando?. 1: si, 0:volver al menu anterior " << endl;
        cin >> opc;
        if(opc == 1){
            cout << "Ingrese el codigo de socio: " << endl;
            cin >> codSocio;
        }
        else{
            return -1;
        }
    }
    return codSocio;
}

int ingresarMes()
{
    int mesPagado;
    int intentoMes = 0;
    bool salir = false;
    while(salir == false)
    {
        cout << "Ingrese numero del mes de pago:" << endl;
        cin >> mesPagado;
        if(mesPagado >= 1 && mesPagado <= 12)
        {
            salir = true;
        }
        else
        {
            intentoMes++;
            cout << "numero de mes invalido. debe ser entre 1 y 12." << endl;
            if(intentoMes == 2)
            {
                int opc;
                cout << "¿Desea seguir intentando?. 1: si, 0:volver al menu anterior" << endl;
                cin >> opc;
                if(opc == 0)
                {
                    return -1;
                }
                else
                {
                    intentoMes = 0;
                }
            }
        }
    }

}

int ingresarAnio(int anioActual){

    int intentoAnio = 0;
    bool salirAnio = false;
    int anioPagado;

    while(salirAnio == false)
    {
        cout << "Ingrese  el anio de pago:" << endl;
        cin >> anioPagado;
        if(anioPagado >= 1900 && anioPagado <= anioActual)
        {
            salirAnio = true;
            }
            else{

                intentoAnio++;
                cout << "Anio invalido. Debe estar entre 1900 y " << anioActual << "." << endl;

                if(intentoAnio == 2)
                {
                    int Aopc;
                    cout << "¿Desea seguir intentando?. 1: si, 0:volver al menu anterior" << endl;
                    cin >> Aopc;
                    if(Aopc == 1)
                    {
                        return -1;
                    }
                    else
                    {
                        intentoAnio = 0;
                    }
                }
            }

    }

}

int ingresarImporte(){
    float importe;
    int intentosImporte = 0;
    bool salirImporte = false;

while (salirImporte == false) {
    cout << "Ingrese el importe de pago:" << endl;
    cin >> importe;

    if (importe >= 0) {
        salirImporte = true;
    }
    else {
        intentosImporte++;
        cout << "Importe inválido. No puede ser negativo." << endl;

        if (intentosImporte >= 2) {
            int opcion;
            cout << "¿Desea intentar de nuevo? 1: Sí, 0: Volver al menú " << endl;
            cin >> opcion;

            if (opcion == 0) {
                return -1;
            } else {
                intentosImporte = 0;
            }
        }
    }
}

}

bool existePago(int codSocio, int mesPagado, int anioPagado){

    FILE* ppago;
    ppago = fopen("pagos.dat", "rb");

    if(ppago != nullptr){
        Pagos pagoAux;
        while(fread(&pagoAux,sizeof(Pagos),1,ppago)){
            if(pagoAux.getCodSocio() == codSocio &&
               pagoAux.getMesPagado()== mesPagado &&
               pagoAux.getAnioPagado() == anioPagado &&
               pagoAux.getEstado()){
                return true;
               }
        }
        fclose(ppago);
        return false;
    }
}
