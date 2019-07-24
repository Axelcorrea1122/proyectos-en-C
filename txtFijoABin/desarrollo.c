#include "header.h"
int txtFijoABin(char *linea,tEmpleados *emp)
{
    FILE *archtxt = fopen("EmpleadosFijo.txt","rt");
    FILE *archbin = fopen("EmpleadosFijo.dat","wb");
    if(!archbin || !archtxt)
    {
        puts("\nNo se abrio");
        exit(1);
    }
    fgets(linea,500,archtxt);
    char *inic = strchr(linea,'\n');

    if(!inic)
    {
        return LINEA_LARGA;
    }
    *inic = '\0';
    inic -= 5;
    sscanf(inic,"%f",&emp->sueldo);
    printf("\n%f",emp->sueldo);
    *inic = '\0';
    inic -= 8;
    textFijoAFecha(inic,&emp->fnac);
    printf("\n%d/%d/%d",emp->fnac.di,emp->fnac.me,emp->fnac.an);
    *inic = '\0';
    inic--;
    emp->sexo = *inic;
    printf("\n%c",emp->sexo);
    *inic = '\0';
    inic -= 149;
    trim(inic);
    printf("\n%s",inic);
    strcpy(emp->ApyN,inic);
    *inic='\0';
    sscanf(linea,"%d",&emp->dni);
    printf("\n%d",emp->dni);

    printf("\n%d - %s - %c - %d/%d/%d - %f",emp->dni,emp->ApyN,emp->sexo,emp->fnac.di,emp->fnac.me,emp->fnac.an,emp->sueldo);

    return TODO_OK;

}

void textFijoAFecha(char *inic, tFecha *f)
{
    char *aux = inic,*i=inic;
    while( !isdigit(*aux) )
    {
        aux++;
    }


    while(isdigit(*aux))
    {
        aux++;
    }
    *aux='\0';
    f->di = atoi(i);
    aux++;
    i = aux;

    while(isdigit(*aux))
    {
        aux++;
    }
    *aux='\0';
    f->me = atoi(i);

    i = aux + 1;
    f->an = atoi(i);

}

void trim( char *inic)
{
    char *i=inic;

    i+=148;
    while(!isalpha(*i))
    {
        i--;
    }
    i++;
    *i='\0';
}
