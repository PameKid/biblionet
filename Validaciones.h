#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

int ingresarCodSocio();
int ingresarMes();
int ingresarAnio(int anioActual);
float ingresarImporte();
bool existePago(int codsocio, int mes, int anio);

#endif // VALIDACIONES_H_INCLUDED
