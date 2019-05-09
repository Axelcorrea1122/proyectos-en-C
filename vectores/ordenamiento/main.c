#include "header.h"

int main()
{
    int vec[]={1,5,6,9,3,55,6,8,0},i=0;

    ordSeleccionAsc(vec,9);

    for(i=0;i<9;i++)
      printf("%d",vec[i]);


    return 0;
}
