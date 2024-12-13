#include<stdio.h>
#include "arbolmagos.h"

//crear arbol vacio
void crearArbol(ArbolMagos &a)
{
    a=NULL;
}

//obtener raiz
//PRECOND: No debe estar vacio
Mago darRaiz(ArbolMagos a)
{
    return a->mago;
}

//obtener hijo izquierdo
//PRECOND: No debe estar vacio
ArbolMagos darHIzq(ArbolMagos a)
{
    return a->hIzq;
}

//obtener hijo derecho
//PRECOND: No debe estar vacio
ArbolMagos darHDer(ArbolMagos a)
{
    return a->hDer;
}

//saber si esta vacio
boolean esVacioArbol(ArbolMagos a)
{
    boolean vacio=FALSE;
    if(a==NULL)
    {
        vacio=TRUE;
    }

    return vacio;
}

//Constructor: dados 2 arboles y un valor devolver un nuevo arbol con ese valor
//como raiz y los subarboles como hijos
//precond: arboles no vacios
ArbolMagos cons(Mago mago, ArbolMagos izq, ArbolMagos der)
{
    ArbolMagos a;
    a=new NodoMagos;
    a->mago=mago;
    a->hIzq=izq;
    a->hDer=der;
    return a;
}

// insertar un nuevo valor en el arbol
//PRECOND: el valor no existía previamente en el arbol
void insertar (ArbolMagos &a, Mago mago)
{
    if (a == NULL)
    {
        a = new NodoMagos;
        a -> mago = mago;
        a -> hIzq = NULL;
        a -> hDer = NULL;
    }
    else if (mago.cedula < darCedula( a-> mago))
    {
        insertar(a->hIzq,mago);
    }
    else
    {
        insertar(a->hDer,mago);
    }
}

// saber si un elemento pertenece al arbol
//precond: cedula no vacia
boolean pertenece(ArbolMagos a, int cedula)
{
    if (a == NULL)
        return FALSE;
    else if (darCedula(a-> mago) == cedula)
        return TRUE;
    else if (cedula < darCedula(a->  mago))
        return pertenece(a->hIzq,cedula);
    else
        return pertenece(a->hDer,cedula);
}
//precond: si tiene magos, q tenga su categoriamagica cargada
int cantidadBrujos(ArbolMagos a)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        if(darCategoriaMagica(a->mago)==BRUJO)
        {
            return 1 + cantidadBrujos(a->hIzq) + cantidadBrujos(a->hDer);
        }
        else
        {
            return cantidadBrujos(a->hIzq) + cantidadBrujos(a->hDer);
        }
    }
}
//precond: si tiene magos, q tenga su categoriamagica cargada
int cantidadHechiceros(ArbolMagos a)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        if(darCategoriaMagica(a->mago)==HECHICERO)
        {
            return 1 + cantidadHechiceros(a->hIzq) + cantidadHechiceros(a->hDer);
        }
        else
        {
            return cantidadHechiceros(a->hIzq) + cantidadHechiceros(a->hDer);
        }
    }
}
//precond: si tiene magos, q tenga su categoriamagica cargada
int cantidadHadas(ArbolMagos a)
{
    if (a == NULL)
    {
        return 0;
    }
    else
    {
        if(darCategoriaMagica(a->mago)==HADA)
        {
            return 1 + cantidadHadas(a->hIzq) + cantidadHadas(a->hDer);
        }
        else
        {
            return cantidadHadas(a->hIzq) + cantidadHadas(a->hDer);
        }
    }
}
//precond: si tiene mago, q tenga cargada su fechanac
int cantNacidosAntesFecha(ArbolMagos a, Fecha f)
{

    if (a == NULL)
    {
        return 0;
    }
    else
    {
        if(primeraFechaMayor(f, darFechaNac(a->mago))==TRUE)
        {
            return 1 + cantNacidosAntesFecha(a->hIzq, f) + cantNacidosAntesFecha(a->hDer, f);
        }
        else
        {
            return cantNacidosAntesFecha(a->hIzq, f) + cantNacidosAntesFecha(a->hDer, f);
        }
    }
}
//precond: si tiene magos, que tenga sus campos cargados
void preorden (ArbolMagos a)
{
    if (a != NULL)
    {
        mostrarMago(a->mago);
        preorden (a -> hIzq);
        preorden (a -> hDer);
    }
}
//precond: si tiene magos, que tenga sus campos cargados
void orden (ArbolMagos a)
{
    if (a != NULL)
    {
        orden (a -> hIzq);
        mostrarMago(a->mago);
        orden (a -> hDer);
    }
}

//precond: si tiene magos, que tenga sus campos cargados
void postOrden (ArbolMagos a)
{
    if (a != NULL)
    {
        postOrden (a -> hIzq);
        postOrden (a -> hDer);
        mostrarMago(a->mago);
    }
}
//precond: magos con cedulas cargadas
void mostrarNoTieneHab(ArbolMagos a, ListaHab lista)
{
    if (a != NULL)
    {
       mostrarNoTieneHab (a -> hIzq, lista);
        if(perteneceLista(lista,  darCedula(a->mago))==FALSE){
            mostrarMago(a->mago);
        }
        mostrarNoTieneHab (a -> hDer, lista);
    }
}
