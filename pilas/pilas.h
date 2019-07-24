#ifndef PILAS_H_INCLUDED
#define PILAS_H_INCLUDED

#include <stdlib.h>
#include "definiciones.h"

typedef struct sNodo
{
    tInfo          info;
    struct sNodo  *sig;
} tNodo;
typedef tNodo *tPila;



int sacarDeLaPila(tPila *p, tInfo *d);
void vaciarPila(tPila *p);
int pilaVacia(const tPila *p);
int verTope(const tPila *p, tInfo *d);
int ponerEnPila(tPila *p, const tInfo *d);
int pilaLlena(const tPila *p);
void crearPila(tPila *p);
#endif // PILAS_H_INCLUDED
