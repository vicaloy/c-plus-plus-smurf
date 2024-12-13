#ifndef ARBOLMAGOS_H_INCLUDED
#define ARBOLMAGOS_H_INCLUDED
#include "mago.h"
#include "listahab.h"
typedef struct Nodo{
Mago mago;
Nodo * hIzq;
Nodo * hDer;
}NodoMagos;

typedef NodoMagos *ArbolMagos;

//crear arbol vacio
void crearArbol(ArbolMagos &a);

//obtener raiz
//PRECOND: No debe estar vacio
Mago darRaiz(ArbolMagos a);

//obtener hijo izquierdo
//PRECOND: No debe estar vacio
ArbolMagos darHIzq(ArbolMagos a);

//obtener hijo derecho
//PRECOND: No debe estar vacio
ArbolMagos darHDer(ArbolMagos a);

//saber si esta vacio
boolean esVacioArbol(ArbolMagos a);

//Constructor: dados 2 arboles y un valor devolver un nuevo arbol con ese valor
//como raiz y los subarboles como hijos
ArbolMagos cons(Mago mago, ArbolMagos izq, ArbolMagos der);

// insertar un nuevo valor en el arbol
//PRECOND: el valor no existía previamente en el ABB
void insertar(ArbolMagos &a, Mago mago);

// saber si un elemento pertenece al arbol
boolean pertenece (ArbolMagos a, int cedula);

int cantidadBrujos(ArbolMagos a);
int cantidadHechiceros(ArbolMagos a);
int cantidadHadas(ArbolMagos a);

int cantNacidosAntesFecha(ArbolMagos a, Fecha f);

void preorden (ArbolMagos a);
void orden (ArbolMagos a);
void postorden (ArbolMagos a);

void mostrarNoTieneHab(ArbolMagos a, ListaHab lista);



#endif // ARBOLMAGOS_H_INCLUDED
