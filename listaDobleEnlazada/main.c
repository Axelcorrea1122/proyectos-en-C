#include "listaDoble.h"

int cmpxNroCuentaPF(const void *e1,const void *e2);



int main()
{
    FILE *pf = fopen("PlazosFijos.txt","r");

    tListaDoble listadoble;
    tPlazoFijo plazo;
    int codret, ce=0;
    crearListaDoble(&listadoble);

    while(fscanf(pf,"%d|%d|%f|%f|%d/%d/%d|%d",&plazo.nroPF,&plazo.cuenta,&plazo.monto,&plazo.interesAnual,&plazo.fechaConstitucion.d,&plazo.fechaConstitucion.m,&plazo.fechaConstitucion.a,&plazo.dias) != EOF)
    {
        codret = ingresarEnListaDobleOrd(&listadoble,&plazo,cmpxNroCuentaPF);

        if(codret)
            exit(1);
        ce++;
    }

    tPlazoFijo aux;
    aux.cuenta = 500;
    ingresarAlInicioListaDoble(&listadoble, &aux);
    tPlazoFijo aux2;
    tInfo *otro = sacarPrimeroListaDoble(&listadoble, &aux2);

    printf("\n%d - %d - %f",otro->nroPF,otro->cuenta,otro->monto);


    return 0;
}


int cmpxNroCuentaPF(const void *e1,const void *e2)
{
    tPlazoFijo *E1 = (tPlazoFijo*)e1;
    tPlazoFijo *E2 = (tPlazoFijo*)e2;

    if(E1->cuenta>E2->cuenta)
        return 1;
    if(E1->cuenta==E2->cuenta)
        return 0;
    return -1;

}
