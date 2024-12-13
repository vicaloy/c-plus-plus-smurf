#include "habilidad.h"
#include "stdio.h"
//precond: habilidad con campos catgados
void mostrarHabilidad(Habilidad h)
{
    printf("Habilidad: \n");
    printf("Cedula: %d.", h.cedulaMago);
    printf(" Nombre: ");
    print(h.nombreHabilidad);
    printf(". Fecha manifestacion: ");
    mostrarFecha(h.fechaManif);
    mostrarTipoHabilidad(h.tipoHabilidad);
    printf("\n");

}
//precond: ingreso de datos en la entrada estandar
void cargarHabilidad(Habilidad &h)
{
    printf("Ingrese a continuacion los valores para una nueva Habilidad.\n");

    printf("Cedula: ");
    scanf("%d",&h.cedulaMago);
    while(h.cedulaMago < 0)
    {
        printf("La cedula debe ser un valor entero mayor que 0.\nCedula: ");
        scanf("%d",&h.cedulaMago);
    }

    printf("Nombre habilidad: ");
    scan(h.nombreHabilidad);
    while (strlar(h.nombreHabilidad) < 1)
    {
        printf("El nombre debe contener al menos una letra.\nNombre: ");
        scan(h.nombreHabilidad);
    }

    printf("Ingrese la Fecha de manifestacion: ");
    cargarFecha(h.fechaManif);

    printf("Ingrese tipo habilidad: ");
    cargarTipoHabilidad(h.tipoHabilidad);
}
//precond: habilidad con cedula cargada
int darCedulaMago(Habilidad h)
{
    return h.cedulaMago;
}

void setearCedulaHab(Habilidad &h, int ced)
{
    h.cedulaMago= ced;
}

//precond: habilidad con nombre cargado y param nombre no nulo
void darNombreHab(Habilidad h, StringDinamico &nombre)
{
    strcop(nombre ,h.nombreHabilidad);
}
void setearNombreHab(Habilidad &h, StringDinamico &nombre)
{
    strcrear(h.nombreHabilidad);
    strcop(h.nombreHabilidad,nombre);
}


//precond: habilidad con fecha cargada
Fecha darFechaManif(Habilidad h)
{
    return h.fechaManif;
}
//precond: fMan no nula
void setearFechaManif(Habilidad &h, Fecha fman)
{
    h.fechaManif.dia= darDia(fman);
    h.fechaManif.mes = darMes(fman);
    h.fechaManif.ano= darAno(fman);
}

//precond: habilidad con tipo cargado
TipoHabilidad darTipoHabilidad(Habilidad h)
{
    return h.tipoHabilidad;
}

void setearTipoHabilidad(Habilidad &h, TipoHabilidad tHab)
{
    h.tipoHabilidad = tHab;
}

