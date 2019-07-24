#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED
#include "plazosFijos.h"
#include "defs.h"
#include "strings.h"

typedef struct nodo_a
{
    tInfo info;
    struct nodo_a *hizq;
    struct nodo_a *hder;
}tNodo_a;
typedef tNodo_a *tArbol;

int mostrarNodoArbol(const void *d, const void* dato);
int cargarRaicesEnArbol(tArbol *pa, tListaDoble *pl,tInfo *d, int posini, int fin);
char* tipoBalanceoArbol(tArbol *pa);
int esAVL(tArbol *pa);
int esBalanceado(tArbol *pa);
int esCompletoArbol(tArbol *pa);
int cantNodosArbolHastaNivel(const tArbol *pa, int nivel);
int cantNodosArbol(const tArbol *pa);
void recorrerArbolPosOrden(tArbol *pa,tAccion accion, void *datoaccion);
void recorrerArbolEnOrden(tArbol *pa,tAccion accion, void *datoaccion);
void recorrerArbolPreOrden(tArbol *pa,tAccion accion, void *datoaccion);
int podarArbol(tArbol *pa, int nivel);
int vaciarArbol(tArbol *pa);
tNodo_a ** mayor(tArbol *pa);
void eliminarNodo(tNodo_a **pnae);
int eliminarDelArbol(tArbol *pa, tInfo *d, tCmp cmp);
int alturaDeArbol(tArbol *pa);
void crearArbol(tArbol *pa);
int ingresarEnArbol(tArbol *pa,tPlazoFijo *plazo,tCmp cmpPL);
tNodo_a** buscarNodoArbol(tArbol *pa, tPlazoFijo *plazo, tCmp cmpPL);

#endif // ARBOL_H_INCLUDED
