#include "header.h"

int esNumero(char *cad)
{
    int es=Verdadero;
    char *i=cad;
    if(*i=='-')
    {
        i++;
    }
    while( *i!='/0' && *i>='0' && *i<='9' )
    {
        i++;
    }
    return !*i;
}


void ingreseCad(char *cad)
{
    puts("INGRESE CADENA :\n");
    fflush(stdin);
    gets(cad);

}

int miAtoi(char *cad)
{
    int num=0;
    int positivo=Verdadero;
    char *i=cad;
    if(*i=='-')
    {
        i++;
        positivo=Falso;
    }
    while(*i!='\0')
    {
        num*=10;
        num+=(*i)-'0';
        i++;
    }
    return positivo?num:-num;

}

char miItoa(int num, char *cad)
{
    int positivo=(num>=0);
    int dig;
    int nums=abs(num);
    char *i = cad;
    if (nums==0)
    {
        *i='0';
        *i++;
        *i='\0';
        return cad;
    }
    while(nums!=0)
    {
        dig = nums % 10;
        nums /= 10;
        *i = dig + '0';
        i++;
    }
    if(!positivo)
    {
        *i='-';
        i++;
    }
    *i='\0';

    invertirCadena(cad);

    return cad;
}

void invertirCadena(char *cad)
{
    char *i=cad;
    char *j=cad;
    char aux;

    i+=strlen(cad)-1;

    while(i>=j)
    {
        aux=*j;
        *j=*i;
        *i=aux;
        j++;
        i--;
    }
}
