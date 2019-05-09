#include "header.h"


float ingreseDatoVal()
{
    float dato;
    printf("Ingrese valor de X para calcular e^x: \n");
    scanf("%f",&dato);

    return dato;
}


float ingreseDatoVal2()
{
    float dato;
    do
    {
        printf("Ingrese el valor numerico de la tolerancia:\n" );
        scanf("%f",&dato);
    }
    while(esDatoVal2(dato));
    return dato;
}


int esDatoVal2(float dato)
{

    if(dato>0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

float calculoPotencia(float num,float tol)
{
    float ResultExp=1, TermExp=1;
    int cont=1, acum=1;



    if(num==0)
    {
        ResultExp=1;

        return ResultExp;
    }

    while(TermExp >= tol)
    {
        acum*=cont;
        TermExp=(pow(num,cont))/acum ;
        ResultExp+=TermExp;
        cont++;
    }
    return ResultExp;

}
