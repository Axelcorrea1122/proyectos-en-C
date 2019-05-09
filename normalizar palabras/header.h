#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define Verdadero 1
#define Falso 0
#endif // HEADER_H_INCLUDED
typedef struct
{
    char *ini;
    char *fin;

}T_Palabra;

typedef struct
{
    char *act;
    int fin;

}T_Sec_Pal;

int esLetra(char caracter);
void formatearPalabra(T_Palabra *paldest);
void miUpper(char *caracter);
void miLower(char *caracter);
void escribirPalabra(T_Sec_Pal *sdest, const T_Palabra *pal, T_Palabra *paldest);
int finSec(T_Sec_Pal *sec);
void leerPalabra(T_Sec_Pal *sec,T_Palabra *Pal);
char *normalizar(const char *orig, char *dest);
void iniciarSec(T_Sec_Pal *sec, const char *cad);
void moverCursor(T_Sec_Pal *cad,int desplazamiento);
void escribirCaracter(T_Sec_Pal *sdest,char caracter);
