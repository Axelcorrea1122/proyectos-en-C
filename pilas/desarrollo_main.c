#include "main.h"

void probarIngresarYMostrarProd()
{
    tProd prod;
    int   result;
    int   cant = 0;

    puts("Probando ingresar productos y mostrar nombres productos");
    result = ingresarProducto(&prod);
    if(result)
    {
        mostrarProducto(NULL);
    }
    while(result)
    {
        mostrarProducto(&prod);
        result = ingresarProducto(&prod);
        cant ++;
    }
    printf("Se mostraron %d productos.\n\n",cant);
}

void probarPonerYSacarDePila()
{
    tProd prod;
    tPila pila;
    int result;
    int llena;

    crearPila(&pila);
    llena = pilaLlena(&pila);
    if(!llena)
    {
        result = ingresarProducto(&prod);
        puts("Procedimiento a poner en pila");
        mostarProducto(NULL);
    }
    while(result && !llena)
    {
        if(!ponerEnPila(&pila,&prod))
        {
            fprintf(stderr, "ERROR - inesperado: pila llena\n");
            puts("no se pudo cargar la informacion");
        }
        mostrarProducto(&prod);
        llena = pilaLlena(&pila);
        if(!llena)
            result = ingresarProducto(&prod);
        else
            puts("Se lleno la pila");

    }

    puts("\nMostrando el tope de la pila");
    if(!pilaVacia(&pila))
    {
        tProd otro;
        verTope(&pila,&otro);
        mostarProductos(&otro);
    }
    else
        puts("La pila estaba vacia");

    puts("\nProcedimiento a sacar de la pila y mostrar");
    if(pilaVacia(&pila))
        puts("La pila esta vacia");
    else
        mostrarProducto(NULL);
    while(sacarDeLaPila(&pila, &prod))
        mostrarProducto(&prod);
    puts("");

}
