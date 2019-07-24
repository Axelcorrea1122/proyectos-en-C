#include "pilas.h"

void crearPila(tPila *p)
{
    *p = NULL;
}

int pilaLlena(const tPila *p)
{
    tNodo *aux = (tNodo *)malloc(sizeof(tNodo));
    free(aux);
    return aux == NULL;
}


int ponerEnPila(tPila *p, const tInfo *d)
{
    tNodo *nue = (tNodo *)malloc(sizeof(tNodo));
    if(nue == NULL)
    {
        return 0;
    }
    nue->info = *d;
    nue->sig = *p;
    *p = nue;
    return 1;
}

int verTope(const tPila *p, tInfo *d)
{
    if(*p == NULL)
    {
        return 0;
    }
    *d = (*p)->info;
    return 1;
}

int pilaVacia(const tPila *p)
{
    return *p == NULL;
}


void vaciarPila(tPila *p)
{

    while(*p)
    {
        tNodo *aux = *p;
        *p = aux->sig;
        free(aux);
    }
}

int sacarDeLaPila(tPila *p, tInfo *d)
{
    tNodo *aux = *p;
    if(aux == NULL)
    {
        return 0;
    }
    *p = aux->sig;
    *d = aux->info;
    free(aux);
    return 1;
}
