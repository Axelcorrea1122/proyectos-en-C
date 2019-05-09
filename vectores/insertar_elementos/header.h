#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


void eliminarElemVec(int *vec, int ce, int pos );
/*
    *Elimina un elemento segun la posicion indicada
        se debe decrementar la cantidad de elementos.
*/

void intercambiarInts(int *a,int *b);

int * busquedaMenor(const int *d, const int *h);

void ordSeleccionAsc(int *v, int ce);

void insertarElem(int *vec, int ce, int Elem, int pos);



void insertarElemOrdenadoAscVec(int *vec, int ce, int Elem, int pos);
/*
    *Se inserta un elemento segun la posicion indicada y se
        incrementa automaticamente la cantidad de elementos
        dentro de la funcion.
*/


#endif // HEADER_H_INCLUDED
