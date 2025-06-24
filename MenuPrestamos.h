#ifndef MENUPRESTAMOS_HH_INCLUDED
#define MENUPRESTAMOS_HH_INCLUDED
#include "ManagerPrestamo.h"

#endif // MENUPRESTAMOS_HH_INCLUDED


using namespace std;

void menuPrestamos(){
    int opc;
    while(true){
        system("cls");
        cout << "**********¡PRESTAMOS!**********" << endl<< endl;
        cout << "      ~ MENU PRESTAMOS ~     " << endl<<endl;
        cout << " 1. NUEVO PRESTAMO" << endl;
        cout << " 2. LISTA DE PRESTAMOS ACTIVOS" << endl;
        cout << " 3. BUSCAR PRESTAMO POR CÓDIGO" << endl;
        cout << " 4. DEVOLUCION LIBRO" << endl;
        cout << " 0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "---------------------------------" << endl;
        cout << "SELECCIONAR OPCION: ";
        cin >>opc;
        system("cls");

        ManagerPrestamo mp;
         switch(opc)
        {
        case 1:
            mp.altaPrestamo();
           break;
        case 2:
            mp.listarPrestamosActivos();
            break;
        case 3:
            mp.buscarPrestamoCodigo();
            break;
        case 4:
           mp.devolverPrestamo();
           break;
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
