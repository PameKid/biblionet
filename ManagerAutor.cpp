#include "ManagerAutor.h"


void ManagerAutor :: cargarAutor(){
    //cargarPersona();

    char nombre[20];
    char apellido [20];
    char direccion [50];
    char nacionalidad [30];
    bool estado;
    int codAutor;
    Fecha fechaDeNacimiento;

    cin.ignore();

    cout << "Ingrese la nacionalidad del autor: ";
    cin.getline(_nacionalidad, 20);
}

void ManagerAutor::agregarAutor()
{
    ArchivoAutor archivoAutor;
    int cantReg;
    cantReg = archivoAutor.contarRegistrosAutor();

    Autor nuevoAutor;

    nuevoAutor.cargarAutor();

    nuevoAutor.setCodAutor(cantReg+1);

    archivoAutor.agregarAutor(nuevoAutor);
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
        cout<<"cantidad registros: " << cantReg << endl;
        vecAutor[x].mostrarInfo();
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
        autor.mostrarInfo();
    }
}
