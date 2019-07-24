#ifndef PLAZOFIJO_H_INCLUDED
#define PLAZOFIJO_H_INCLUDED
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

#endif // PLAZOFIJO_H_INCLUDED
