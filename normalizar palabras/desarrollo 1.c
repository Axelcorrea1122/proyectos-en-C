#include "header.h"


void iniciarSec(T_Sec_Pal *sec, const char *cad)
{
    sec->act=cad;
}

char *normalizar(const char *orig, char *dest)
{
    T_Palabra pal, paldest;
    T_Sec_Pal sorig, sdest;

    iniciarSec(&sorig,orig);
    iniciarSec(&sdest,dest);

    leerPalabra(&sorig,&pal);

    while(!finSec(&sorig))    {
        escribirPalabra(&sdest,&pal,&paldest);
        formatearPalabra(&paldest);
        escribirCaracter(&sdest,' ');
        leerPalabra(&sorig,&pal);
    }
    moverCursor(&sdest,-1);

    escribirCaracter(&sdest,'\0');

    return dest;

}

void leerPalabra(T_Sec_Pal *sec,T_Palabra *pal)
{
  while(*sec->act && (!esLetra(*sec->act)))
  {
    sec->act++;

  }
  if(!*sec->act)
  {
      sec-> fin = Verdadero;
      return ;
  }
  pal->ini=sec->act;
  while((*sec->act) && esLetra(*sec->act))
  {
     sec->act++;
  }
  pal->fin= sec->act -1;

}


int finSec(T_Sec_Pal *sec)
{
    if(*sec->act=='\0')
    {
        return Verdadero;
    }else
    {
        return Falso;
    }
}

void escribirPalabra(T_Sec_Pal *sdest, const T_Palabra *pal, T_Palabra *paldest)
{
    int c=0;
    char *i,*j=sdest->act;
    for(i=pal->ini ; i<=pal->fin ; i++ )
    {
        *sdest->act = *i;
        sdest->act++;
        c++;
    }
    paldest->ini = j;
    paldest->fin = j + (c-1);

}

void formatearPalabra(T_Palabra *paldest)
{
    char *i=paldest->ini;
    miUpper(i);
    i++;

    for(i;i<=paldest->fin;i++)
    {
        miLower(i);
    }

}

void miUpper(char *caracter)
{
    if(*caracter>='a' && *caracter<='z' )
    {
        *caracter = *caracter - ('a'-'A');
    }
}

void miLower(char *caracter)
{
    if(*caracter>='A' && *caracter<='Z')
    {
        *caracter = *caracter + ('a'-'A');
    }
}

void escribirCaracter(T_Sec_Pal *sdest,char caracter)
{


    *(sdest->act)= caracter;

    sdest->act++;
}

void moverCursor(T_Sec_Pal *cad,int desplazamiento)
{
    if(desplazamiento>=0)
    {
        cad->act = cad->act + desplazamiento;
    }
    else
    {
        cad->act = cad->act - abs(desplazamiento);
    }
}

int esLetra(char caracter)
{
    return (caracter>='a' && caracter<='z') || (caracter>='A' && caracter<='Z')?Verdadero:Falso;
}
