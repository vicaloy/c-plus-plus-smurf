#include <stdio.h>
#include "menu.h"
#include "arbolmagos.h"
#include "mago.h"
#include "habilidad.h"
#include "listahab.h"
#include "files.h"
using namespace std;

int main()
{
    ArbolMagos arbolMagos;
    crearArbol(arbolMagos);
    ListaHab listaHab;
    crearLista(listaHab);
    int opcion=0;

    FILE * fileHab;
    FILE * fileSoc;

    //si no existe los crea - para evitar errores al leer
    if(existe(nomArchHabilidades))
    {
        leerTodasHabilidades(listaHab);
    }
    else
    {
        crearArchivos( fileHab,fileSoc);
    }

    if(existe(nomArchSocios))
    {
        leerTodosMagos(arbolMagos);
    }
    else
    {
        crearArchivos( fileHab,fileSoc);
    }

    do
    {
        mostrarMenuPrincipal(opcion);
        switch(opcion)
        {
        case 1:
            opcion=0;
            do
            {
                mostrarRegistroDeDatos(opcion);
                switch(opcion)
                {
                case 1:
                    printf("1- Ingresar los datos de un nuevo socio (mago). \n");
                    Mago mago;
                    cargarMago(mago);
                    if(pertenece(arbolMagos, darCedula(mago))==FALSE)
                    {
                        insertar(arbolMagos, mago);
                    }
                    else
                    {
                        printf("Cedula ingresada existente. \n");
                    }
                    break;
                case 2:
                    printf("2- Ingresar una nueva habilidad. \n");
                    Habilidad hab;
                    cargarHabilidad(hab);
                    if(pertenece(arbolMagos, darCedulaMago(hab))==TRUE)
                    {
                        insOrdenFecha(listaHab, hab);
                    }
                    else
                    {
                        printf("Cedula ingresada inexistente. \n");
                    }

                    break;
                case 3:
                    printf("Salio del menu registro de datos. \n");
                    break;
                default:
                    printf("Ingrese opcion valida. \n");
                    break;
                }
            }
            while(opcion!=3);
            break;
        case 2:
            opcion=0;
            do
            {
                mostrarConsultas(opcion);
                switch(opcion)
                {

                case 1:
                    printf("1- Contar cuantos socios de cada categoria magica (brujos, hadas y hechiceros) hay registrados en el sistema. \n");
                    printf("Cantidad de Brujos: %d \n", cantidadBrujos(arbolMagos));
                    printf("Cantidad de Hadas: %d \n", cantidadHadas(arbolMagos));
                    printf("Cantidad de Hechiceros: %d \n\n\n", cantidadHechiceros(arbolMagos));
                    break;
                case 2:
                    printf("2- Contar cuantas habilidades de cada tipo (naturales, poco naturales y sobrenaturales) hay registradas en el sistema. \n");
                    int natural, poconatural, sobrenatural;
                    cantidadHab(listaHab, natural, poconatural, sobrenatural);
                    printf("Cantidad de natural: %d \n", natural);
                    printf("Cantidad de poconatural: %d \n", poconatural);
                    printf("Cantidad de sobrenatural: %d \n\n\n", sobrenatural);
                    break;
                case 3:
                    printf("3- Dada una fecha de nacimiento, contar cuantos de los socios registrados en el sistema nacieron antes de dicha fecha. \n");
                    Fecha f;
                    cargarFecha(f);
                    printf("Cantidad de magos nacidos antes de la fecha ingresada: %d", cantNacidosAntesFecha(arbolMagos, f));
                    break;
                case 4:
                    printf("4- Dadas dos fechas, contar cuantas habilidades fueron ingresadas dentro de dicho rango de fechas (incluidas ambas fechas). \n");
                    Fecha primeraFecha;
                    Fecha segundaFecha;
                    cargarFecha(primeraFecha);
                    cargarFecha(segundaFecha);
                    if(primeraFechaMenor(primeraFecha, segundaFecha)==TRUE)
                    {
                        printf("Cantidad de habilidades registradas: %d", cantidadHabRangoFec(listaHab, primeraFecha, segundaFecha));
                    }
                    else
                    {
                        printf("La primera fecha debe ser menor o igual que la segunda. \n");
                    }
                    break;
                case 5:
                    printf("Salio del menu consultas. \n");
                    break;
                default:
                    printf("Ingrese opcion valida. \n");
                    break;

                }
            }
            while(opcion!=5);

            break;
        case 3:
            opcion=0;
            do
            {
                mostrarListados(opcion);
                switch(opcion)
                {
                case 1:
                    printf("1- Listar todos los socios registrados en el sistema, ordenados por cedula de menor a mayor. \n");
                    orden(arbolMagos);
                    break;
                case 2:
                    printf("2- Listar todos aquellos socios registrados en el sistema que aun no han manifestado ninguna habilidad, ordenados por cedula de menor a mayor. \n");
                    mostrarNoTieneHab(arbolMagos, listaHab);
                    break;
                case 3:
                    printf("3- Dada la cedula magica de un socio, listar todas las habilidades correspondientes a dicho socio, ordenadas en forma cronologica inversa (desde las mas recientes hacia las mas antiguas). \n");
                    int ci;
                    printf("Ingrese cedula: ");
                    scanf("%d", &ci);
                    if(perteneceLista(listaHab, ci)==TRUE)
                    {
                        mostrarElemListaPorCedula(listaHab, ci);
                    }
                    else
                    {
                        printf("Cedula inexistente. \n");
                    }
                    break;
                case 4:
                    printf("4- Dada una fecha, listar todas las habilidades que hayan sido manifestadas en dicha fecha. \n");
                    Fecha fec;
                    cargarFecha(fec);
                    mostrarElemListaPorFecha(listaHab, fec);
                    break;
                case 5:
                    printf("5- Listar los datos del socio mas poderoso registrado en el sistema. \n");
                    printf("\nEl mago mas poderoso tiene Ci: %d\n", cedulaMagoPoderoso(listaHab));
                    printf("La lista de sus habilidades son :\n");
                    mostrarElemListaPorCedula(listaHab, cedulaMagoPoderoso(listaHab));
                    break;
                case 6:
                    printf("6- Salio del menu. \n\n\n");
                    break;
                default:
                    printf("Ingrese opcion valida. \n");
                    break;
                }
            }
            while(opcion!=6);

            break;
        case 4:
            printf("Salio del menu principal. \n");
            break;
        default:
            printf("Ingrese opcion valida. \n");
            break;
        }



    }
    while(opcion!=4);

    //escribo los archivos
    bajarTodasHabilidades(listaHab);
    bajarTodosMagos(arbolMagos);



    return 0;
}
