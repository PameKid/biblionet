#include "ManagerSocio.h"
#include <iostream>
#include "ArchivoSocio.h"
#include <cstring>

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
    cin.ignore();
    cin.getline (dni,9);
    validar = archivoSocio.existeSocioPorDni(dni);
    while(validar == true)
    {
        cout << "El dni ingresado ya existe, intente con otro o ingrese 0 para volver al menu: ";
        cin.getline (dni,9);
        if (strcmp(dni, "0") == 0)
        {
            return;
        }
        validar=archivoSocio.existeSocioPorDni(dni);
    }

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
        if (vecSocios[x].getEstado()== true )
        {
            mostrarInfo(vecSocios[x]);
        }
    }

    delete[]vecSocios;
}


void ManagerSocio::mostrarInfo(Socio socio)
{
    cout<<endl;
    cout << "Nombre: " <<socio.getNombre()<< endl;
    cout << "Apellido: " << socio.getApellido() << endl;
    cout << "Fecha de nacimiento:" << socio.getFecaDeNacimiento().toString()<< endl;
    cout << "Telefono: " << socio.getTelefono()<< endl;
    cout << "DNI: " << socio.getDNI() << endl;
    cout << "Mail: " <<  socio.getMail() << endl;
    cout << "Direccion: " << socio.getDireccion() << endl;
    cout << "Codigo de Socio: "  << socio.getCodSocio() << endl;
    cout << "Estado del Socio: " <<socio.getEstado() << endl;
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
        mostrarInfo(socio);
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
    mostrarInfoParaModificar(socioModificado);

    cin >> opcion;

    while (opcion != 0)
    {
        cargarSocioModificado(opcion, socioModificado);

        system("cls");

        mostrarInfoParaModificar(socioModificado);
        cin >>opcion;
    }

    archivoSocio.modificarArchivoSocio(socioModificado);

    cout << "Modificado correctamente " << endl;
    system("pause");
}

void ManagerSocio::cargarSocioModificado(int opcion, Socio &socioAModificar)
{
    char direccion [50];
    char telefono[30];
    char mail[30];

    switch(opcion)
    {
    case 1:
        cout << "Ingrese el nuevo mail del Socio: " << endl;
        cin.ignore();
        cin.getline(mail,30);
        socioAModificar.setMail(mail);
        break;
    case 2:
        cout << "Ingrese la nueva direccion del socio: " << endl;
        cin.ignore();
        cin.getline(direccion, 30);
        socioAModificar.setDireccion(direccion);
        break;
    case 3:
        cout << "Ingrese el nuevo telefono del socio: " << endl;
        cin.ignore();
        cin.getline(telefono,30);
        socioAModificar.setTelefono(telefono);
        break;
    }
}

void ManagerSocio::mostrarInfoParaModificar(Socio socioAmodificar)
{
    cout << "Datos del Socio: " << endl;

    cout << "1. mail del Socio:  " << socioAmodificar.getMail() << endl;
    cout << "2. Direccion del Socio" << socioAmodificar.getDireccion() << endl;
    cout << "3. Telefono del Socio: " << socioAmodificar.getTelefono() << endl;
    cout << "0. Para guardar los cambios.  " << endl;
}
