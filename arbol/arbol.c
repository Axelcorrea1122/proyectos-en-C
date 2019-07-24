#include "include/arbol.h"


void crearArbol(tArbol *pa)
{
    *pa = NULL;
}

int ingresarEnArbol(tArbol *pa,tPlazoFijo *plazo,tCmp cmp)
{
    if(!*pa)
    {
        *pa = (tNodo_a*)malloc(sizeof(tNodo_a));
        if(!*pa)
            return SIN_MEM;

        (*pa)->info = *plazo;
        (*pa)->hizq = (*pa)->hder = NULL;
        return TODO_OK;
    }
    int comp = cmp(plazo, &(*pa)->info);

    if(comp == 0)
        return DUPLICADO;
    if(comp > 0)
        return ingresarEnArbol(&(*pa)->hder,plazo,cmp);
    else
        return ingresarEnArbol(&(*pa)->hizq,plazo,cmp);
}


tNodo_a** buscarNodoArbol(tArbol *pa, tPlazoFijo *plazo, tCmp cmp)
{
    if(!*pa)
        return NO_SE_ENCON;

    int comp = cmp(plazo,&(*pa)->info);

    if(comp == 0)
        return pa;

    if(comp < 0)
        return buscarNodoArbol(&(*pa)->hizq,plazo,cmp);

    return buscarNodoArbol(&(*pa)->hder,plazo,cmp);

}

int alturaDeArbol(tArbol *pa)
{
    if(!*pa)
        return 0;

    int hi = alturaDeArbol(&(*pa)->hizq);
    int hd = alturaDeArbol(&(*pa)->hder);

    return (hi>hd ? hi : hd)+1;
}

int eliminarDelArbol(tArbol *pa, tInfo *d, tCmp cmp)
{
    tNodo_a **pnae = buscarNodoArbol(pa, d, cmp);
    if(!pnae)
        return FALSO;
    *d = (*pnae)->info;
    eliminarNodo(pnae);
    return VERDADERO;
}

void eliminarNodo(tNodo_a **pnae)
{
    if(!(*pnae)->hizq && !(*pnae)->hder)
    {
        free(*pnae);
        *pnae = NULL;
        return;
    }

    int hi = alturaDeArbol(&(*pnae)->hizq);
    int hd = alturaDeArbol(&(*pnae)->hder);

    tNodo_a **pnreempl = hi > hd ? mayor(&(*pnae)->hizq): mayor(&(*pnae)->hder);
    (*pnae)->info = (*pnreempl)->info;

    eliminarNodo(pnreempl);
}




tNodo_a ** mayor(tArbol *pa)
{
    return pa;
}


int podarArbol(tArbol *pa, int nivel)
{
    if(!*pa)
        return 0;
    if(nivel == 0)
        vaciarArbol(pa);
    return podarArbol(&(*pa)->hizq,nivel -1) + podarArbol(&(*pa)->hder, nivel -1);
}

int vaciarArbol(tArbol *pa)
{
    if(!*pa)
        return 0;
    int cn = vaciarArbol(&(*pa)->hizq);
    cn += vaciarArbol(&(*pa)->hder);

    free(*pa);
    *pa = NULL;
    return cn+1;
}


void recorrerArbolPre(tArbol *pa,tAccion accion, void *datoaccion)
{
    if(!*pa)
        return;
    accion(&(*pa)->info, datoaccion);
    recorrerArbolPre(&(*pa)->hizq,accion,datoaccion);
    recorrerArbolPre(&(*pa)->hder,accion,datoaccion);

}

void recorrerArbolEnOrden(tArbol *pa,tAccion accion, void *datoaccion)
{
    if(!*pa)
        return;

    recorrerArbolEnOrden(&(*pa)->hizq,accion,datoaccion);
    accion(&(*pa)->info, datoaccion);
    recorrerArbolEnOrden(&(*pa)->hder,accion,datoaccion);

}

void recorrerArbolPosOrden(tArbol *pa,tAccion accion, void *datoaccion)
{
    if(!*pa)
        return;

    recorrerArbolPosOrden(&(*pa)->hizq,accion,datoaccion);
    recorrerArbolPosOrden(&(*pa)->hder,accion,datoaccion);
    accion(&(*pa)->info, datoaccion);

}

int cantNodosArbol(const tArbol *pa)
{
    if(!*pa)
        return 0;
    return cantNodosArbol(&(*pa)->hizq) + cantNodosArbol(&(*pa)->hder) + 1;
}


int cantNodosArbolHastaNivel(const tArbol *pa, int nivel)
{
    if(!*pa)
        return 0;
    if(nivel == 0)
        return 1;
    return cantNodosArbolHastaNivel(&(*pa)->hizq, nivel-1) +
    cantNodosArbolHastaNivel(&(*pa)->hder, nivel-1) + 1;
}

int esCompletoArbol(tArbol *pa)
{
    int i,cant=1;
    int h = alturaDeArbol(pa);
    for(i=1 ; i<=h ; i++)
        cant *= 2;
    cant--;
    if(cantNodosArbol(pa) == cant)
        return 1;
    else
        return 0;
}

int esBalanceado(tArbol *pa)
{
    int i, cant=1;
    int h = alturaDeArbol(pa) -1;
    for(i=1 ; i<=h ; i++)
        cant *= 2;
    cant--;
    if(cantNodosArbolHastaNivel(pa,h-1) == cant)
        return 1;
    else
        return 0;
}

int esAVL(tArbol *pa)
{
    if(!*pa)
        return VERDADERO;

    int hi= alturaDeArbol(&(*pa)->hizq);
    int hd= alturaDeArbol(&(*pa)->hder);

    if(abs(hi-hd)>1)
        return FALSO;
    return esAVL(&(*pa)->hizq) && esAVL(&(*pa)->hder);
}

char tipoBalanceoArbol(tArbol *pa)
{
    char car;
    if(esAVL(pa))
        car='A';
    if(esBalanceado(pa))
        car='B';
    if(esCompletoArbol(pa))
        car='C';

    return car;
}


int insertarEnArbolBalanceado(tArbol *pa, tAccion accion, void *datoAccion, tInfo *d)
{


}
