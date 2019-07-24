#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int di,
        me,
        an;
}tFecha;

typedef struct
{
    int nroPL;
    int nrocuenta;
    float saldo;
    float interes;
    tFecha fechaConstitucion;
    int dias;
}tPlazoFijo;

#endif // HEADER_H_INCLUDED
