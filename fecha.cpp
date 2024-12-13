#include<stdio.h>
#include "fecha.h"
//precond: fecha no vacia
void mostrarFecha(Fecha fecha)
{
    printf("Dia %d ", darDia( fecha));
    printf("Mes %d ", darMes(fecha));
    printf("Ano %d ", darAno( fecha));
}
//precond: ingreso de valores en la entrada estandar
void cargarFecha(Fecha &fecha)
{
    printf("Ingrese dia: ");
    scanf("%d", &fecha.dia);
    printf("Ingrese mes: ");
    scanf("%d", &fecha.mes);
    printf("Ingrese ano: ");
    scanf("%d", &fecha.ano);
    while(validarFecha(fecha.dia, fecha.mes, fecha.ano)==FALSE)
    {
        printf("Fecha invalida. \n");
        printf("Ingrese dia: ");
        scanf("%d", &fecha.dia);
        printf("Ingrese mes: ");
        scanf("%d", &fecha.mes);
        printf("Ingrese ano: ");
        scanf("%d", &fecha.ano);
    }

}
//precond: fecha no vacia con dia cargado
int darDia(Fecha fecha)
{
    return fecha.dia;
}
//precond: fecha no vacia con mes cargado
int darMes(Fecha fecha)
{
    return fecha.mes;
}
//precond: fecha no vacia con anio cargado
int darAno(Fecha fecha)
{
    return fecha.ano;
}
//precond: dia, mes y anio no vacios
boolean validarFecha(int dia, int mes, int anio)
{
    boolean validado=FALSE;
    switch (mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (dia >= 1 && dia <= 31)
            validado=TRUE;
        else
            validado=FALSE;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (dia >= 1 && dia <= 30)
            validado=TRUE;
        else
            validado=FALSE;
        break;
    case 2:
        if (anio % 4 == 0)
        {
            if (dia >= 1 && dia <= 29)
                validado=TRUE;
            else
                validado=FALSE;
        }
        else
        {
            if (dia >= 1 && dia <= 28)
                validado=TRUE;
            else
                validado=FALSE;
        }
        break;
    default:
        validado=FALSE;
    }

    return validado;
}
//precond: las 2 fechas cargadas
boolean primeraFechaMayor(Fecha primeraFecha, Fecha segundaFecha)
{
    boolean primeraMayor=FALSE;
    if(darAno( primeraFecha) > darAno( segundaFecha))
    {
        primeraMayor=TRUE;
    }
    else if(darAno( primeraFecha) == darAno( segundaFecha) && darMes( primeraFecha) > darMes( segundaFecha))
    {
        primeraMayor=TRUE;
    }
    else if( darAno( primeraFecha)== darAno( segundaFecha) && darMes( primeraFecha) == darMes( segundaFecha)
             && ( darDia( primeraFecha) > darDia( segundaFecha) ||  darDia( primeraFecha) == darDia( segundaFecha)))
    {
        primeraMayor=TRUE;
    }

    return primeraMayor;
}
//precond: las 2 fechas cargadas
boolean primeraFechaMenor(Fecha primeraFecha, Fecha segundaFecha)
{
    boolean primeraMayor=FALSE;
    if( darAno( primeraFecha) < darAno( segundaFecha))
    {
        primeraMayor=TRUE;
    }
    else if( darAno( primeraFecha)== darAno( segundaFecha) && darMes(primeraFecha)< darMes(segundaFecha))
    {
        primeraMayor=TRUE;
    }
    else if( darAno(primeraFecha)== darAno(segundaFecha) && darMes(primeraFecha) == darMes(segundaFecha) &&
             ( darDia(primeraFecha)< darDia(segundaFecha) ||  darDia(primeraFecha)== darDia(segundaFecha)))
    {
        primeraMayor=TRUE;
    }

    return primeraMayor;
}

//precond: las 2 fechas cargadas
boolean fechasIguales(Fecha primeraFecha, Fecha segundaFecha)
{
    boolean iguales=FALSE;
    if( darAno(primeraFecha)== darAno(segundaFecha) && darMes(primeraFecha)== darMes(segundaFecha) && darDia(primeraFecha)== darDia(segundaFecha))
    {
        iguales=TRUE;
    }

    return iguales;
}

void setearDia(Fecha &fecha, int dia)
{
    fecha.dia = dia;
}

void setearMes(Fecha &fecha, int mes)
{
    fecha.mes = mes;
}

void setearAno(Fecha &fecha, int ano)
{
    fecha.ano = ano;
}


