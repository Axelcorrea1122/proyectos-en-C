#include "header.h"
#include "include/arbol.h"
int accion(const void *ele, const void *datocc);
int cmpPL(const void *e1,const void *e2);

int main()
{
    tPlazoFijo plazo;






    return 0;
}




void cargarEnArbol(tArbol *pa,FILE *pfpl)
{
    tPlazoFijo plazo;
    long cr=0;
    while(fscanf(pfpl,"%d|%d|%f|%f|%d/%d/%d|%d",&plazo.nroPL,&plazo.nrocuenta,&plazo.saldo,&plazo.interes,&plazo.fechaConstitucion.di,&plazo.fechaConstitucion.me,&plazo.fechaConstitucion.an,&plazo.dias)!=EOF)
    {
        cr++;
    }

    fseek(pfpl,2*sizeof(tPlazoFijo)+3,SEEK_SET);

    fscanf(pfpl,"%d|%d|%f|%f|%d/%d/%d|%d",&plazo.nroPL,&plazo.nrocuenta,&plazo.saldo,&plazo.interes,&plazo.fechaConstitucion.di,&plazo.fechaConstitucion.me,&plazo.fechaConstitucion.an,&plazo.dias);
    ingresarEnArbol(pa,&plazo,cmpPL);
    fseek(pfpl,0,SEEK_SET);

    while(fscanf(pfpl,"%d|%d|%f|%f|%d/%d/%d|%d",&plazo.nroPL,&plazo.nrocuenta,&plazo.saldo,&plazo.interes,&plazo.fechaConstitucion.di,&plazo.fechaConstitucion.me,&plazo.fechaConstitucion.an,&plazo.dias)!=EOF)
    {
        ingresarEnArbol(pa,&plazo,cmpPL);
    }


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


int accion(const void *ele, const void *datocc)
{
    tPlazoFijo *dato = (tPlazoFijo*)ele;

    printf("\n%d - %d - %f - %f",dato->nroPL,dato->nrocuenta,dato->interes,dato->saldo);

    return 0;
}


