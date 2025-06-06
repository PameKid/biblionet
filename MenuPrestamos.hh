#ifndef MENUPRESTAMOS_HH_INCLUDED
#define MENUPRESTAMOS_HH_INCLUDED
#include "ManagerPrestamo.h"

#endif // MENUPRESTAMOS_HH_INCLUDED


using namespace std;

void menuPrestamos(){
    int opc;
    while(true){
        system("cls");
        cout << "*******PRESTAMOS!*******" << endl;
        cout << "1. NUEVO PRESTAMO" << endl;
        cout << "2. DEVOLUCION LIBRO" << endl;
        cout << "3. LISTA DE PRESTAMOS ACTIVOS" << endl;
        cout << "4. BUSCAR PRESTAMO" << endl;
        cout << "0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "---------------------------------" << endl;
        cout << "SELECCIONAR OPCION" << endl;
        cin >>opc;
        system("cls");

        ManagerPrestamo mp;
         switch(opc)
        {
        case 1:
            mp.altaPrestamo();
           break;
        //case 2:
          //  menuSocios();
          //  break;
        //case 3:
          //  menuPrestamos();
          //  break;
        //case 4:
          //  menuPagos();
          //  break;
        //case 5:
          //  menuReportes();
          //  break;
        case 0:
            return;
            break;
        default:
            cout<< "LA SELECCION ES INCORRECTA"<<endl;

        }
    }
}
