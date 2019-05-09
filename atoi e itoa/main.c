#include "header.h"

int main()
{
    int num;
    char cad[5];
    ingreseCad(cad);
    if(!esNumero(cad))
    {
        puts("No ingresaste digitos numericos...\n");
        return 1;
    }

    num=miAtoi(cad);
    printf("%d este es num\n",num);

    char cad2[10];

    char *cadnum=miItoa(num,cad2);

    printf("%s este es cad2",cad2);


    return 0;

}
