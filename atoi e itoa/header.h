#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define Verdadero 1
#define Falso 0
char toAscii(int dig);
void invertirCadena(char *cad);
char *miItoa(int num, char *cad, int base);
int miAtoi(char *cad);
void ingreseCad(char *cad);

#endif // HEADER_H_INCLUDED
