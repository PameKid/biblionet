#ifndef MENUPAGOS_H_INCLUDED
#define MENUPAGOS_H_INCLUDED
#endif // MENUPAGOS_H_INCLUDED


using namespace std;

void menuPagos(){
    int opc;
    while(true){
        system("cls");
        cout << "*******PAGOS!*******" << endl;
        cout << "1. INGRESAR UN PAGO" << endl;
        cout << "2. BUSCAR UN PAGO POR CODIGO DE SOCIO" << endl;
        cout << "3. LISTAR PAGOS" << endl;
        cout << "0. VOLVER AL MENU ANTERIOR" << endl;
        cout << "----------------------------------------" << endl;
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
            return ;
            break;
        default:
            cout<< "LA SELECCION ES INCORRECTA"<<endl;

        }
    }
}
