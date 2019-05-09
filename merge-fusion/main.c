#include "header.h"
int main()
{
    TProductos prodVec[10];
    TMov movVec[15];

    generarArchivo(prodVec,10);
    puts("A continuacion ingrese las ventas de los productos\n");
    generarArchivo2(movVec,15);


    FILE *aprod= fopen("Productos.dat","rb");
    FILE *amov= fopen("Movimientos.dat","rb");
    FILE *aprodA= fopen("ProductosAct.dat","wb");

    if(!aprod || !amov || !aprodA)
    {
        puts("Error al abrir el archivo");
        return 1;
    }

    TProductos prod, prodA;
    TMov mov;

    fread(&prod,sizeof(TProductos),1,aprod);
    fread(&mov,sizeof(TMov),1,amov);

    while(!feof(aprod) && !feof(amov))
    {
        int comp = compararProd(&prod,&mov);
        if(comp == 0)
        {
            prod.stock += mov.cantprod;
            if(prod.stock < 0)
            {
                printf("El producto %s se encuentra con stock (-)\n",prod.cod);
            }
            else
            {
                fwrite(&prod,sizeof(TProductos),1,aprodA);
            }
            fread(&prod,sizeof(TProductos),1,aprod);
            fread(&mov,sizeof(TMov),1,amov);
        }

        if( comp < 0 )
        {
            prod.precio *= ( 1 - 0.10 );
            fwrite(&prod,sizeof(TProductos),1,aprodA);
            fread(&prod,sizeof(TProductos),1,aprod);
        }

        if( comp >0 )
        {
            miStrCpy(prodA.cod,mov.cod);
            prodA.stock = mov.cantprod;
            prodA.precio = 0;

            if( prodA.stock < 0 )
            {
                printf("El producto %s queda con stock (-)\n",prodA.cod);
            }
            else
            {
                fwrite(&prodA,sizeof(TProductos),1,aprodA);
            }
            fread(&mov,sizeof(TMov),1,amov);
        }

    }

    while(!feof(aprod))
    {
        prod.precio *= (1 - 0.10);
        fwrite(&prod,sizeof(TProductos),1,aprodA);
        fread(&prod,sizeof(TProductos),1,aprod);
    }

    while(!feof(amov))
    {
        miStrCpy(prodA.cod,mov.cod);
        prodA.stock = mov.cantprod;
        prodA.precio = 0;

        if( prodA.stock < 0 )
        {
            printf("El producto %s queda con stock (-)\n",prodA.cod);
        }
        else
        {
            fwrite(&prodA,sizeof(TProductos),1,aprodA);
        }
        fread(&mov,sizeof(TMov),1,amov);
    }

    fclose(aprod);
    fclose(amov);
    fclose(aprodA);



fflush(stdin);
    return 0;
}
