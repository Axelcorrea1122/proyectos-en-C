#include "main.h"
#include <conio.h>
#include "include/arbol.h"

int main()
{
    FILE *pf = fopen("PlazosFijos.txt","rt");
    tListaDoble listaDoble;

    crearListaDoble(&listaDoble);

    tPlazoFijo plazo;
    int ce=0;
    while(fscanf(pf,"%d|%d|%f|%f|%d/%d/%d|%d",&plazo.nroPF,&plazo.cuenta,
          &plazo.monto,&plazo.interesAnual,&plazo.fechaConstitucion.d,&plazo.fechaConstitucion.m,
          &plazo.fechaConstitucion.a,&plazo.dias) != EOF)
    {
        int codret = ingresarEnListaDobleOrd(&listaDoble, &plazo, cmpxNroCuentaPF);

        if(codret)
            exit(1);
        ce++;
    }
    int i = 1;
    while(i<=ce)
    {
        tNodo *nam = buscarNodoPorPosicionListaDoble(&listaDoble,i);
        printf("\n%d",nam->info.cuenta);
        i++;
    }

    int pos=1;

    tArbol arbol;
    crearArbol(&arbol);

    cargarRaicesEnArbol(&arbol, &listaDoble, &plazo, pos, ce);
    tPlazoFijo *aux;
    while(!esVaciaListaDoble(&listaDoble))
    {

        aux = sacarPrimeroListaDoble(&listaDoble,&plazo);
        if(aux)
            ingresarEnArbol(&arbol,aux,cmpxNroCuentaPF);
    }
    tNodo_a *ndato = NULL;
    puts("\n Recorrer el arbol en inOrden");
    recorrerArbolEnOrden(&arbol,mostrarNodoArbol, ndato);
    puts("\n Recorrer el arbol en posOrden");
    recorrerArbolPosOrden(&arbol,mostrarNodoArbol, ndato);
    puts("\n Recorrer el arbol en preOrden");
    recorrerArbolPreOrden(&arbol,mostrarNodoArbol,ndato);

    printf("\n%s",tipoBalanceoArbol(&arbol));

    return 0;
}




int cmpxNroCuentaPF(const void *e1,const void *e2)
{
    tPlazoFijo *E1 = (tPlazoFijo*)e1;
    tPlazoFijo *E2 = (tPlazoFijo*)e2;

    if(E1->cuenta>E2->cuenta)
        return 1;
    if(E1->cuenta==E2->cuenta)
        return 0;
    return -1;

}
