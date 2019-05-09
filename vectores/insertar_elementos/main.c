#include "header.h"

int main()
{
    int vec[7] = {1,2,3,5,6,7};

    insertarElemOrdenadoAscVec(vec,6,4,1);

    int *i;
    for(i = vec ; i < (vec + 7) ; i++)
    {
        printf("%d\n",*i);
    }

    eliminarElemVec(vec,7,3);

    for( i = vec ; i < (vec + 6) ; i++ )
    {
        printf("%d\n",*i);
    }


}
