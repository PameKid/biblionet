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

/*int ArchivoSocio ::leerArchivoSocio()
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
}    */

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


void ArchivoSocio::obtenerVectorSocios(int cantRegistros, Socio *vecSocios)   // este es el que lista.
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


/*int ArchivoSocio::buscarArchivoSocio(int codigo)
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
} */


bool ArchivoSocio::bajaArchivoSocio(int codigo)
{
    Socio socio;
    socio=obtenerSocioPorCodigo(codigo);
    if(socio.getCodSocio()==-1)
    {
        return false;
    }
    socio.setEstado(false);
    return modificarArchivoSocio(socio);
}

int ArchivoSocio::modificarArchivoSocio(Socio socio)
{
    FILE *pSocio;
    pSocio=fopen("Socio.dat","rb+");
    if(pSocio==nullptr)
    {
        return -1;
    }

    fseek(pSocio, socio.getPosicion()*sizeof(socio),0);
    int escribio=fwrite(&socio, sizeof(socio),1,pSocio);

    fclose(pSocio);
    return escribio;
}


int ArchivoSocio::buscarSocioDni(char dni[])
{
    Socio socio;
    FILE *pSocio;
    pSocio=fopen("Socio.dat","rb");

    if(pSocio==nullptr)
    {

        return -2;
    }

    int pos=0;
    while(fread(&socio,sizeof(socio),1,pSocio)==1)
    {
        if(strcmp(socio.getDNI(),dni) == 0 )
        {
            return pos;
        }
        pos++;
    }

    fclose(pSocio);
    return -1;
}

Socio ArchivoSocio::obtenerSocioPorCodigo(int codSocio)
{

    int cantReg;
    Socio *vecSocios = nullptr;
    Socio socioObtenido;
    socioObtenido.setCodSocio(-1);

    cantReg =contarRegistrosArchivoSocio();
    vecSocios = new Socio[cantReg];

    obtenerVectorSocios(cantReg, vecSocios);
    for(int x=0; x<cantReg; x++)
    {
        if(vecSocios[x].getCodSocio()==codSocio && vecSocios[x].getEstado() == true)
        {
            socioObtenido = vecSocios[x];
            socioObtenido.setPosicion(x);
            break;
        }
    }

    delete[]vecSocios;
    return socioObtenido;
}

bool ArchivoSocio::existeSocio(int codSocio)
{
    FILE * pArchivoSocio;
    Socio s1;

    pArchivoSocio = fopen("Socio.dat","rb");

    if(pArchivoSocio == nullptr)
    {
        return false;
    }

    while((fread(&s1,sizeof(Socio),1,pArchivoSocio))== 1)
    {
        if(s1.getCodSocio() == codSocio)
        {
            fclose(pArchivoSocio);
            return true;
        }
    }

    fclose(pArchivoSocio);
    return false;
}

bool ArchivoSocio :: existeSocioPorDni(char dni[])
{
    FILE * pArchivoSocio;
    Socio socio;

    pArchivoSocio = fopen("Socio.dat","rb");

    if(pArchivoSocio == nullptr)
    {
        return false;
    }

    while((fread(&socio,sizeof(Socio),1,pArchivoSocio))== 1)
    {

        if(strcmp(socio.getDNI(), dni)==0)
        {
            fclose(pArchivoSocio);
            return true;
        }
    }

    fclose(pArchivoSocio);
    return false;
}

