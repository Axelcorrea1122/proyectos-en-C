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

int cmpxClave(const void *elem1,const void *elem2)
{
    tInfo *e1=(tInfo*)elem1;
    tInfo *e2=(tInfo*)elem2;

    return strcmp(e1->nombre,e2->nombre);
}


int insertarEnListaOrd(tLista *p,tInfo *d,tCmp cmpxClave,tActualizador updProd)
{
    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
    {
        return SIN_MEM;
    }

    while(*p && cmpxClave(d,&(*p)->info)>0)
    {
        p = &(*p)->sig;
    }

    if(cmpxClave(d,&(*p)->info) == 0)
    {
        int codret = updProd(&(*p)->info,d);
        return codret;
    }
    nue->info = *d;
    nue->sig = *p;
    *p = nue;

    return 0;

}

void mostrarElemLista(tLista *p,tInfo *d)
{

    while(*p)
    {
        *d = (*p)->info;
        p = &(*p)->sig;

        printf("\n%s - %f",d->nombre,d->precio);
    }
}



int updProd(void *pactualizado,const void *pactualizador)
{
    tProd *actualizado = (tProd*)pactualizado;
    tProd *actualizador = (tProd*)pactualizador;

    actualizado->precio = actualizador->precio;

    return TODO_OK;
}

void ordenarListaAsc(tLista *p)
{
    tLista lord;
    tNodo **pm;
    tNodo **pord = lord;

    while(*p)
    {
        pm = buscarMenor(p,cmp);

        *pord = *pm;
        *pm = (*pm)->sig;
        pord = &(*pord)->sig;

        p = &(*p)->sig;
    }
}

tNodo * buscarMenor(tLista *p,tCmp cmp);
{
    tNodo **pm = p;
    p = &(*p)->sig;
    while(*p)
    {
        if(cmp(&(*pm)->info,&(*p)->info) > 0)
            pm = p;
        p = &(*p)->sig;
    }
    return pm;
}

int cmp(void *e1,void *e2)
{
    tNodo *E1 = (tNodo*)e1;
    tNodo *E2 = (tNodo*)e2;

    if(E1->info.precio > E2->info.precio)
        return 1;
    if(E1->info.precio == E2->info.precio)
        return 0;
    return -1;


}
