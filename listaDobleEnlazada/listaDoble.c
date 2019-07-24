#include "listaDoble.h"
#include "Defs.h"
void crearListaDoble(tListaDoble *pl)
{
    *pl = NULL;
}

int ingresarEnListaDobleOrd(tListaDoble *pl,tInfo *d, tCmp cmp)
{
    tNodo *auxsig = *pl,
          *auxant = auxsig ? auxsig->ant:NULL;

    while(auxsig && cmp(d,&(auxsig->info))>0)
    {
        auxant = auxsig;
        auxsig = auxsig->sig;
    }

    while(auxant && cmp(d,&(auxant->info))<0)
    {
        auxsig = auxant;
        auxant = auxant->ant;
    }

    if((auxsig && cmp(d,&(auxsig->info))==0) || (auxant && cmp(d,&(auxant->info))==0))
        return DUPLICADO;

    tNodo *nue = (tNodo*)malloc(sizeof(tNodo));
    if(!nue)
        return SIN_MEM;

    nue->info = *d;
    nue->sig = auxsig;
    nue->ant = auxant;
    if(auxsig)
        auxsig->ant = nue;
    if(auxant)
        auxant->sig = nue;

    *pl = nue;

    return TODO_OK;


}


void mostrarUltimoListaDoble(tListaDoble *pl)
{
    tNodo *auxact = *pl;
    if(!auxact)
        return NULL;

    while(auxact->sig)
        auxact = auxact->sig;

    tInfo d = auxact->info;

    printf("\n%d - %d - %f",d.nroPF,d.cuenta,d.monto);

}

int ingresarAlInicioListaDoble(tListaDoble *pl, tInfo *d)
{
    tNodo *auxact = *pl,
          *auxant = auxact ? auxact->ant:NULL;

    while(auxant) // Al principio hasta que sea nulo
    {
        auxact = auxant;
        auxant = auxant->ant;
    }
    tNodo *nue;
    if(!(nue = (tNodo*)malloc(sizeof(tNodo))))
        return SIN_MEM;
    nue->info = *d;
    nue->sig = auxact;
    nue->ant = auxant;
    if(auxact)
        auxact->ant = nue;

    *pl = nue;

    return TODO_OK;

}

int ingresarAlfinalListaDoble(tListaDoble *pl,tInfo *d)
{
    tNodo *auxact = *pl, *nue,
          *auxant = auxact ? auxact->ant : NULL;

    while(auxact) //Al final hasta que sea nulo
    {
        auxant = auxact;
        auxact = auxact->sig;
    }


    if(!(nue = (tNodo*)malloc(sizeof(tNodo))))
        return SIN_MEM;
    nue->info = *d;
    nue->sig = auxact;
    nue->ant = auxant;
    if(auxant)
        auxant->sig = nue;
    *pl = nue;

    return TODO_OK;
}


tNodo* buscarNodoPorCampoListaDoble(tListaDoble *pl, tInfo *d, tCmp cmp)
{
    tNodo *auxact= *pl;
    if(!auxact)
        return NULL;
    while(auxact->ant)
        auxact = auxact->ant;
    while(auxact && cmp(d,&(auxact->info))!= 0)
        auxact = auxact->sig;
    if(!auxact)
        return NULL;
    else
    {
        *d = auxact->info;
        if(auxact->ant)
            auxact->ant->sig = auxact->sig;
        if(auxact->sig)
            auxact->sig->ant = auxact->ant;
        *pl = auxact->sig ? auxact->sig : auxact->ant;
    }
    return auxact;
}

tNodo* buscarNodoPorPosicionListaDoble(tListaDoble *pl, int pos)
{
    tNodo *auxact = *pl;
    if(!auxact)
        return NULL;
    int i=0;
    while(auxact->ant)
        auxact = auxact->ant;

    while(auxact && i<pos-1)
    {
        auxact = auxact->sig;
        i++;
    }
    return auxact?auxact:NO_SE_ENCON;
}

int cantNodos(tListaDoble *pl)
{
    tNodo *auxact = *pl;
    int c=1;
    if(!auxact)
        return 0;
    while(auxact->ant)
        auxact = auxact->ant;

    while(auxact)
    {
        auxact = auxact->sig;
        c++;
    }

    return c-1;
}

tInfo* sacarUltimoListaDoble(tListaDoble * pl, tInfo *d)
{
    tNodo *auxact = *pl;
    if(!auxact)
        return NULL;
    while(auxact->sig)
        auxact = auxact->sig;
    *d = auxact->info;
    if(auxact->ant)
        auxact->ant->sig=NULL;
    *pl = auxact->ant?auxact->ant:NULL;
    free(auxact);

    return d;
}

tInfo* sacarPrimeroListaDoble(tListaDoble * pl, tInfo *d)
{
    tNodo *auxact = *pl;
    if(!auxact)
        return NULL;
    while(auxact->ant)
        auxact = auxact->ant;
    *d = auxact->info;
    if(auxact->sig)
        auxact->sig->ant = NULL;
    *pl = auxact->sig?auxact->sig:NULL;
    free(auxact);

    return d;
}

tInfo* sacarXCampoListaDoble(tListaDoble *pl, tInfo *d, tCmp cmp)
{
    tNodo *auxact = *pl;
    if(!auxact)
        return NULL;

    while(auxact->ant)
        auxact = auxact->ant;

    while(auxact && cmp(d,&(auxact->info))!=0)
        auxact = auxact->sig;

    if(!auxact)
        return NO_SE_ENCON;
    *d = auxact->info;
    if(auxact->ant)
        auxact->ant->sig = auxact->sig;
    if(auxact->sig)
        auxact->sig->ant = auxact->ant;
    *pl = auxact->sig ? auxact->sig : auxact->ant;
    free(auxact);
    return d;
}

tInfo* sacarXPosListaDoble(tListaDoble *pl, tInfo *d, int pos)
{
    tNodo *auxact = *pl;
    if(!auxact)
        return NULL;
    int i=0;
    while(auxact->ant)
        auxact = auxact->ant;

    while(auxact && i<pos-1)
    {
        auxact = auxact->sig;
        i++;
    }
    if(!auxact)
        return NULL;
    *d = auxact->info;
    if(auxact->ant)
        auxact->ant->sig = auxact->sig;
    if(auxact->sig)
        auxact->sig->ant = auxact->ant;
    *pl = auxact->sig?auxact->sig:auxact->ant;
    free(auxact);
    return d;
}



void vaciarListaDoble(tListaDoble *pl)
{
    tNodo *aux = *pl, *nae;
    if(!aux)
        return NULL;
    while(aux->ant)
        aux = aux->ant;

    while(aux)
    {
        nae = aux;
        aux = aux->sig;
        free(nae);
    }
}

int esVaciaListaDoble(tListaDoble *pl)
{
    return *pl == NULL;
}
