#include<stdio.h>
#include "tipohabilidad.h"
//precond: se ingresa un numero por entrada estandar del conjunto 0-1-2
void cargarTipoHabilidad(TipoHabilidad &h)
{
    int valor;
    printf("Ingrese 0-Natural, 1-Poco natural, 2-Sobrenatural: ");
    scanf("%d", &valor);
    if(valor==0)
    {
        h=NATURAL;
    }
    else if(valor==1)
    {
        h=POCONATURAL;
    }
    else if(valor==2)
    {
        h=SOBRENATURAL;
    }
}
//precond: h no vacio
void mostrarTipoHabilidad(TipoHabilidad h)
{
    if(h==NATURAL)
    {
        printf("Natural");
    }
    else if(h==POCONATURAL)
    {
        printf("Poco natural");
    }
    else if(h==SOBRENATURAL)
    {
        printf("Sobrenatural");
    }
}
