#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include "plazoFijo.h"
#include <stdio.h>
#include <stdlib.h>


typedef tPlazoFijo tInfo;

typedef struct sNodo
{
    tInfo info;
    struct sNodo *sig;
}tNodo;

typedef tNodo *tColaCircular;


void crearColaCircular(tColaCircular *pc);
tInfo desencolar(tColaCircular *pc, tInfo *d);
int encolar(tColaCircular *pc, tInfo *d);
int colaVacia(tColaCircular *pc);
void vaciarCola(tColaCircular *pc);

#endif // COLA_H_INCLUDED
