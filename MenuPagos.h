#ifndef MENUPAGOS_H_INCLUDED
#define MENUPAGOS_H_INCLUDED
#endif // MENUPAGOS_H_INCLUDED
#include "ManagerPago.h"

using namespace std;

void menuPagos(){
    int opc;
    while(true){
        system("cls");
        cout << "*******PAGOS!*******" << endl;
        cout << "1. INGRESAR UN PAGO" << endl;
        cout << "2. BUSCAR UN PAGO POR CODIGO DE SOCIO" << endl;
        cout << "3. LISTAR PAGOS" << endl;
        cout << "0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "----------------------------------------" << endl;
        cout << "SELECCIONAR OPCION" << endl;
        cin >>opc;
        system("cls");

        ManagerPago mp;
         switch(opc)
        {
        case 1:
            mp.altaPago();
            break;
        //case 2:

           // break;
        case 3:
            mp.listarpagos();
            break;
        //case 4:
          //  menuPagos();
          //  break;
        //case 5:
          //  menuReportes();
          //  break;
        case 0:
            return ;
            break;
        default:
            cout<< "LA SELECCION ES INCORRECTA"<<endl;

        }
    }
}
