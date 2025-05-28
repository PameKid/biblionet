#include "ArchivoSocio.h"
#include <iostream>


int ArchivoSocio::agregarArchivoSocio(Socio socioNuevo)
{

    FILE* psocio;

    psocio = fopen("Socio.dat", "ab");

    if(psocio == nullptr)
    {
        cout << "No se pudo abrir el archivo" << endl;
        return -1; //regresa -1 si no se pudo abrir
    }

    fwrite(&socioNuevo, sizeof(Socio),1,psocio);

    fclose(psocio);

    return 2; //regresa 2 si se guardó correctamente
}

int ArchivoSocio ::leerArchivoSocio()
{
    Socio socio;
    FILE* psocio;
    psocio = fopen("Socio.dat", "rb");

    if(psocio == nullptr)
    {
        cout << "No se pudo leer el archivo." << endl;
        return -1;
    }

    while((fread(&socio,sizeof(socio),1,psocio))== 1)
    {
        if(socio.getEstado() == true)
        {
            socio.mostrarInfo();
        }
    }
    fclose(psocio);

     return 0;
}

int ArchivoSocio::contarRegistrosArchivoSocio(){
    FILE* pSocio;

    pSocio = fopen("libro.dat", "rb");

    if(pSocio == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return -1;
    }

    fseek(pSocio,0,SEEK_END);
    int tamanio = ftell(pSocio);
    fclose(pSocio);

    int cantRegistosSocios;

    cantRegistosSocios = tamanio/sizeof(Socio);
    return cantRegistosSocios ;

}


void ArchivoSocio::obtenerVectorSocios(int cantRegistros, Socio *vecSocios){

    FILE* pSocio;
    pSocio = fopen("Socio.dat", "rb");

    if(pSocio == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return;
    }

    for(int x=0; x<cantRegistros; x++){
        fread(&vecSocios[x],sizeof(Socio),1,pSocio);
    }

    fclose(pSocio);

}
