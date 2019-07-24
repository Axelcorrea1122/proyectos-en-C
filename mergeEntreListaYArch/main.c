#include <stdio.h>
#include <stdlib.h>
#include "lista.h"


int main(int argc, char *argv[])
{
    FILE *stockF = fopen(argv[1],"r+b");
    FILE *movF = fopen(argv[2],"rb");

    if(!stockF && ! movF)
    {
        return ERROR_ARCH;
    }

    tLista movL;
    crearLista(&movL);

    int ret = resumirMov(movF,&movL);
    fclose(movF);

    if( ret != TODO_OK )
    {
        return ret;
    }
    ret = actualizarStock(stockF,&movL,cmpProd);

    fclose(stockF);

    return ret;





    return 0;
}
