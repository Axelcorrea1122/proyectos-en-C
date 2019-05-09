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


void insertarElemVec(int *vec, int ce, int Elem, int pos)
{
    int *i = vec + (ce - 1), *ind = vec + pos;

    while(i >= ind)
    {
        *(i+1) = *i;
        i--;
    }
    i++;
    *i = Elem;



}


void insertarElemOrdenadoAscVec(int *vec, int ce, int Elem, int pos)
{
    int *i = vec + (ce - 1), *ind = vec + pos;

    while(i >= ind)
    {
        *(i+1) = *i;
        i--;
    }
    i++;
    *i = Elem;

    ce = ce + 1 ;

    ordSeleccionAsc(vec,ce);


}


void eliminarElemVec(int *vec, int ce, int pos )
{
    int *i = vec + pos, *ind = vec + (ce - 1);

    while( i < ind )
    {
        *i = *(i+1);
        i++;
    }
}
