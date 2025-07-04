#include <iostream>
#include "MenuLibros.h"
#include "MenuSocios.h"
#include "MenuPrestamos.h"
#include "MenuPagos.h"
#include "MenuReportes.h"
#include "MenuAutor.h"

using namespace std;

int main()
{
    system("chcp 65001");
    setlocale(LC_ALL, "");
    int opc;
    while(true)
    {
        system("cls");
        cout << "*********ˇBIBLIONET!********" << endl<< endl;
        cout << "      ~ MENU PRINCIPAL ~     " << endl<<endl;
        cout << " 1. LIBROS" << endl;
        cout << " 2. SOCIOS" << endl;
        cout << " 3. PRESTAMOS" << endl;
        cout << " 4. PAGOS SOCIOS" << endl;
        cout << " 5. VER REPORTES" << endl;
        cout << " 6. AUTORES " << endl;
        cout << " 0. SALIR" << endl;
        cout << "-----------------------------" << endl;
        cout << "SELECCIONAR OPCION: ";
        cin >>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            menuLibros();
            break;
        case 2:
            menuSocios();
            break;
        case 3:
            menuPrestamos();
            break;
        case 4:
            menuPagos();
            break;
        case 5:
            menuReportes();
            break;
        case 6:
            menuAutor();
            break;
        case 0:
            return 0;
            break;
        default:
            cout<< "LA SELECCION ES INCORRECTA"<<endl;
        }
        //system("pause");
    }

    return 0;
}
