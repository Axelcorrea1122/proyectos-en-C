#include "cola.h"

int main()
{
    tColaCircular colaCircular;
    crearColaCircular(&colaCircular);

    FILE *pf = fopen("PlazosFijos.txt","rt");
    tPlazoFijo plazo, otro;
    while( fscanf(pf,"%d|%d|%f|%f|%d/%d/%d|%d",&plazo.nroPL,&plazo.nrocuenta,&plazo.saldo,&plazo.interes,
                  &plazo.fechaConstitucion.di,&plazo.fechaConstitucion.me,&plazo.fechaConstitucion.an,&plazo.dias) != EOF)
    {
        int codret = encolar(&colaCircular, &plazo);
        if(codret)
            exit(1);
    }

    vaciarCola(&colaCircular);
    if(colaVacia(&colaCircular))
        printf("\nSE BORRO LA COLA");
    /*while(!colaVacia(&colaCircular))
    {
        otro = desencolar(&colaCircular,&otro);
        printf("\n%d - %d",otro.nroPL,otro.nrocuenta);
    }*/
    return 0;
}
