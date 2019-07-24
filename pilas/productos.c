#include "productos.h"
int ingresarProducto(tProd *d)
{
    static const tProd productos[] =
    {
        {"clavoro3/4","Clavo de oro"},
        {"martillo3K","Martillo bolita con saca clavos de 3 kilos"},
        {"alamyeso","Alambre de yeso de un milimetro de espesor"},
        {"rem-vid15","Remache de vidrio de 1,5 milimetros"},
        {"plom-telgo","Plomada de poliestireno expandido"},
        {"limagona17","Lima de goma de 17 pulgadas"}
    };

    static int posi = 0;

    if(posi == sizeof(productos) / sizeof(tProd))
    {
        posi = 0;
        return 0;
    }
    *d = productos[posi];
    posi++;

    return 1;
}

void mostrarProducto(const tProd *d)
{
    if(d)
        fprintf(stdout,"%-*s %-*s ...\n",sizeof(d->codprod) -1,d->codprod,
                sizeof(d->descrip) - 1,d->descrip);
    else
        fprintf(stdout,"%-*.*s %-*.*s ...\n",sizeof(d->codprod) -1,sizeof(d->codprod) - 1,"Cod.Producto",
                sizeof(d->descrip) - 1, sizeof(d->descrip) - 1,"Descripcion del producto");
}
