#ifndef PRODUCTOS_H_INCLUDED
#define PRODUCTOS_H_INCLUDED

#include "stdio.h"
typedef struct
{
    char codprod[11];
    char descrip[46];
}   tProd;

int ingresarProducto(tProd *d);
void mostrarProducto(const tProd *d);

#endif // PRODUCTOS_H_INCLUDED
