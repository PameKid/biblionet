#ifndef MENUSOCIOS_H_INCLUDED
#define MENUSOCIOS_H_INCLUDED
#include "ManagerSocio.h"
#include "persona.h"
#endif // MENUSOCIOS_H_INCLUDED

using namespace std;

void menuSocios()
{
    int opc;
    while(true)
    {
        system("cls");
        cout << "**********¡SOCIOS!**********" << endl<< endl;
        cout << "       ~ MENU SOCIOS ~     " << endl<<endl;
        cout << " 1. BUSCAR SOCIO POR DNI" << endl;
        cout << " 2. LISTAR SOCIOS" << endl;
        cout << " 3. ALTA DE SOCIO" << endl;
        cout << " 4. BAJA DE SOCIO" << endl;
        cout << " 5. MODIFICAR SOCIO" << endl;
        cout << " 0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "----------------------------" << endl;
        cout << "SELECCIONAR OPCION: ";
        cin >>opc;
        system("cls");
        ManagerSocio ms;
        switch(opc)
        {
        case 1:
            ms.buscarSocioPorDni();
            system("pause");
            break;
        case 2:
            ms.listarSocios();
            system("pause");
            break;
        case 3:
            ms.cargarSocio();
            system("pause");
            break;
        case 4:
            ms.bajaSocio();
            system("pause");
            break;
        case 5:
            ms.modificarSocio();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<< "LA SELECCION ES INCORRECTA"<<endl;
        }
    }
}
