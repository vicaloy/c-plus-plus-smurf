#include<stdio.h>
#include "menu.h"

void mostrarMenuPrincipal(int &opcion)
{
    printf("\n-------------MENU PRINCIPAL---------------\n");
    printf("1- Ingrese a registro de datos \n");
    printf("2- Ingrese a consultas \n");
    printf("3- Ingrese a listados \n");
    printf("4- Salir del programa \n\n\n");
    scanf("%d", &opcion);
}

void mostrarRegistroDeDatos(int &opcion)
{
    printf("\n-------------MENU REGISTRO DE DATOS---------------\n");
    printf("1- Ingresar los datos de un nuevo socio (mago). \n");
    printf("2- Ingresar una nueva habilidad. \n");
    printf("3- Salir del menu. \n\n\n");
    scanf("%d", &opcion);
}

void mostrarConsultas(int &opcion)
{
    printf("\n-------------MENU CONSULTAS---------------\n");
    printf("1- Contar cuantos socios de cada categoria magica (brujos, hadas y hechiceros) hay registrados en el sistema. \n");
    printf("2- Contar cuantas habilidades de cada tipo (naturales, poco naturales y sobrenaturales) hay registradas en el sistema. \n");
    printf("3- Dada una fecha de nacimiento, contar cuantos de los socios registrados en el sistema nacieron antes de dicha fecha. \n");
    printf("4- Dadas dos fechas, contar cuantas habilidades fueron ingresadas dentro de dicho rango de fechas (incluidas ambas fechas). \n");
    printf("5- Salir del menu. \n\n\n");
    scanf("%d", &opcion);
}

void mostrarListados(int &opcion)
{
    printf("\n-------------MENU LISTADOS---------------\n");
    printf("1- Listar todos los socios registrados en el sistema, ordenados por cedula de menor a mayor. \n");
    printf("2- Listar todos aquellos socios registrados en el sistema que aun no han manifestado ninguna habilidad, ordenados por cedula de menor a mayor. \n");
    printf("3- Dada la cedula magica de un socio, listar todas las habilidades correspondientes a dicho socio, ordenadas en forma cronologica inversa (desde las mas recientes hacia las mas antiguas). \n");
    printf("4- Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha. \n");
    printf("5- Listar los datos del socio mas poderoso registrado en el sistema. \n");
    printf("6- Salir del menu. \n\n\n");
    scanf("%d", &opcion);
}
