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

    return 2; //regresa 2 si se guard� correctamente

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

    if(pPrestamo==nullptr)
    {
        return false;
    }
    while(fread(&prestamo,sizeof(prestamo),1,pPrestamo)==1)
    {
        if(prestamo.getCodSocio() == codSocio && prestamo.getDevuelto())
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

int ArchivoPrestamo::cantidadLibrosPorSocio(int codSocio){
    FILE* pPrestamo;
    Prestamo p1;
    int contadorDePrestamos = 0;

    pPrestamo = fopen("Prestamos.dat", "rb");

    if(pPrestamo == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return -1;
    }

    while((fread(&p1,sizeof(Prestamo),1,pPrestamo))== 1){
        if(p1.getCodSocio() == codSocio && p1.getDevuelto()== false){
            contadorDePrestamos++;
        }
    }
    fclose(pPrestamo);
    return contadorDePrestamos;
}

Prestamo ArchivoPrestamo::obtenerPrestamoPorPosicion(int posicion){

    FILE* pPrestamo;
    Prestamo p1;


    pPrestamo = fopen("Prestamos.dat","rb");

    if(pPrestamo == nullptr){
        cout << "No se pudo leer el archivo." << endl;
        return p1 ; //devuelve p1 vacio
    }

    fseek(pPrestamo,sizeof(Prestamo)*posicion,0);

    fread(&p1,sizeof(Prestamo),1,pPrestamo);

    return p1;
}

bool ArchivoPrestamo::consultarPenalidades(int codSocio, int mesPagado){
    FILE* pPrestamo;
    Prestamo p1;

    pPrestamo = fopen("Prestamos.dat","rb"); // nombre correcto del archivo

    if(pPrestamo == nullptr){
        cout << "No se pudo leer el archivo de pr�stamos." << endl;
        return false;
    }

    while((fread(&p1,sizeof(Prestamo),1,pPrestamo)) == 1){
        if(p1.getCodSocio() == codSocio && p1.getFechaPrestamo().getMes() == mesPagado - 1){
            if(p1.devolucionVencida(p1.getFechaVencimiento(), p1.getFechaDevolucion())){
                cout << " Penalidad detectada: devoluci�n fuera de t�rmino" << endl;
                return true;
            }
        }
    }

    fclose(pPrestamo);
    return false;
}

