#include "header.h"

int main()
{
    float num=ingreseDatoVal();


    float tol=ingreseDatoVal2();
    float result;

    result=calculoPotencia(num,tol);

    printf("El resultado de e^%.0f es: %f",num,result);


    return 0;
}
