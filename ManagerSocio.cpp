#include "ManagerSocio.h"
#include <iostream>
#include "ArchivoSocio.h"


void ManagerSocio::agregarSocio()
{
    ArchivoSocio archivoSocio;
    int cantReg;
    cantReg = archivoSocio.contarRegistrosArchivoSocio();

    Socio nuevoSocio;

    nuevoSocio.cargarSocio();

    nuevoSocio.setCodSocio(cantReg+1);

    archivoSocio.agregarArchivoSocio(nuevoSocio);
}

void ManagerSocio::listarSocios()  //mostrar la lista de archivos
{
    ArchivoSocio arhivoSocio;
    int cantReg;
    Socio*vecSocios = nullptr;

    cantReg = arhivoSocio.contarRegistrosArchivoSocio();
    vecSocios = new Socio[cantReg];

    arhivoSocio.obtenerVectorSocios(cantReg, vecSocios);
    for(int x=0; x<cantReg; x++)
    {
        cout<<"cantidad registros: " << cantReg << endl;
        vecSocios[x].mostrarInfo();
    }

    delete[]vecSocios;
}

void ManagerSocio::bajaSocio()
{
    int codigo;
    ArchivoSocio archivoSocio;
    cout<<"Ingrese codigo de Socio: ";
    cin>>codigo;
    if(archivoSocio.bajaArchivoSocio(codigo)==true)
    {
        cout<<"REGISTRO BORRADO"<<endl;
    }
    else
    {
        cout<<"NO SE PUDO BORRAR EL REGISTRO"<<endl;
    }
}

void ManagerSocio::buscarSocioPorDni()
{
    ArchivoSocio archivoSocio;
    Socio socio;
    char dni [9];
    cout <<"Ingrese DNI: ";

    cin.ignore();
    cin.getline(dni,9);

    int posicion= archivoSocio.buscarSocioDni(dni);

    if (posicion < 0 )
    {
        cout << "No existe el Socio";
    }
    else
    {
        socio= archivoSocio.obtenerSocioArchivo(posicion);
        socio.mostrarInfo();
    }
}

void ManagerSocio::modificarSocio()
{
    Socio socioModificado;
    ArchivoSocio archivoSocio;
    int codSocio;
    int opcion;

    cout << "Ingrese el código del Socio que desea modificar: " << endl;
    cin >> codSocio;

    socioModificado = archivoSocio.obtenerSocioPorCodigo(codSocio);
    cout << "Socio a modificar: " << socioModificado.getNombre()<< " " << socioModificado.getApellido()<<endl;
    cout << "Elija el dato que quiere modificar: " << endl;
    socioModificado.mostrarInfoParaModificar();

    cin >> opcion;

    while (opcion != 0)
    {
        socioModificado.cargarSocioModificado(opcion);

        system("cls");

        socioModificado.mostrarInfoParaModificar();
        cin >>opcion;
    }

    archivoSocio.modificarArchivoSocio(socioModificado);

    cout << "Modificado correctamente " << endl;
    system("pause");
}
