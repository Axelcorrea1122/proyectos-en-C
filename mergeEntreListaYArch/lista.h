#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define NO_SE_ENCONTRO_ELEM NULL
#define SIN_MEM 1
#define TODO_OK 0
#define ERROR_ARCH 1
#include <string.h>
#include <conio.h>
typedef int(*tCmp)(const void*, const void*);
typedef int(*tActualizador)(void*, const void*);

typedef struct
{
    char nombre[10];
    int movi;
}tMovi;



typedef struct
{
    char nombre[10];
    int stock;
    float precio;
}tProducto;

typedef tMovi tInfo;


typedef struct sNodo
{
        tInfo           info;
        struct sNodo    *sig;
}tNodo;
typedef tNodo *tLista;

int cmpProd(const void *elem1,const void *elem2);
int actualizarStock(FILE *stockF,tLista *movL,tCmp cmpProd);
int resumirMov( FILE *movF, tLista *movL);

int updProducto(void *actualizado,const void *actualizador);
int insertarEnListaOrd(tLista *p,tInfo *d,tCmp cmpxClave,tActualizador updProd);
typedef int(*tCmp)(const void*, const void*);
void ponerAlFinalLista(tLista *p, tInfo *d);
int listaLlena(tLista *list);
void crearLista(tLista *list);
void ponerAlInicioLista(tLista *p, tInfo *d);
void ponerxPosicionLista(tLista *p, tInfo *d, int pos);
tInfo* buscarxPosicionLista(tLista *p, tInfo*d,int pos);
tInfo* buscarxClaveLista(tLista *p, tInfo *clave,tInfo *d, tCmp cmpxClave);
int cmpMov(const void *elem1,const void *elem2);
#endif // LISTA_H_INCLUDED
