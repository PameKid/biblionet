#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

#endif // MENUREPORTES_H_INCLUDED


using namespace std;

void menuReportes(){
    int opc;
    while(true){
        system("cls");
        cout << "*******¡REPORTES!*******" << endl;
        cout << "1. PRESTAMOS ECHOS AL MES" << endl;
        cout << "2. SOCIOS Y FECHAS DE DEVOLUCIONES" << endl;
        cout << "0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "-----------------------------------" << endl;
        cout << "SELECCIONAR OPCION" << endl;
        cin >>opc;
        system("cls");
         switch(opc)
        {
        //case 1:
          //  menuLibros();
          //  break;
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
