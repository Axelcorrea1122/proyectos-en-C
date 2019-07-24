#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED
#include <stdio.h>

typedef struct
{
    int di;
    int me;
    int an;
} tFecha;
/**
*funcion booleana que permite el ingreso de tres enteros para el dia, mes
*    y año sin garantia de que correspondan a un fecha.
*contempla el caso en que se quiera mostrar un mensaje distinto del
*    mensaje por defecto el que se mostrara si recibe NULL.
*contempla el caso en que no se quiera mostrar ningun mensaje cuando reciba
*    una cadena vacia ( o con blancos o tabulaciones), en este caso, de ser
*    necesario, se mostrara el mensaje antes de invocarla.
*contempla el caso en que no se quiera ingresar nada, por ejemplo con
*    cero en alguno de los enteros, con lo que devolvera 0 ( cero )
**/
int ingresarFechaDMA(tFecha *fec, const char *mensajeOpcional);

/**
*	muestra una fecha en el formato dia/mes/año
**/
void mostrarFechaDMA(const tFecha *fec);

/**
*    Vigencia del Calendario Gregoriano
*    Al jueves -juliano- 4 de octubre de 1582 le sucede el
*        viernes -gregoriano- 15 de octubre de 1582.
*    Diez dias desaparecen debido a que ya se habian contado de mas en el
*        calendario juliano.
*    Si hubiera habido calendario gregoriano;
*        01/01/1582 -> VIERNES
*        01/01/1580 -> JUEVES
*       01/01/1580 -> MARTES

*    tomaremos como minimo valido el año 1 (uno), teniendo en cuenta que no
*        existio el año 0 (cero), 'extrapolando2 la vigencia del calendario
*       gregoriano (su vigencia es -en España, Italia y Portugal, a saber, a
*        partir del 15 de octubre de 1582)
*    por no ser adoptado en forma universal, su vigencia depende del pais
*    NOTA: se ponen topes minimo y maximo, y nuestros algoritmos quedaran
*        abiertos a modificaciones (que  hasta ahora estan mas alla)
*    OTRA: a partir de su vigencia, por una pequeña diferencia, cada 3623 años
*        habra un dia mas y para corregirlo, se dejara de contar un biciesto
*        cada 300 años
*    esto quedara como tema abierto a quien tenga intereses muy trascendentes, y
*        debera tener en cuenta determinaciones astronomicas mas precisas
*    si extrapolamos dentro de un rango razonable nos queda...
**/

#define    AN_MIN       1
#define    AN_MAX       5000

/**
*    para determiinar si un año es biciesto se lo puede hacer con una funcion, o
*        mejor, como en este caso con un macroremmplazo
**/

#define esBiciesto( x ) ( ( ( x ) % 4 == 0 && ( x ) % 100 != 0 ) || \
                            ( x ) % 400 == 0 )

/**
*    determina si una fecha es valida
**/
int esFechaValida(const tFecha *fec);

/**
*    permite el ingreso de una fecha valida (valiendose de las dos anteriores
*    contemplando el caso de que no se quiera ingresarla, ademas de la
*    posibilidad de mostrar un mensaje distinto del mensaje por defecto
**/
int ingresarFechaValidaDMA(tFecha *fec, const char *mensajeOpcional);

/**
*    compara dos fechas devolviendo 0 si son iguales, algun valor negativo
*        si la primera es menor que la segunda, algun valor positivo si la
*        primera es mayor que la segunda
**/
int compararFecha(const tFecha * fec1, const tFecha *fec2);

/**
*    calcula y devuelve el dia del año de esa fecha
*    precondicion: que sea una fecha valida
**/
int aJuliano(const tFecha * fec);

/**
*    la convencion, mas comunmente utilizada, adoptada a continuacion se puede
*        alterar a gusto del programador, a costa de apartarse del estandar
**/
#define DOMINGO         0
#define LUNES           1
#define MARTES          2
#define MIERCOLES       3
#define JUEVES          4
#define VIERNES         5
#define SABADO          6

/**
*    determina el numero de dia de la semana de una fecha
*    se tiene en cuenta que:
*        -en un lapso de 400años la cantidad de dias es multiplo de 7
*        -para cada uno de los años consecutivos de esos intervalos el primero de
*         enero de cad año comienza en el mismo dia
*        -el primero de enero de los años multiplo de 400 es SABADO (6)
*        tomando como año base el año multiplo de 400 inmediato anterior al año
*            pero solo es necesario calcular la distancia al año base en años
*        por cada años se suma 1 al nro de dia del año base, salvo que
*            cada cuatro años es biciesto y se suma uno mas, pero cada 100 años
*            no es biciesto y se resta 1.
*        si el año no fuera el año calculado, se suma 1 porque es biciesto
**/

int nroDeDiaDeLaSemana(const tFecha *fec);

/**
*    determina la cantidad de dias desde fecDesde hasta fecHasta, que sera
*        negativa si fecDesde es mayor que fecHasta
**/
long diasEntreFechas(const tFecha *fecDesde, const tFecha *fecHasta);

/**
*    calcula la cantidad de dias, meses alos entre dos fechas, y lo devuelve
*        como un fecha
**/
tFecha calcularEdad(const tFecha *fecDesde, const tFecha *fecHasta);


#endif // FECHAS_H_INCLUDED
