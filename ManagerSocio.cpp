#include "ManagerSocio.h"
#include <iostream>


void ManagerSocio::agregarSocio()
{
    ArchivoSocio arhivoSocio;
    int cantReg;
    cantReg = arhivoSocio.contarRegistrosArchivoSocio();

    ArchivoSocio archivoSocio;
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
