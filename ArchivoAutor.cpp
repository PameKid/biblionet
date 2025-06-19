#include "Autor.h"
#include "ArchivoAutor.h"
#include <cstring>
using namespace std;


int ArchivoAutor::agregarAutor(Autor autorNuevo)
{
    FILE* pAutor;
    pAutor = fopen("Autor.dat", "ab");

    if(pAutor == nullptr)
    {
        cout << "No se pudo abrir el archivo" << endl;
        return -1; //regresa -1 si no se pudo abrir
    }

    fwrite(&autorNuevo, sizeof(Autor),1,pAutor);
    fclose(pAutor);

    return 2; //regresa 2 si se guardó correctamente
}

int ArchivoAutor::contarRegistrosAutor()
{
    int cantRegistosAutor;
    FILE* pAutor;

    pAutor = fopen("Autor.dat", "rb");

    if(pAutor == nullptr)
    {
        //cout << "No se pudo leer el archivo." << endl;
        return 0;
    }

    fseek(pAutor,0,SEEK_END);
    int tamanio = ftell(pAutor);
    fclose(pAutor);
    cantRegistosAutor = tamanio/sizeof(Autor);

    return cantRegistosAutor ;
}

void ArchivoAutor::obtenerVectorAutores(int cantRegistros, Autor *vecAutor)   // este es el que lista.
{
    FILE* pAutor;
    pAutor = fopen("Autor.dat", "rb");
    if(pAutor == nullptr)
    {
        cout << "No se pudo leer el archivo." << endl;
        return;
    }

    for(int x=0; x<cantRegistros; x++)
    {
        fread(&vecAutor[x],sizeof(Autor),1,pAutor);
    }

    fclose(pAutor);
}

int ArchivoAutor:: buscarAutorPorNombre(char nombre []){

    Autor autor;
    FILE *pAutor;
    pAutor=fopen("Autor.dat","rb");

    if(pAutor==nullptr)
    {
        ///cout<<"ERROR DE ARCHIVO"<<endl;
        return -2;
    }

    int pos=0;
    while(fread(&autor,sizeof(Autor),1,pAutor)==1)
    {
        cout<<"NOMBRE: "<<autor.getNombre()<<endl;
        if(strcmp(autor.getNombre(), nombre) == 0 )
        {
            return pos;
        }
        pos++;
    }

    fclose(pAutor);
    return -1;
}


Autor ArchivoAutor::obtenerAutorArchivo(int pos)
{
    Autor autor;
    FILE *pAutor;
    pAutor=fopen("Autor.dat","rb");
    autor.setCodAutor(-1);
    if(pAutor==nullptr)   ///NULL
    {
        /// cout<<"ERROR DE ARCHIVO"<<endl;
        return autor;
    }

    fseek(pAutor,pos*sizeof(autor),0);
    fread(&autor, sizeof(autor),1,pAutor);
    fclose(pAutor);
    return autor;
}

bool ArchivoAutor::existeCodigoAutor(int codAutor){
    FILE * pArchivoAutor;
    Autor a1;

    pArchivoAutor = fopen("Autor.dat","rb");

    if(pArchivoAutor == nullptr){
        return false;
    }

    while((fread(&a1,sizeof(Autor),1,pArchivoAutor))== 1){
        if(a1.getCodAutor() == codAutor && a1.getEstado() == true){
           fclose(pArchivoAutor);
           return true;
           }
    }

    fclose(pArchivoAutor);
    return false;
}

Autor ArchivoAutor::obtenerAutorPorCodigo(int codAutor)
{
    int cantReg;
    Autor *vecAutor = nullptr;
    Autor autorObtenido;
    autorObtenido.setCodAutor(-1);

    cantReg = contarRegistrosAutor();
    vecAutor = new Autor[cantReg];

    obtenerVectorAutores(cantReg, vecAutor);
    for(int x=0; x<cantReg; x++)
    {
        if(vecAutor[x].getCodAutor()==codAutor && vecAutor[x].getEstado() == true)
        {
            autorObtenido = vecAutor[x];
            autorObtenido.setPosicion(x);
            break;
        }
    }

    delete[]vecAutor;
    return autorObtenido;
}

int ArchivoAutor::modificarArchivoAutor(Autor autor)
{
    FILE *pAutor;
    pAutor=fopen("Autor.dat","rb+");
    if(pAutor==nullptr)
    {
        return -1;
    }

    fseek(pAutor, autor.getPosicion()*sizeof(autor),0);
    int escribio=fwrite(&autor, sizeof(autor),1,pAutor);

    fclose(pAutor);
    return escribio;
}
 bool ArchivoAutor::bajaArchivoAutor(int codigo)
{
    Autor autor;
    autor =obtenerAutorPorCodigo(codigo);
    if(autor.getCodAutor()==-1)
    {
        return false;
    }
    autor.setEstado(false);
    return modificarArchivoAutor(autor);
}
