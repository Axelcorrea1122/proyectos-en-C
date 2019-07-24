#include "header.h"
#include "include/arbol.h"
int cmpPL(const void *e1,const void *e2);

int main()
{
    tArbol arbol2;

    crearArbol(&arbol2);

    tPlazoFijo plazo1;
    plazo1.nroPL=2;
    plazo1.nrocuenta=5000;
    plazo1.saldo=2000.00;
    plazo1.interes=54.00;
    plazo1.fechaConstitucion.di=24;
    plazo1.fechaConstitucion.me=5;
    plazo1.fechaConstitucion.an=2018;
    plazo1.dias=90;

    ingresarEnArbol(&arbol2,&plazo1,cmpPL);

    tPlazoFijo plazo2;
    plazo2.nroPL=1;
    plazo2.nrocuenta=2000;
    plazo2.saldo=2500.00;
    plazo2.interes=40.00;
    plazo2.fechaConstitucion.di=5;
    plazo2.fechaConstitucion.me=3;
    plazo2.fechaConstitucion.an=2019;
    plazo2.dias=30;

    ingresarEnArbol(&arbol2,&plazo2,cmpPL);

    printf("\n%d",alturaDeArbol(&arbol2));





}

int cmpPL(const void *e1,const void *e2)
{
    tPlazoFijo *E1 = (tPlazoFijo*)e1;
    tPlazoFijo *E2 = (tPlazoFijo*)e2;

    if(E1->nroPL == E2->nroPL)
        return 0;
    if(E1->nroPL < E2->nroPL)
        return -1;
    return 1;
}
