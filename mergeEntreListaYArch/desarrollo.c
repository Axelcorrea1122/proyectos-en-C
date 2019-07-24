#include "lista.h"
int resumirMov( FILE *movF, tLista *movL)
{
    int codret;
    tMovi mov;
    fread(&mov,sizeof(tMovi),1,movF);
    while(!feof(movF))
    {
        codret = insertarEnListaOrd(movL,&mov,cmpMov,updProducto);
        if(codret != TODO_OK)
        {
            return codret;
        }

        fread(&mov,sizeof(tMovi),1,movF);
    }
    return TODO_OK;

}

int actualizarStock(FILE *stockF,tLista *movL,tCmp cmpProd)
{

    int i = 0;
    tProducto prod,prodaux;
    tMovi *pmov;
    tMovi mov;
    fread(&prod,sizeof(tProducto),1,stockF);
    pmov = buscarxPosicionLista(movL,&mov,i);

    i++;

    while(pmov != NULL && !feof(stockF))
    {
        int comp = cmpProd(&prod,pmov);

        if(comp == 0 )
        {
            prod.stock += pmov->movi;
            if(prod.stock < 0)
            {
                printf("\nEl producto %s se encuentra con stock negativo: ",prod.nombre);
            }
            else
            {
                fseek(stockF,-1,SEEK_CUR);
                fwrite(&prod,sizeof(tProducto),1,stockF);
            }
        }
        fread(&prod,sizeof(tProducto),1,stockF);
        pmov = buscarxPosicionLista(movL,&mov,i);
        i++;
        if(comp < 0)
        {
            prod.precio *= (1-0.10);
            fseek(stockF,-1,SEEK_CUR);
            fwrite(&prod,sizeof(tProducto),1,stockF);
            fread(&prod,sizeof(tProducto),1,stockF);
        }

        if(comp > 0)
        {
            strcpy(prodaux.nombre,pmov->nombre);
            prodaux.stock = pmov->movi;
            prodaux.precio = 0;

            if(prodaux.stock < 0)
            {
                printf("\nEl producto %s queda con stock negativo",prodaux.nombre);
            }
            else
            {
                fseek(stockF,-1,SEEK_CUR);
                fwrite(&prodaux,sizeof(tProducto),1,stockF);
            }
            pmov = buscarxPosicionLista(movL,&mov,i);
            i++;
        }
    }

    while(!feof(stockF))
    {
        prod.precio *= (1-0.10);
        fseek(stockF,-1,SEEK_CUR);
        fwrite(&prod,sizeof(tProducto),1,stockF);
        fread(&prod,sizeof(tProducto),1,stockF);
    }

    while(pmov != NULL)
    {
        strcpy(prodaux.nombre,pmov->nombre);
        prodaux.stock = pmov->movi;
        prodaux.precio = 0;

        if(prodaux.stock < 0)
        {
            printf("\nEl producto %s queda con stock negativo",prodaux.nombre);
        }
        else
        {
            fseek(stockF,-1,SEEK_CUR);
            fwrite(&prodaux,sizeof(tProducto),1,stockF);
        }
        pmov = buscarxPosicionLista(movL,&mov,i);
        i++;
    }


    return TODO_OK;
}

int cmpMov(const void *elem1,const void *elem2)
{
    tMovi *e1=(tInfo*)elem1;
    tMovi *e2=(tInfo*)elem2;

    return strcmp(e1->nombre,e2->nombre);
}
