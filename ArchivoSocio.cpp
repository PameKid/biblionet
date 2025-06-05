#include "ArchivoSocio.h"
#include <iostream>
#include<cstring>


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

int ArchivoSocio::contarRegistrosArchivoSocio()
{
    int cantRegistosSocios;
    FILE* pSocio;

    pSocio = fopen("Socio.dat", "rb");

    if(pSocio == nullptr)
    {
        cout << "No se pudo leer el archivo." << endl;
        return 0;
    }

    fseek(pSocio,0,SEEK_END);
    int tamanio = ftell(pSocio);
    fclose(pSocio);
    cantRegistosSocios = tamanio/sizeof(Socio);

    return cantRegistosSocios ;
}


void ArchivoSocio::obtenerVectorSocios(int cantRegistros, Socio *vecSocios)
{
    FILE* pSocio;
    pSocio = fopen("Socio.dat", "rb");
    if(pSocio == nullptr)
    {
        cout << "No se pudo leer el archivo." << endl;
        return;
    }

    for(int x=0; x<cantRegistros; x++)
    {
        fread(&vecSocios[x],sizeof(Socio),1,pSocio);
    }

    fclose(pSocio);
}



Socio ArchivoSocio::obtenerSocioArchivo(int pos)
{
    Socio socio;
    FILE *pSocio;
    pSocio=fopen("Socio.dat","rb");
    socio.setCodSocio(-1);
    if(pSocio==nullptr)   ///NULL
    {
        /// cout<<"ERROR DE ARCHIVO"<<endl;
        return socio;
    }

    fseek(pSocio,pos*sizeof(socio),0);
    fread(&socio, sizeof(socio),1,pSocio);
    fclose(pSocio);
    return socio;
}


int ArchivoSocio::buscarArchivoSocio(int codigo)
{
    Socio socio;
    int cantRegistro;
    FILE *pSocio;
    pSocio=fopen("Socio.dat","rb");

    if(pSocio==nullptr)
    {
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&socio,sizeof(socio),1,pSocio)==1)
    {
        if(socio.getCodSocio()==codigo)
        {
            return pos;
        }
        pos++;
    }

    fclose(pSocio);
    return -1;
}


bool ArchivoSocio::bajaArchivoSocio(int codigo)
{
    Socio socio;
    int pos= buscarArchivoSocio(codigo);
    if(pos==-1) return false;
    socio=obtenerSocioArchivo(pos);
    if(socio.getCodSocio()==-1)
    {
        return false;
    }
    socio.setEstado(false);
    return modificarArchivoSocio(socio,pos);
}

int ArchivoSocio::modificarArchivoSocio(Socio socio, int posicion)
{
    FILE *pSocio;
    pSocio=fopen("Socio.dat","rb+");
    if(pSocio==nullptr)
    {
        return -1;
    }

    fseek(pSocio, posicion*sizeof(socio),0);
    int escribio=fwrite(&socio, sizeof(socio),1,pSocio);

    fclose(pSocio);
    return escribio;
}


int ArchivoSocio::buscarSocioDni(char dni[]) {

    Socio socio;
    int cantRegistro;
    FILE *pSocio;
    pSocio=fopen("Socio.dat","rb");

    if(pSocio==nullptr)
    {
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&socio,sizeof(socio),1,pSocio)==1)
    {
        if(strcmp (socio.getDNI(),dni) == 0 )
        {
            return pos;
        }
        pos++;
    }

    fclose(pSocio);
    return -1;





}
