#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED
#include "ManagerSocio.h"

using namespace std;

void menuReportes(){
    int opc;
     ManagerSocio ms;
    while(true){
        system("cls");
        cout << "*******¡REPORTES!*******" << endl;
        cout << "1. PRESTAMOS AL MES" << endl;
        cout << "2. SOCIOS Y FECHAS DE DEVOLUCIONES" << endl;
        cout << "3. RANKINGS DE LIBROS MAS PRESTADOS" << endl;
        cout << "0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "-----------------------------------" << endl;
        cout << "SELECCIONAR OPCION" << endl;
        cin >>opc;
        system("cls");
         ManagerLibro ml;
         switch(opc)
        {
        //case 1:
          //  menuLibros();
          //  break;
        case 2:
            ms.listarSociosNoAlDia();
            system("pause");
            break;
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

#endif // MENUREPORTES_H_INCLUDED
