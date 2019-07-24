#include "lista.h"

void crearLista(tLista *p)
{
    *p = NULL;
}


int listaLlena(tLista *p)
{
    tNodo *aux = (tNodo*)malloc(sizeof(tNodo));
    free(aux);
    return aux == NULL;

}

void ponerAlFinalLista(tLista *p, tInfo *d)
{
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    while(*p)
    {
        p = &(*p)->sig;
    }
    nue->info = *d;
    nue->sig = *p;
    *p = nue;

}

void ponerAlInicioLista(tLista *p, tInfo *d)
{
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    nue->info = *d;
    nue->sig = *p;
    *p = nue;
}

void ponerxPosicionLista(tLista *p, tInfo *d, int pos)
{
    int i=0;
    while(*p && i<pos-1)
    {
        p=&(*p)->sig;
        i++;
    }
    tNodo *nue=(tNodo*)malloc(sizeof(tNodo));
    nue->sig=*p;
    *p=nue;

}

tInfo* buscarxPosicionLista(tLista *p, tInfo *d,int pos)
{
    int i=0;
    if(pos==1)
    {
        *d = (*p)->info;
        return d;
    }

    while(*p && i<pos-1)
    {
        p=&(*p)->sig;
        i++;
    }
    if(!*p)
    {
        return NO_SE_ENCONTRO_ELEM;
    }
    *d=(*p)->info;
    return d;


}

tInfo* buscarxClaveLista(tLista *p, tInfo *clave, tInfo *d, tCmp cmpxClave) //definir el el tipedef de la funcion cmp
{

    while(*p && cmpxClave(clave,&(*p)->info)!=0)
    {
        p=&(*p)->sig;
    }
    if(!*p)
    {
        return NO_SE_ENCONTRO_ELEM; // definir esta macro
    }
    *d=(*p)->info;
    return d;

}

int cmpProd(const void *elem1,const void *elem2)
{
    tProducto *e1=(tProducto*)elem1;
    tMovi *e2=(tInfo*)elem2;

    return strcmp(e1->nombre,e2->nombre);
}


int insertarEnListaOrd(tLista *p,tInfo *d,tCmp cmpMov,tActualizador updProducto)
{
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
    {
        return SIN_MEM;
    }

    while(*p && cmpMov(d,&(*p)->info)>0)
    {
        p = &(*p)->sig;
    }

    if(cmpMov(d,&(*p)->info) == 0)
    {
        int codret = updProducto(&(*p)->info,d);
        return codret;
    }
    nue->info = *d;
    nue->sig = *p;
    *p = nue;

    return 0;

}



int updProducto(void *pactualizado,const void *pactualizador)
{
    tMovi *actualizado = (tMovi*)pactualizado;
    tMovi *actualizador = (tMovi*)pactualizador;

    actualizado->movi += actualizador->movi;

    return TODO_OK;
}


