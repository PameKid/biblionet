#ifndef ARCHIVOPAGOS_H_INCLUDED
#define ARCHIVOPAGOS_H_INCLUDED
#include "Pagos.h"

class ArchivoPagos{

public:

    int AgregarArchivoPago(Pagos pagonuevo);
    int leerArchivo();
    Pagos devolverArchivoPagoPorCodigo(char* codPago);
    void listarPagosDelMes();
    bool socioAlDia(int codSocio) ;


};







#endif // ARCHIVOPAGOS_H_INCLUDED
