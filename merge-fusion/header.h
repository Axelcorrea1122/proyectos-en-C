#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Verdadero 1
#define Falso 0
typedef struct
{
    char cod[11];
    int stock;
    float precio;
}TProductos;

typedef struct
{
    char cod[11];
    int cantprod;
}TMov;

int miStrCmp(char *cad1,char *cad2);
void miStrCpy(char *cad1,char *cad2);
int compararProd(TProductos *prod,TMov *mov);
void cargarEnArchivo2(TMov movVec[],int ce);
void cargarEnArchivo(TProductos prodVec[],int ce);
void generarArchivo(TProductos prodVec[],int ce);
void generarArchivo2(TMov movVec[],int ce);
int compararProd(TProductos *prod,TMov *mov);





#endif // HEADER_H_INCLUDED
