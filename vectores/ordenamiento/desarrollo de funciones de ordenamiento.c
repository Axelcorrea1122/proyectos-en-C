#include "header.h"

void ordSeleccionAsc(int *v, int ce)
{
  int *i, *ult= v + (ce -1), *m;

  for(i=v;i<ult;i++)
  {
    m=busquedaMenor(i,ult);
    if(m!=i)
    {
      intercambiarInts(m,i);
    }

  }
}



int * busquedaMenor(const int *d, const int *h)
{
  int *m=d, *j;

  for(j=d+1;j<=h;j++)
  {
    if(*j<*m)
    {
      m=j;
    }
  } return m;
}

void intercambiarInts(int *a,int *b)
{
  int aux;

  aux=*a;
  *a=*b;
  *b=aux;
}
