#include "header.h"


void generarArchivo(TProductos prodVec[],int ce)
{
    int esSalida = Falso;
    int i=0;
    int cond1;
    float cond2;
    char cadnula[2]={'0'};
    while(i < ce && esSalida == Falso)
    {
        do
        {
            puts("\nIngrese el nombre del producto:       ------ 0 para terminar\n ");
            fflush(stdin);
            gets(prodVec[i].cod);

            if(!miStrCmp(prodVec[i].cod,cadnula))
            {
                esSalida = Verdadero;
                printf("Se presiono cero se termino la carga...");
            }

            if(esSalida)
            {
                cond1 = 1;
                cond2 = 1;

            }
            else
            {
                puts("\nIngrese cantidad del producto: ");
                scanf("%d",&(prodVec[i].stock));

                puts("\nIngrese el precio unitario del producto: ");
                scanf("%f",&(prodVec[i].precio));

                cond1 = prodVec[i].stock;
                cond2 = prodVec[i].precio;
            }
        }while(cond1<0 || cond2<0);
        i++;

    }
    ce = i-1;
    cargarEnArchivo(prodVec,ce);
}


void generarArchivo2(TMov movVec[],int ce)
{
    int esSalida = Falso;
    int i=0;
    char cadnula[2]={'0'};
    while(i < ce && esSalida == Falso)
    {
            puts("\nIngrese el nombre del producto:       ------ 0 para terminar\n ");
            fflush(stdin);
            gets(movVec[i].cod);

            if(miStrCmp(movVec[i].cod,cadnula) == 0)
            {
                esSalida = Verdadero;
                printf("Se presiono cero se termino la carga...");
            }
            else
            {
                puts("\nIngrese cantidad del producto: ");
                scanf("%d",&(movVec[i].cantprod));

            }
        i++;
    }
    ce = i-1;
    cargarEnArchivo2(movVec,ce);

}


void cargarEnArchivo(TProductos prodVec[],int ce)
{
    int i = 0;
    FILE *pf = fopen("Productos.dat","wb");
    while(i<ce)
    {
        fwrite(&prodVec[i],sizeof(TProductos),1,pf);
        i++;
    }
    fclose(pf);
}


void cargarEnArchivo2(TMov movVec[],int ce)
{
    int i = 0;
    FILE *pf = fopen("Movimientos.dat","wb");
    while(i<ce)
    {
        fwrite(&movVec[i],sizeof(TProductos),1,pf);
        i++;
    }
    fclose(pf);

}


int compararProd(TProductos *prod,TMov *mov)
{
    return miStrCmp(prod->cod,mov->cod);
}

int miStrCmp(char *cad1,char *cad2)
{
    char *i=cad1, *j=cad2;
    while((*i == *j) && (*i != '\0') && (*j != '\0'))
    {
        i++;
        j++;
    }
    if(*i > *j)
    {
        return 1;
    }
    if(*i < *j)
    {
        return -1;
    }
    return 0;
}
void miStrCpy(char *cad1,char *cad2)
{
    char *i=cad1 , *j=cad2;
    while(*j!='\0')
    {
        *i=*j;
        i++;
        j++;
    }
    *i='\0';
}

