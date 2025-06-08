#include "ManagerPrestamo.h"
#include "ArchivoLibro.h"
#include "ArchivoSocio.h"

void ManagerPrestamo::cargarPrestamo(Prestamo objetoPrestamo){
    //variables auxiliares
    int codigoLibro;
    int codigoPrestamo;
    int codigoSocio;
    Fecha fechaPrestamo;

    bool existeLibro; //se guarda el resultado de la validacion
    ArchivoLibro archiLibro; //para el metodo para validar el codigo

    bool existeSocio;
    ArchivoSocio archiSocio;


    cout << "NUEVO PRÉSTAMO " << endl;
    cout << "***************" << endl;

    //carga de fecha actual
    fechaPrestamo.cargarFechaActual();
    objetoPrestamo.setFechaEntrega(fechaPrestamo);
    fechaPrestamo.mostrarFecha();

    //carga y creacion del codigo prestamo: concatenar cod libro, codsocio y fecha
    cout << "Ingrese el código del prestamo: " << endl;
    cin >> codigoPrestamo;
    objetoPrestamo.setCodPrestamo(codigoPrestamo);


    cout << "Ingrese el código del libro: " << endl;
    cin >> codigoLibro;

    existeLibro = archiLibro.existeLibro(codigoLibro);

    while (existeLibro == false){
        cout << "El código ingresado no existe, intente con otro: " << endl;
        cin >> codigoLibro;
        existeLibro = archiLibro.existeLibro(codigoLibro);
    }


    //todo ok settea el codigo en el objeto
    objetoPrestamo.setCodLibro(codigoLibro);

    cout << "Ingrese el codigo del socio:  " << endl;
    cin >> codigoSocio;

    existeSocio = archiSocio.existeSocio(codigoSocio);

    while(existeSocio == false){
        cout << "El codigo ingresado no existe, intente con otro: " << endl;
        cin >> codigoSocio;
        existeSocio = archiSocio.existeSocio(codigoSocio);
    }

    //todo ok settea el objeto Prestamo
    objetoPrestamo.setCodSocio(codigoSocio);


    cout << "Los datos fueron guardados correctamente: " << endl;


//aca se debería llamar a una funcion para que calcule y muestre la fecha de devolucion.
// _fechaDevolucion;
}

void ManagerPrestamo::altaPrestamo(){
    ArchivoPrestamo archivoPrestamo;
    Prestamo p1;

    cargarPrestamo(p1);
    archivoPrestamo.agregarArchivoPrestamo(p1);

    //acá se debería interactuar con libro y restar un ejemplar hasta la fecha de devolucion.

}
void ManagerPrestamo::listarPrestamosActivos(){
    ArchivoPrestamo archiPrestamo;

    cout << "Listado de préstamos activos: " << endl;

    cout << "****************************************" << endl;
    archiPrestamo.leerArchivoPrestamos();

    system("pause");
}


void ManagerPrestamo::contarPrestamosActivos(){}
void ManagerPrestamo::buscarPrestamosCodigo(){}
void ManagerPrestamo::devolucionPrestamo(){} //guardo la fecha de devolucion
void ManagerPrestamo::modificarDatosDelPrestamo(){}; //preguntar si es necesario
Prestamo ManagerPrestamo:: obtenerPrestamoPorCodigo(int codPrestamo){}

