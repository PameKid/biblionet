#include "ManagerSocio.h"
#include <iostream>
#include "ArchivoSocio.h"

void ManagerSocio::cargarSocio()
{
    ArchivoSocio archivoSocio;
    bool validar;
    char nombre[20];
    char apellido [20];
    char direccion [50];
    char telefono[30];
    char dni[9];
    char mail[30];
    Fecha fechaDeNacimiento;


    int cantReg;
    cout << "Ingrese el dni: ";
    cin >> dni;
    validar = archivoSocio.existeSocioPorDni(dni);
    if (validar == true)
    {
        cout <<"ESTE SOCIO YA EXISTE!"<<endl;
        system ("pause");
        return;
    }
    cin.ignore();
    cout << "Ingrese nombre: ";
    cin.getline(nombre,20);

    cout << "Ingrese apellido: ";
    cin.getline(apellido,20);

    //cout << "Ingres Fecha: ";
    fechaDeNacimiento.cargarFecha();

    cin.ignore();
    cout << "Ingrese un numero de telefono: ";
    cin.getline(telefono,30);

    cout << "Ingrese un mail: ";
    cin.getline(mail, 30);

    cout << "Ingrese una direccion: ";
    cin.getline(direccion, 50);

    Socio nuevoSocio(nombre,apellido,fechaDeNacimiento,telefono,dni,direccion,mail);
    cantReg = archivoSocio.contarRegistrosArchivoSocio();
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
