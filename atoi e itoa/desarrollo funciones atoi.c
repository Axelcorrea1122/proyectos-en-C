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

char *miItoa(int num, char *cad, int base)
{
    int positivo=(num>=0);
    if(!positivo)
    {
        num=abs(num);
    }
    char *i = cad;
    if (num==0)
    {
        *i='0';
        *(i+1)='\0';
        return cad;
    }
    while(num>0)
    {
        *i = toAscii(num%base);
        i++;
        num/=base;

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

char* invertirCadena(char *cad)
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

char toAscii(int dig)
{
    return dig<=9?dig+'0':(dig-10)+'A';
}
