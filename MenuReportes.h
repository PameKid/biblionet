#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED
#include "ManagerSocio.h"

using namespace std;

void menuReportes(){
    int opc;
     ManagerSocio ms;
    while(true){
        system("cls");
        cout << "*********¡REPORTES!*********" << endl<< endl;
        cout << "      ~ MENU REPORTES ~     " << endl<<endl;

        cout << " 1. SOCIOS CON CUOTA PENDIENTE" << endl;
        cout << " 2. RANKINGS DE LIBROS MAS PRESTADOS" << endl;
        cout << " 0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "-----------------------------------" << endl;
        cout << "SELECCIONAR OPCION: ";
        cin >>opc;
        system("cls");
         ManagerLibro ml;
         switch(opc)
        {

        case 1:
            ms.listarSociosNoAlDia();
            system("pause");
            break;
        case 2:
           ml.listarRankingLibro();
            break;

        case 0:
            return;
            break;
        default:
            cout<< "LA SELECCION ES INCORRECTA"<<endl;

        }
    }
}

#endif // MENUREPORTES_H_INCLUDED
