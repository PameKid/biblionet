#ifndef MENULIBROS_H_INCLUDED
#define MENULIBROS_H_INCLUDED
#include "ManagerLibro.h"
#endif // MENULIBROS_H_INCLUDED
using namespace std;

void menuLibros(){
    int opc;
    while(true){
        system("cls");
        cout << "*******LIBROS!*******" << endl;
        cout << "1. BUSCAR LIBRO POR CODIGO" << endl;
        cout << "2. BUSCAR LIBRO POR AUTOR" << endl;
        cout << "3. LISTAR LIBROS" << endl;
        cout << "4. ALTA LIBRO" << endl;
        cout << "5. BAJA LIBRO" << endl;
        cout << "6. MODIFICAR LIBRO" << endl;
        cout << "0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "---------------------------------" << endl;
        cout << "SELECCIONAR OPCION" << endl;
        cin >>opc;
        system("cls");

        ManagerLibro ml;
         switch(opc)
        {
        case 1:
            ml.buscarLibroPorCodigo();
             system("pause");
            break;
        case 2:
            ml.contarRegistros();
             system("pause");
            break;
        case 3:
           ml.listarLibros();
            system("pause");
            break;
        case 4:
            ml.agregarLibro();
            break;
             system("pause");
        case 5:
            ml.bajaLogicaLibro();
             system("pause");
            break;
        case 6:
            ml.modificarLibro();
             system("pause");
            break;
        case 0:
            return ;
            break;
        default:
            cout<< "LA SELECCION ES INCORRECTA"<<endl;

        }
    }




}
