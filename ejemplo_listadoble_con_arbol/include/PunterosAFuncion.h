#ifndef PUNTEROSAFUNCION_H
#define PUNTEROSAFUNCION_H
#include "listaDoble.h"


typedef int (*tCmp)(const void*, const void*);
typedef void (*tAccion)(void* info, void* datos_accion);
typedef int (*tCondicion)(void* info);
typedef void (*tActualizar)(void* actualizado, const void* actualizador);


#endif // PUNTEROSAFUNCION_H
