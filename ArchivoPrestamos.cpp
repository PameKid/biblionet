#include "ArchivoPrestamos.h"

int ArchivoPrestamo:: agregarArchivoPrestamo(Prestamo prestamonuevo){
    FILE *pPrestamo;

    pPrestamo = fopen("prestamos.dat","ab");

    if(pPrestamo == nullptr){
        cout << "No se pudo abrir el archivo" << endl;
        return -1; //regresa -1 si no se pudo abrir
    }

    fwrite(&prestamonuevo, sizeof(Prestamo),1,pPrestamo);
    fclose(pPrestamo);

    return 2; //regresa 2 si se guardó correctamente

}
int ArchivoPrestamo::leerArchivoPrestamos(){
    Prestamo p1;
    FILE* pPrestamo;

    pPrestamo = fopen("prestamos.dat", "rb");

    if(pPrestamo == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return -1;
    }

    while((fread(&p1,sizeof(Prestamo),1,pPrestamo))== 1){
        if(p1.getEstado() == true){

        p1.mostrarInfo();
        }
    }
    fclose(pPrestamo);
}

int ArchivoPrestamo::contarRegistrosdePrestamos(){
    FILE* pPrestamo;

    pPrestamo = fopen("Prestamos.dat", "rb");

    if(pPrestamo == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return -1;
    }

    fseek(pPrestamo,0,SEEK_END);
    int tamanio = ftell(pPrestamo);
    fclose(pPrestamo);

    int cantRegistosPrestamos;

    cantRegistosPrestamos = tamanio/sizeof(Prestamo);

}

void ArchivoPrestamo::buscarArchivoPrestamoPorCodigo(){}
//int ArchivoPrestamo:: modificarArchivoPrestamo(Prestamo prestamoModificar); preguntar al profe
