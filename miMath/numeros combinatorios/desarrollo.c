#include "header.h"

int ingreseDatoVal()
{
    float dato;
    do
    {
        printf("Ingrese m mayor a cero para calcular su combinatorio:" );
        scanf("%f",&dato);
    }
    while(esDatoVal(dato));
    return dato;
}

int ingreseDatoVal2(int num)
{
    float dato;
    do
    {
        printf("Ingrese n mayor a m para calcular su combinatorio:" );
        scanf("%f",&dato);
    }
    while(esDatoVal2(dato,num));
    return dato;
}


int esDatoVal(float dato)
{
    int dato2=dato;
    if(dato<0 || dato>dato2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int esDatoVal2(float dato,int num)
{
    int dato2=dato;
    if(dato<0 || dato>dato2 || dato>num)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int calculoNumCombinatorio(int num,int num2)
{

    int fac,fac2,fac3,result;
    int rest=num - num2;


    result=fac=CalculoFactorial(num)/(fac2=CalculoFactorial(num2)*(fac3=CalculoFactorial(rest)));

    return result;

}





int CalculoFactorial(int num)
{
    if (num!=0 && num!=1)
    {
        int fac=1;
        while (num>=1)
        {

            fac*=num;
            num--;
        }
        return fac;

    }
    else
    {
        return 1;
    }

}
