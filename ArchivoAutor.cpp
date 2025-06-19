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

bool ArchivoAutor :: compararNombres(const char* nombre1, const char* nombre2)
{
    while (*nombre1 && *nombre2 )
    {
        if (tolower(*nombre1) != tolower(*nombre2))
        {
            return false;
        }
        nombre1++;
        nombre2++;
    }
    if(*nombre1 == *nombre2)
    {
        return true;
    }
    return false;
}

int ArchivoAutor:: buscarAutorPorNombre(char nombre [], int vecPosiciones[])
{

    Autor autor;
    FILE *pAutor;
    pAutor=fopen("Autor.dat","rb");

    if(pAutor==nullptr)
    {
        return -2;
    }

    int pos=0;
    int cantidadAutores = 0;
    while(fread(&autor,sizeof(Autor),1,pAutor)==1)
    {
        if(compararNombres(autor.getNombre(), nombre))
        {
            vecPosiciones[cantidadAutores]= pos;
            cantidadAutores++;
        }
        pos++;
    }

    fclose(pAutor);
    return cantidadAutores;
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

bool ArchivoAutor::existeCodigoAutor(int codAutor)
{
    FILE * pArchivoAutor;
    Autor a1;

    pArchivoAutor = fopen("Autor.dat","rb");

    if(pArchivoAutor == nullptr)
    {
        return false;
    }

<<<<<<< HEAD
    while((fread(&a1,sizeof(Autor),1,pArchivoAutor))== 1){
        if(a1.getCodAutor() == codAutor && a1.getEstado() == true){
           fclose(pArchivoAutor);
           return true;
           }
=======
    while((fread(&a1,sizeof(Autor),1,pArchivoAutor))== 1)
    {
        if(a1.getCodAutor() == codAutor)
        {
            fclose(pArchivoAutor);
            return true;
        }
>>>>>>> 42c5a8ff62f60324cd1eece3b04dd4de2af4eee3
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
