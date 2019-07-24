#ifndef PLAZOSFIJOS_H_INCLUDED
#define PLAZOSFIJOS_H_INCLUDED

typedef struct
{
    int d,
        m,
        a;
}tFecha;

typedef struct
{
	int nroPF;
	int cuenta;
	float monto;
	float interesAnual;
	tFecha fechaConstitucion;
	int dias;
}
tPlazoFijo;

typedef tPlazoFijo tInfo;


#endif // PLAZOSFIJOS_H_INCLUDED
