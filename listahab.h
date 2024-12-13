#ifndef LISTAHAB_H_INCLUDED
#define LISTAHAB_H_INCLUDED
#include "habilidad.h"
#include "boolean.h"
typedef struct nodo {
Habilidad hab;
nodo * sig;
} NodoHab;
typedef NodoHab * ListaHab;

//crea lista vacia
void crearLista(ListaHab &lis);
//dice si la lista esta vacia
boolean vaciaLista(ListaHab lis);
//devuelve el primer elemento de la lista
//PRECOND: lista NO vacía
Habilidad primero (ListaHab lis);
//borra el primer elemento de la lista
//PRECOND: lista NO vacía
void resto(ListaHab &lis);
//agrega un elemento al principio de la lista
void insFront (ListaHab &lis, Habilidad h);
//inserta en orden de fecha en la lista
void insOrdenFecha(ListaHab &lis, Habilidad h);

void cantidadHab(ListaHab lista, int &natural, int &pocoNatural, int &sobreNatural);

int cantidadHabRangoFec(ListaHab lista, Fecha primeraFec, Fecha segundaFec);

boolean perteneceLista (ListaHab l, int cedula);

void mostrarElemListaPorCedula(ListaHab l, int cedula);

void mostrarElemListaPorFecha(ListaHab l, Fecha fecha);

int contarCedulaLista (int cedula, ListaHab lista);

int cedulaMagoPoderoso(ListaHab l);
ListaHab UltimoIter (ListaHab L) ;
void insBack (ListaHab &lis, Habilidad h);


#endif // LISTAHAB_H_INCLUDED
