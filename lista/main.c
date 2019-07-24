#include "lista.h"
int main()
{
    tLista lista;

    tProd vecProd[3]={{"celular",13000},{"laptop",25000},{"smartTv",50000}};
    tProd *ini = vecProd;
    tProd *ult = vecProd + 3 - 1;

    crearLista(&lista);

    while(!listaLlena(&lista) && ini <= ult )
    {
        ponerAlFinalLista(&lista,&(*ini));
        ini++;
    }
    tProd elem = {"dell g5",70000};
    int cod=insertarEnListaOrd(&lista,&elem,cmpxClave,updProd);

    if(cod==0)
    {
        tProd otro;
        mostrarElemLista(&lista,&otro);
    }
    return 0;
}

