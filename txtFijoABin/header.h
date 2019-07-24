#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "fechas.h"
#include <strings.h>
#include <ctype.h>
#define TODO_OK 0
#define LINEA_LARGA 1
#define SEP_INVALIDOS 2
#define DNI_INVALIDO 3
#define FECHA_INVALIDA 4
#define SUELDO_INVALIDO 5
#define Verdadero 1
#define Falso 0
typedef struct
{
    char ApyN[150];
    int dni;
    char sexo;
    tFecha fnac;
    float sueldo;
}tEmpleados;

void trim( char *inic);

void textFijoAFecha(char *ini, tFecha *f);

int txtFijoABin(char *linea,tEmpleados *emp);


#endif // HEADER_H_INCLUDED
