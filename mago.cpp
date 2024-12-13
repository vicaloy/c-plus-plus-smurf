#include "mago.h"
#include "stdio.h"
//precond: mago no vacio
void mostrarMago(Mago mago)
{
    printf("Cedula: %d. ", mago.cedula);
    printf("Nombre: ");
    print(mago.nombreMago);
    printf(". Origen: ");
    printf(mago.origen);
    printf(". Mago: ");
    mostrarFecha(mago.fechaNac);
    mostrarCategoriaMagica(mago.categoria);
    printf("\n");

}
//precond: se ingresen datos del tipo acorde en la entrada estandar
void cargarMago(Mago &mago)
{
    printf("Ingrese a continuacion los valores para un nuevo Mago.\n");

    printf("Cedula: ");
    scanf("%d",&mago.cedula);
    while(mago.cedula < 0)
    {
        printf("La cedula debe ser un valor entero mayor que 0.\nCedula: ");
        scanf("%d",&mago.cedula);
    }

    printf("Nombre: ");
    scan(mago.nombreMago);
    while (strlar(mago.nombreMago) < 1)
    {
        printf("El nombre debe contener al menos una letra.\nNombre: ");
        scan(mago.nombreMago);
    }



    printf("Origen: ");
    scan(mago.origen);
    while (strlar(mago.origen) < 1)
    {
        printf("La dimension de Origen debe contener al menos una letra.\nNombre: ");
        scan(mago.origen);
    }

    printf("Ingrese la Fecha de nacimiento: ");
    cargarFecha(mago.fechaNac);

    printf("Ingrese categoria: ");
    cargarCategoriaMagica(mago.categoria);
}
//precond: mago con cedula
int darCedula(Mago mago)
{
    return mago.cedula;
}

void setearCedula(Mago &mago, int ced )
{
    mago.cedula = ced;
}

void setearCategoria(Mago &mago, CategoriaMagica cat )
{
    mago.categoria = cat;
}


//precond: mago con nombre
void darNombreMago(Mago mago, StringDinamico &nombre)
{
    strcop(nombre,mago.nombreMago);
}
//precond: nombre no vacio
void setearNombreMago(Mago &mago, StringDinamico nombre)
{
    strcrear(mago.nombreMago);
    strcop(mago.nombreMago,nombre);
}

//precond: mago con nombre
void darOrigenMago(Mago mago, StringDinamico &origen)
{
    strcop( origen, mago.origen);
}
//precond: nombre no vacio
void setearOrigenMago(Mago &mago, StringDinamico origen)
{
    strcrear(mago.origen);
    strcop(mago.origen,origen);
}


//precond: mago con fechaNac
Fecha darFechaNac(Mago mago)
{
    return mago.fechaNac;
}

void setearFechaNac(Mago &mago, Fecha fnac)
{
    mago.fechaNac.dia = darDia(fnac);
    mago.fechaNac.mes = darMes(fnac);
    mago.fechaNac.ano = darAno(fnac);
}

//precond: mago con categMagica
CategoriaMagica darCategoriaMagica(Mago mago)
{
    return mago.categoria;
}

