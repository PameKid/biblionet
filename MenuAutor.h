#ifndef MENUAUTOR_H_INCLUDED
#define MENUAUTOR_H_INCLUDED
#include "ManagerAutor.h"

using namespace std;

void menuAutor()
{
    int opc;
    while(true)
    {
        system("cls");
        cout << "*******¡AUTOR!*******" << endl;
        cout << "1. BUSCAR AUTOR POR NOMBRE" << endl;
        cout << "2. LISTAR AUTORES" << endl;
        cout << "3. ALTA DE AUTOR" << endl;
        cout << "4. BAJA DE AUTOR" << endl;
        cout << "5. MODIFICAR AUTOR" << endl;
        cout << "0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "----------------------------" << endl;
        cout << "SELECCIONAR OPCION" << endl;
        cin >>opc;
        system("cls");
        ManagerAutor mA;
        switch(opc)
        {
        case 1:
            mA.buscarAutorPorNombre();
            system("pause");
            break;
        case 2:
            mA.listarAutores();
            system("pause");
            break;
        case 3:
            mA.cargarAutor();
            system("pause");
            break;
        case 4:
            mA.bajaAutor();
            system("pause");
            break;
        case 5:
        //ms.modificarSocio();
        //system("pause");
        //break;
        case 0:
            return;
            break;
        default:
            cout<< "LA SELECCION ES INCORRECTA"<<endl;

        }
    }
}

#endif // MENUAUTOR_H_INCLUDED
