//#pragma once
#include <iostream>
#include <locale.h>
#include "ManagerLibro.h"
#include "ManagerSocio.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    while(true){
    int opcion;
    system("cls");
    cout << "**** Bienvenido a BiblioNet ****"  << endl;
    cout << "         Menú principal      " << endl;
    cout << "1. Menú libros" << endl;
    cout << "2. Menú Socios " << endl;
    cout << "3. Menú préstamos" << endl;
    cout << "4. Menú pagos" << endl;
    cout << "5.Reportes" << endl;
    cout << "6. Salir   " << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Ingrese una opción: " << endl;

    cin >> opcion;
    system("cls");

    //Libro l1;
    ManagerLibro ml;
    ManagerSocio managerSocio;

    switch(opcion){

        case 1:
            //l1.cargarLibro();

            //l1.mostrarInfo();

            //ml.agregarLibro();
            ml.listarLibros();
            //ml.contarRegistros();

            system("pause");
            //system("cls");

            break;
        case 2:
            //ml.buscarLibroPorCodigo();
            //system("pause");
            managerSocio.agregarSocio();
            cout <<   endl;
            managerSocio.listarSocios();

            break;
        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        default:
            cout << "Opcion inválida. Por favor, intente de nuevo." << endl;

        system("pause");
        }
    }
    return 0;
}
