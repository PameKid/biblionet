

using namespace std;

void menuReportes(){
    int opc;
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
        //case 2:
          //  menuSocios();
          //  break;
        case 3:
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
