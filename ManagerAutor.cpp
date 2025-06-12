#include "ManagerAutor.h"


void ManagerAutor :: cargarAutor()
{
    ArchivoAutor  archivoAutor;
    char nombre[20];
    char apellido [20];
    char nacionalidad [30];
    int codAutor;
    Fecha fechaDeNacimiento;
    int cantReg;

    cout << "Ingrese nombre: ";
    cin.ignore();
    cin.getline(nombre,20);

    cout << "Ingrese apellido: ";
    cin.getline(apellido,20);

    fechaDeNacimiento.cargarFecha();

    cout << "Ingrese nacionalidad: ";
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

    cantReg = arhivoAutor.contarRegistrosAutor();
    vecAutor = new Autor[cantReg];

    arhivoAutor.obtenerVectorAutores(cantReg, vecAutor);
    for(int x=0; x<cantReg; x++)
    {
        if (vecAutor[x].getEstado()==true)
        {
            //cout<<"cantidad registros: " << cantReg << endl;
            mostrarInfo(vecAutor[x]);
        }
    }

    delete[]vecAutor;
}

void ManagerAutor::buscarAutorPorNombre()
{
    ArchivoAutor ArchivoAutor;
    Autor autor;
    char nombre [20];
    cout <<"Ingrese Nombre: ";

    cin.ignore();
    cin.getline(nombre,20);

    int posicion= ArchivoAutor.buscarAutorPorNombre(nombre);

    if (posicion < 0 )
    {
        cout << "No existe el Autor";
    }
    else
    {
        autor= ArchivoAutor.obtenerAutorArchivo(posicion);
        mostrarInfo(autor);
    }
}

void ManagerAutor::mostrarInfo(Autor autor)
{

    cout<<endl;
    cout << "Nombre: " <<autor.getNombre()<< endl;
    cout << "Apellido: " << autor.getApellido() << endl;
    cout << "Fecha de nacimiento:" << autor.getFecaDeNacimiento().toString()<< endl;
    cout << "Nacionalidad: " << autor.getNacionalidad() << endl;
    cout << "Codigo de Autor: "  << autor.getCodAutor() << endl;
    cout << "Estado del Autor: " <<autor.getEstado() << endl;
}

void ManagerAutor::bajaAutor()
{
    int codigo;
    ArchivoAutor archivoAutor;
    cout<<"Ingrese codigo de Autor: ";
    cin>>codigo;
    if(archivoAutor.bajaArchivoAutor(codigo)==true)
    {
        cout<<"REGISTRO BORRADO"<<endl;
    }
    else
    {
        cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
    }
}
