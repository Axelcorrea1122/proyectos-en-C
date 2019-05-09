#include "header.h"


int main()
{
    int num=ingreseDatoVal();
    int num2=ingreseDatoVal2(num);
    int comb;

    comb=calculoNumCombinatorio(num,num2);

    printf("El numero combinatorio de %d y %d es: %d",num,num2,comb);

    return 0;
}
