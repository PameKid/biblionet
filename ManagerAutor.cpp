#include "ManagerAutor.h"



void ManagerAutor::agregarAutor()
{
    ArchivoAutor archivoAutor;
    int cantReg;
    cantReg = archivoAutor.contarRegistrosAutor();

    Autor nuevoAutor;

    nuevoAutor.cargarAutor();

    nuevoAutor.setCodAutor(cantReg+1);

    archivoAutor.agregarAutor(nuevoAutor);
}
void ManagerAutor::listarAutores()  //mostrar la lista de archivos
{
    ArchivoAutor arhivoAutor;
    int cantReg;
    Autor*vecAutor = nullptr;

    cantReg = arhivoAutor.contarRegistrosAutor();
    vecAutor = new Autor[cantReg];

    arhivoAutor.obtenerVectorAutores(cantReg, vecAutor);
    for(int x=0; x<cantReg; x++)
    {
        cout<<"cantidad registros: " << cantReg << endl;
        vecAutor[x].mostrarInfo();
    }

    delete[]vecAutor;
}
