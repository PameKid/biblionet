#ifndef MANAGERPAGO_H_INCLUDED
#define MANAGERPAGO_H_INCLUDED
#include "ArchivoPagos.h"

class ManagerPago{

public:
    void agregarPago(Pagos &p1);
    void altaPago();
    void listarpagos();
    void buscarPagoPorCodigo();
    void listarPagosDelMes();
    Pagos obtenerPagoPorCodigo(int codPago);
};










#endif // MANAGERPAGO_H_INCLUDED
