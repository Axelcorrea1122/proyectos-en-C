#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "defs.h"
#include "plazosFijos.h"
typedef tPlazoFijo tInfo;

typedef struct nodo
{
    tInfo info;
    struct nodo *sig;
    struct nodo *ant;
}tNodo;

typedef tNodo *tListaDoble;

int esVaciaListaDoble(tListaDoble *pl);
void vaciarListaDoble(tListaDoble *pl);
tInfo* sacarXPosListaDoble(tListaDoble *pl, tInfo *d, int pos);
tInfo* sacarXCampoListaDoble(tListaDoble *pa, tInfo *d, tCmp cmp);
int cantNodos(tListaDoble *pl);
tInfo* sacarPrimeroListaDoble(tListaDoble * pl, tInfo *d);
tInfo* sacarUltimoListaDoble(tListaDoble * pl, tInfo *d);
tNodo* buscarNodoPorPosicionListaDoble(tListaDoble *pl, int pos);
tNodo* buscarNodoPorCampoListaDoble(tListaDoble *pl, tInfo *d, tCmp cmp);
int ingresarAlfinalListaDoble(tListaDoble *pl,tInfo *d);
int ingresarAlInicioListaDoble(tListaDoble *pl, tInfo *d);
void crearListaDoble(tListaDoble *pl);
int ingresarEnListaDobleOrd(tListaDoble *pl,tInfo *d, tCmp cmp);
void mostrarUltimoListaDoble(tListaDoble *pl);



#endif // LISTADOBLE_H_INCLUDED
