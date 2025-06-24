#include "ManagerAutor.h"
#include "Autor.h"


void ManagerAutor :: cargarAutor()
{
    ArchivoAutor  archivoAutor;
    char nombre[20];
    char apellido [20];
    char nacionalidad [30];
    int codAutor;
    Fecha fechaDeNacimiento;
    int cantReg;

    cout << "**********¡AUTOR!**********" << endl;
    cout << "       CARGA DE AUTOR   "<< endl;
    cout << "****************************" << endl<< endl;

    cout << " Ingrese nombre: ";
    cin.ignore();
    cin.getline(nombre,20);

    cout << " Ingrese apellido: ";
    cin.getline(apellido,20);

    fechaDeNacimiento.cargarFecha();

    cout << " Ingrese nacionalidad: ";
    cin.ignore();
    cin.getline(nacionalidad, 20);

    Autor autornuevo(nombre,apellido,fechaDeNacimiento,nacionalidad);
    cantReg = archivoAutor.contarRegistrosAutor();
    autornuevo.setCodAutor(cantReg+1);
    archivoAutor.agregarAutor(autornuevo);
}

void ManagerAutor::listarAutores()  //mostrar la lista de archivos
{
    ArchivoAutor arhivoAutor;
    int cantReg;
    Autor*vecAutor = nullptr;
    bool hayAutoressActivos = false;

    cantReg = arhivoAutor.contarRegistrosAutor();
    vecAutor = new Autor[cantReg];

    arhivoAutor.obtenerVectorAutores(cantReg, vecAutor);

    cout << "**********¡AUTORES!**********" << endl;
    cout << "      LISTADO DE AUTORES   "<< endl;
    cout << "****************************" << endl;

    for(int x=0; x<cantReg; x++)
    {
        if (vecAutor[x].getEstado()==true)
        {
            hayAutoressActivos = true;
            mostrarInfo(vecAutor[x]);
        }
    }
    if (hayAutoressActivos == false)
    {
        cout <<" NO HAY AUTORES PARA LISTAR" <<endl;
    }
    cout<<"------------------------------"<<endl;

    delete[]vecAutor;
}

void ManagerAutor::buscarAutorPorNombre()
{
    ArchivoAutor archivoAutor;
    Autor autor;
    int vecPosiciones [5];
    char nombre [20];
    int posicion;
    cout << "**********¡AUTORES!**********" << endl;
    cout << "  BUSCAR AUTORES POR NOMBRE   "<< endl;
    cout << "****************************" << endl<< endl;
    cout <<"Ingrese Nombre: ";

    cin.ignore();
    cin.getline(nombre,20);

    int cantidad = archivoAutor.buscarAutorPorNombre(nombre, vecPosiciones);    // De archivoAutor

    if (cantidad <= 0 )
    {
        cout << " NO SE ENCONTRO NINGÚN AUTOR CON ESE NOMBRE."<< endl;
    }
    else
    {
        for (int i=0; i<cantidad; i++)
        {
            posicion =vecPosiciones [i];
            autor = archivoAutor.obtenerAutorArchivo(posicion);
            mostrarInfo(autor);
        }
    }
    cout<<"------------------------------"<<endl;
}

void ManagerAutor::mostrarInfo(Autor autor)
{
    cout<<"------------------------------"<<endl;
    cout << "Nombre             : " <<autor.getNombre()<< endl;
    cout << "Apellido           : " << autor.getApellido() << endl;
    cout << "Fecha de nacimiento: " << autor.getFecaDeNacimiento().toString()<< endl;
    cout << "Nacionalidad       : " << autor.getNacionalidad() << endl;
    cout << "Codigo de Autor    : "  << autor.getCodAutor() << endl;
}

void ManagerAutor::bajaAutor()
{
    int codigo;
    ArchivoAutor archivoAutor;
    Autor autor;
    char opcion;

    cout << "**********¡AUTORES!**********" << endl;
    cout << "        BAJA DE AUTOR   "<< endl;
    cout << "****************************" << endl<< endl;
    cout<<"Ingrese código de Autor: ";
    cin>>codigo;
    autor= archivoAutor.obtenerAutorPorCodigo(codigo);

    if (autor.getCodAutor() != -1)
    {

        cout << endl << "DESEA DARLE DE BAJA AL AUTOR: " << autor.getNombre() << " "<< autor.getApellido()<< " (S O N):  ";
        cin >> opcion;

        if (toupper(opcion) == 'S')
        {
            if(archivoAutor.bajaArchivoAutor(codigo)==true)
            {
                cout<<"REGISTRO BORRADO,PRESIONE UNA TECLA PARA VOLVER AL MENU ANTERIOR."<<endl;
            }
            else
            {
                cout<<"  NO SE PUDO BORRAR EL REGISTRO"<<endl;
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        cout << endl<< "NO EXISTE UN AUTOR CON ESE CODIGO."<< endl;
    }
}


