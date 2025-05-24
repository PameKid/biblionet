#include <iostream>
#include <locale.h>

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

    switch(opcion){

        case 1:

            break;
        case 2:

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
    return 0;
    }
}
