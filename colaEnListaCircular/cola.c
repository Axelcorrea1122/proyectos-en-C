#include "cola.h"
#include "defs.h"
void crearColaCircular(tColaCircular *pc)
{
    *pc = NULL;

}

int encolar(tColaCircular *pc, tInfo *d)
{
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEM;
    nue->info = *d;

    if(!*pc)
    {
        *pc = nue;
        nue->sig = nue;
    }
    else
    {
        nue->sig = *pc;
        (*pc)->sig = nue;
        *pc = nue;
    }
    return 0;

}

tInfo desencolar(tColaCircular *pc, tInfo *d)
{
    tNodo *aux;
    if((*pc)->sig == *pc)
    {
        aux = *pc;
        *d = aux->info;
        *pc = NULL;
    }
    else
    {
        aux = (*pc)->sig;
        *d = aux->info;
        (*pc)->sig = aux->sig;
    }
    free(aux);
    return *d;
}

int colaVacia(tColaCircular *pc)
{
    return *pc == NULL;
}


void vaciarCola(tColaCircular *pc)
{
    tNodo *nae;

    while(!colaVacia(pc))
    {
        if((*pc)->sig == *pc)
        {
            nae = *pc;

            *pc = NULL;
        }
        else
        {
            nae = (*pc)->sig;
            (*pc)->sig = nae->sig;
        }
        free(nae);
    }
}
