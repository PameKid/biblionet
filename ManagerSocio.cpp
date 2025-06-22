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

    cout << "**********¡SOCIOS!**********" << endl;
    cout << "       CARGA DE SOCIOS   "<< endl;
    cout << "****************************" << endl<< endl;
    cout << " Ingrese el DNI: ";
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

    cout <<  " Ingrese nombre: ";
    cin.getline(nombre,20);

    cout << " Ingrese apellido: ";
    cin.getline(apellido,20);

    //cout << "Ingres Fecha: ";
    fechaDeNacimiento.cargarFecha();

    cin.ignore();
    cout << " Ingrese un numero de telefono: ";
    cin.getline(telefono,30);

    cout << " Ingrese un mail: ";
    cin.getline(mail, 30);

    cout << " Ingrese una direccion: ";
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
    bool haySociosActivos= false;

    cantReg = arhivoSocio.contarRegistrosArchivoSocio();
    vecSocios = new Socio[cantReg];

    arhivoSocio.obtenerVectorSocios(cantReg, vecSocios);

    cout << "**********¡SOCIOS!**********" << endl;
    cout << "      LISTADO DE SOCIOS   "<< endl;
    cout << "****************************" << endl;

    for(int x=0; x<cantReg; x++)
    {
        if (vecSocios[x].getEstado()== true )
        {
            haySociosActivos = true;
            mostrarInfo(vecSocios[x]);
        }
    }
    if (haySociosActivos == false)
    {
        cout <<" NO HAY SOCIOS PARA LISTAR" <<endl;
    }
    cout<<"------------------------------"<<endl;
    delete[]vecSocios;
}


void ManagerSocio::mostrarInfo(Socio socio)
{
    cout<<"------------------------------"<<endl;
    cout << "Nombre             : " <<socio.getNombre()<< endl;
    cout << "Apellido           : " << socio.getApellido() << endl;
    cout << "Fecha de nacimiento: " << socio.getFecaDeNacimiento().toString()<< endl;
    cout << "Telefono           : " << socio.getTelefono()<< endl;
    cout << "DNI                : " << socio.getDNI() << endl;
    cout << "Mail               : " <<  socio.getMail() << endl;
    cout << "Direccion          : " << socio.getDireccion() << endl;
    cout << "Codigo de Socio    : "  << socio.getCodSocio() << endl;
    // cout << "Estado del Socio: " <<socio.getEstado() << endl;
}

void ManagerSocio::bajaSocio()
{
    ArchivoPrestamo archivoPrestamo;
    int codigo;
    Socio socio;
    ArchivoSocio archivoSocio;

    cout << "**********¡SOCIOS!**********" << endl;
    cout << "       BAJA DE SOCIOS   "<< endl;
    cout << "****************************" << endl<< endl;
    cout<<" Ingrese codigo de Socio: ";
    cin>>codigo;

    socio = archivoSocio.obtenerSocioPorCodigo(codigo) ;
    if (socio.getCodSocio() != -1)
    {
        if (archivoPrestamo.prestamoInconclusoPorSocio(codigo) ==true )
        {
            cout << "-------------------------------------------------------"<< endl;
            cout << " ¡NO SE PUEDE DAR DE BAJA A ESE SOCIO, ADEUDA LIBROS!" << endl;
            cout << "-------------------------------------------------------"<< endl;
        }
        else
        {
            cout << "-------------------------------------------------------"<< endl;
            cout << "Desea darle de baja al socio: "<< socio.getNombre() << " " << socio.getApellido()<< " (S o N):  ";
            char opcion;
            cin >> opcion;
            if (toupper(opcion) == 'S')
            {
                if(archivoSocio.bajaArchivoSocio(codigo)==true)
                {
                    cout<<endl<<"           REGISTRO BORRADO"<<endl;
                }
                else
                {
                    cout<<"  NO SE PUDO BORRAR EL REGISTRO"<<endl;
                }
            }
            cout << "-------------------------------------------------------"<<endl;
        }
    }
    else
    {
        cout << "NO EXISTE EL SOCIO."  ;
    }
}

void ManagerSocio::buscarSocioPorDni()
{
    ArchivoSocio archivoSocio;
    Socio socio;
    char dni [9];
    cout << "**********¡SOCIOS!**********" << endl;
    cout << "    BUSCAR SOCIOS POR DNI   "<< endl;
    cout << "****************************" << endl<< endl;
    cout <<"Ingrese DNI: ";

    cin.ignore();
    cin.getline(dni,9);

    int posicion= archivoSocio.buscarSocioDni(dni);

    if (posicion < 0 )
    {
        cout << endl << " EL DNI INGRESADO NO PERTENECE A NINGÚN SOCIO ACTIVO"<< endl<< endl;
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
    cout << "**********¡SOCIOS!**********" << endl;
    cout << "      MOODFICAR SOCIOS   "<< endl;
    cout << "****************************" << endl<< endl;

    cout << " Ingrese el código del Socio que desea modificar: ";
    cin >> codSocio;
    cout << endl;

    socioModificado = archivoSocio.obtenerSocioPorCodigo(codSocio);
    cout << " Socio a modificar: " << socioModificado.getNombre()<< " " << socioModificado.getApellido()<<endl<<endl;
    cout << " Elija el dato que quiere modificar: " << endl;
    cout << "-----------------------------------------------------"<< endl;

    mostrarInfoParaModificar(socioModificado);
    cout<<endl<<"          Opción: ";
    cin >> opcion;
    cout << "-----------------------------------------------------"<< endl;
    while (opcion != 0)
    {
        cargarSocioModificado(opcion, socioModificado);
        system("cls");
        cout << "**********¡SOCIOS!**********" << endl;
        cout << "      MOODFICAR SOCIOS   "<< endl;
        cout << "****************************" << endl<< endl;
        cout << " Elija el dato que quiere modificar: " << endl;
        cout << "-----------------------------------------------------"<< endl;
        mostrarInfoParaModificar(socioModificado);
        cout<<endl<<"          Opción: ";
        cin >>opcion;
    }

    archivoSocio.modificarArchivoSocio(socioModificado);

    cout <<endl<< " Modificado correctamente " << endl;
}

void ManagerSocio::cargarSocioModificado(int opcion, Socio &socioAModificar)
{
    char direccion [50];
    char telefono[30];
    char mail[30];

    switch(opcion)
    {
    case 1:
        cout << "Ingrese el nuevo mail del Socio: ";
        cin.ignore();
        cin.getline(mail,30);
        socioAModificar.setMail(mail);
        break;
    case 2:
        cout << "Ingrese la nueva direccion del socio: ";
        cin.ignore();
        cin.getline(direccion, 30);
        socioAModificar.setDireccion(direccion);
        break;
    case 3:
        cout << "Ingrese el nuevo telefono del socio: ";
        cin.ignore();
        cin.getline(telefono,30);
        socioAModificar.setTelefono(telefono);
        break;
    }
}

void ManagerSocio::mostrarInfoParaModificar(Socio socioAmodificar)
{
    cout << " Datos del Socio: " << endl<<endl;

    cout << "   1. Mail del Socio     : " << socioAmodificar.getMail() << endl;
    cout << "   2. Direccion del Socio: " << socioAmodificar.getDireccion() << endl;
    cout << "   3. Telefono del Socio : " << socioAmodificar.getTelefono() << endl;
    cout << "   0. Para guardar los cambios.  " << endl;
}

void ManagerSocio::listarSociosNoAlDia()
{
    ArchivoSocio arhivoSocio;
    int cantReg;
    Socio*vecSocios = nullptr;
    bool haySociosNoAlDia= false;
    ArchivoPagos archivoPago;

    cantReg = arhivoSocio.contarRegistrosArchivoSocio();
    vecSocios = new Socio[cantReg];

    arhivoSocio.obtenerVectorSocios(cantReg, vecSocios);

    cout << "**********¡REPORTES!**********" << endl;
    cout << "  LISTADO DE SOCIOS MOROSOS    "<< endl;
    cout << "****************************" << endl<< endl;

    for(int x=0; x<cantReg; x++)
    {
        if (vecSocios[x].getEstado()== true )
        {
            if (archivoPago.socioAlDia(vecSocios[x].getCodSocio())==false)
            {
                haySociosNoAlDia = true;
                mostrarInfo(vecSocios[x]);
            }
        }
    }
    if (haySociosNoAlDia == false)
    {
        cout <<" NO HAY SOCIOS PARA LISTAR" <<endl;
    }

    delete[]vecSocios;
};
