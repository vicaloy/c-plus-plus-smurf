#include<stdio.h>
#include "categoriamagica.h"
//precond: se ingresan valores (0-1-2)por entrada estandar
void cargarCategoriaMagica(CategoriaMagica &c)
{
    int valor;
    printf("Ingrese 0-Brujo, 1-Hada, 2-Hechicero: ");
    scanf("%d", &valor);
    if(valor==0)
    {
        c=BRUJO;
    }
    else if(valor==1)
    {
        c=HADA;
    }
    else if(valor==2)
    {
        c=HECHICERO;
    }
}
//precond: categoria no vacia
void mostrarCategoriaMagica(CategoriaMagica c)
{
    if(c==HECHICERO)
    {
        printf("Hechicero");
    }
    else if(c==BRUJO)
    {
        printf("Brujo");
    }
    else if(c==HADA)
    {
        printf("Hada");
    }
}
