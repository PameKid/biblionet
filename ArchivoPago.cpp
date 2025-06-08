#include <iostream>
#include "ArchivoPagos.h"

using namespace std;

int ArchivoPagos::AgregarArchivoPago(Pagos pagonuevo){
    FILE* ppago;

    ppago = fopen("pago.dat", "ab");

    if(ppago == nullptr){
        cout << "no se pudo abrir el archivo." << endl;
        return -1;
    }

    fwrite(&pagonuevo, sizeof(Pagos),1,ppago);
    fclose(ppago);

    return 2;
}

int ArchivoPagos::leerArchivo(){
    Pagos p1;
    FILE* ppago;

    ppago = fopen("pago.dat","rb");

    if(ppago == nullptr){
        cout << "no se pudo leer el archivo." << endl;
        return -1;
    }

    while((fread(&p1,sizeof(Pagos),1,ppago))== 1){
        if(p1.getEstado() == true){

            p1.mostrarDatos();
        }
    }

    fclose(ppago);
}
