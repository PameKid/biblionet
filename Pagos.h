#ifndef PAGOS_H_INCLUDED
#define PAGOS_H_INCLUDED
#endif // PAGOS_H_INCLUDED
using namespace std;
#include <iostream>
#include "fecha.h"
#include "socio.h"

class Pagos{

private:

    int _codSocio;
    int _codPago;
    Fecha _fechaDePago;
    int _mesPagado;
    int _anioPagado;
    float _importe;
    bool _estado = true;

public:

    void setCodSocio(int codSocio);
    void setCodPago(int codPago);
    void setFechaDePago(Fecha fechaDePago);
    void setMesPagado(int mesPagado);
    void setAnioPagado(int anioPagado);
    void setImporte(float importe);
    void setEstado(bool estado);

    int getCodSocio();
    int getCodPago();
    Fecha getFechaDePago();
    int getMesPagado();
    int getAnioPagado();
    float getImporte();
    bool getEstado();

    void cargarPago();
    void mostrarDatos();
    bool estaAlDia();
};
