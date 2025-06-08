#include "Autor.h"
#include "ArchivoAutor.h"


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


