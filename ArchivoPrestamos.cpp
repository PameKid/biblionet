#include "ArchivoPrestamos.h"

int ArchivoPrestamo:: agregarArchivoPrestamo(Prestamo prestamonuevo)
{
    FILE *pPrestamo;

    pPrestamo = fopen("Prestamos.dat","ab");

    if(pPrestamo == nullptr)
    {
        cout << "No se pudo abrir el archivo" << endl;
        return -1; //regresa -1 si no se pudo abrir
    }
    prestamonuevo.setEstado(true);
    fwrite(&prestamonuevo, sizeof(Prestamo),1,pPrestamo);
    fclose(pPrestamo);

    return 2; //regresa 2 si se guardó correctamente

}

int ArchivoPrestamo::leerArchivoPrestamos()
{
    Prestamo p1;
    FILE* pPrestamo;

    pPrestamo = fopen("Prestamos.dat", "rb");

    if(pPrestamo == nullptr)
    {
        cout << "No se pudo leer el archivo." << endl;
        return -1;
    }

    while((fread(&p1,sizeof(Prestamo),1,pPrestamo))== 1)
    {
        if(p1.getEstado() == true)
        {
            p1.mostrarInfo();
        }
    }
    fclose(pPrestamo);
}

int ArchivoPrestamo::contarRegistrosdePrestamos()
{
    FILE* pPrestamo;

    pPrestamo = fopen("Prestamos.dat", "rb");

    if(pPrestamo == nullptr)
    {
        cout << "No se pudo leer el archivo." << endl;
        return -1;
    }

    fseek(pPrestamo,0,SEEK_END);
    int tamanio = ftell(pPrestamo);
    fclose(pPrestamo);

    int cantRegistosPrestamos;

    cantRegistosPrestamos = tamanio/sizeof(Prestamo);

    return cantRegistosPrestamos;
}

Prestamo ArchivoPrestamo::devolverArchivoPrestamoPorCodigo(char* codigoPrestamo){
    Prestamo p1;
    Prestamo prestamoVacio;
    FILE* pPrestamo;


    pPrestamo = fopen("Prestamos.dat", "rb");

    if(pPrestamo == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return p1;
    }

    while((fread(&p1,sizeof(Prestamo),1,pPrestamo))== 1){
        if(strcmp(codigoPrestamo,p1.getCodPrestamo()) == 0){ //devuelve 0 si son iguales
            fclose(pPrestamo);
            return p1;
        }
     fclose(pPrestamo);
     return prestamoVacio;

    }
}


//void ArchivoPrestamo::buscarArchivoPrestamoPorCodigo() {}

//int ArchivoPrestamo:: modificarArchivoPrestamo(Prestamo prestamoModificar); preguntar al profe

//Metodo para la validacion de la baja de socio (socio moroso))

bool ArchivoPrestamo :: prestamoInconclusoPorSocio(int codSocio)
{
    Prestamo prestamo;
    FILE *pPrestamo;
    pPrestamo = fopen("Prestamos.dat","rb");
    Fecha fechaVacia;

    if(pPrestamo==nullptr)
    {
        return false;
    }
    while(fread(&prestamo,sizeof(prestamo),1,pPrestamo)==1)
    {
        if(prestamo.getCodSocio() == codSocio && prestamo.getEstado())
        {
            return true;
        }

    }

    fclose(pPrestamo);
    return false;
}

int ArchivoPrestamo::buscarPosicionPrestamo(Prestamo prestamo){

    int cantidadRegistros;
    int posicion;
    FILE* pPrestamo;
    Prestamo p1;

    cantidadRegistros = contarRegistrosdePrestamos();

    pPrestamo = fopen("Prestamos.dat","rb");

    if(pPrestamo == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return -1;
    }

    for(int x = 0; x < cantidadRegistros; x++){
        fread(&p1,sizeof(Prestamo),1,pPrestamo);
        if(strcmp(p1.getCodPrestamo(), prestamo.getCodPrestamo())== 0){
            return x;
        }
    }
    return -1;
}

int ArchivoPrestamo:: modificarArchivoPrestamo(Prestamo prestamoModificar){
    FILE* pArchivoPrestamo;
    int posicion;

    pArchivoPrestamo = fopen("Prestamos.dat", "rb+");

    if(pArchivoPrestamo == nullptr){
        return -1;
    }

    posicion = buscarPosicionPrestamo(prestamoModificar);
    fseek(pArchivoPrestamo,sizeof(Prestamo)*posicion,0);

    int prestamoDesactivado = fwrite(&prestamoModificar,sizeof(Prestamo),1,pArchivoPrestamo);
    fclose(pArchivoPrestamo);

    return prestamoDesactivado;
}

