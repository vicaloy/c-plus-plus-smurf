#include<stdio.h>
#include "listahab.h"

//crea lista vacia
void crearLista(ListaHab &lis)
{
    lis = NULL;
}
//dice si la lista esta vacia
boolean vaciaLista(ListaHab lis)
{
    boolean es = FALSE;
    if (lis == NULL)
        es = TRUE;
    return es;
}
//devuelve el primer elemento de la lista
//PRECOND: lista NO vacía
Habilidad primero (ListaHab lis)
{
    return lis -> hab;
}
//borra el primer elemento de la lista
//PRECOND: lista NO vacía
void resto(ListaHab &lis)
{
    ListaHab aux = lis;
    lis = lis -> sig;
    delete aux;
}
//agrega un elemento al principio de la lista
void insFront (ListaHab &lis, Habilidad h)
{
    ListaHab aux = new NodoHab;
    aux -> hab = h;
    aux -> sig = lis;
    lis = aux;
}

//agrega un elemento al FINAL de la lista
void insBack (ListaHab &lis, Habilidad h)
{

    if(lis==NULL)
    {
        //lista vacia
        lis=new NodoHab;
        lis->hab=h;
        lis->sig=NULL;
    }
    else
    {
        ListaHab aux = new NodoHab;
        aux -> hab = h;
        aux -> sig = NULL;

        //encadeno aal ultimo nodo
        ListaHab ultimoEle = UltimoIter(lis);
        ultimoEle -> sig = aux;
    }

}

// Precondición: L no está vacía
ListaHab UltimoIter (ListaHab l)
{
    while (l!= NULL && l ->sig != NULL)
    {
        l = l -> sig;
    }

    return (l);
}



//inserta en orden de fecha en la lista
void insOrdenFecha(ListaHab &lis, Habilidad h)
{
    ListaHab aux = lis;
    ListaHab itemAnterior;
    crearLista(itemAnterior);
    boolean coloque=FALSE;

    if(lis==NULL)
    {
        //lista vacia
        lis=new NodoHab;
        lis->hab=h;
        lis->sig=NULL;
    }
    else
    {
        //lista con elementos
        while (coloque==FALSE)
        {
            if (primeraFechaMayor(darFechaManif(h), aux->hab.fechaManif)==TRUE)
            {
                coloque=TRUE;
                if(itemAnterior!=NULL)
                {
                    itemAnterior->sig=new NodoHab;
                    itemAnterior->sig->hab=h;
                    itemAnterior->sig->sig =aux;
                }
                else
                {
                    itemAnterior=new NodoHab;
                    itemAnterior->hab=h;
                    itemAnterior->sig=aux;
                    lis=itemAnterior;
                }

            }
            itemAnterior=aux;
            aux = aux -> sig;
        }
    }
}

void cantidadHab(ListaHab lista, int &natural, int &pocoNatural, int &sobreNatural)
{
    natural=0;
    pocoNatural=0;
    sobreNatural=0;

    while(lista!=NULL)
    {
        if(darTipoHabilidad(lista->hab)==NATURAL)
        {
            natural++;
        }
        else if(darTipoHabilidad(lista->hab)==POCONATURAL)
        {
            pocoNatural++;
        }
        else if(darTipoHabilidad(lista->hab)==SOBRENATURAL)
        {
            sobreNatural++;
        }

        lista=lista->sig;
    }
}
//precond: las fechas no son nulas
int cantidadHabRangoFec(ListaHab lista, Fecha primeraFec, Fecha segundaFec)
{
    int cantidad=0;
    while(lista!=NULL && primeraFechaMenor(primeraFec, darFechaManif(lista->hab))==TRUE)
    {
        if(primeraFechaMayor(segundaFec, darFechaManif(lista->hab))==TRUE)
        {
            cantidad++;
        }

        lista=lista->sig;
    }

    return cantidad;
}

//precond: lista y cedula no nulas
boolean perteneceLista (ListaHab l, int cedula)
{
    boolean encontre = FALSE;
    while (l != NULL && encontre==FALSE)
    {
        if (darCedulaMago(l ->hab) == cedula)
        {
            encontre = TRUE;
        }
        else
        {
            l = l -> sig;
        }
    }
    return encontre;
}

//precond: liusta y cedula no nula
void mostrarElemListaPorCedula (ListaHab l, int cedula)
{

    while (l != NULL )
    {
        if (darCedulaMago(l ->hab) == cedula)
        {
            mostrarHabilidad(l->hab);
        }
        l = l -> sig;

    }
}

//precond: lista y fecha no nula
void mostrarElemListaPorFecha (ListaHab l, Fecha f)
{
    while (l != NULL)
    {
        if (fechasIguales( darFechaManif(l->hab), f)==TRUE)
        {
            mostrarHabilidad(l->hab);
            l = l -> sig;

        }
        else
        {
            l = l -> sig;
        }
    }
}

//precond: lista y cedula no nula
int contarCedulaLista (int cedula, ListaHab lista)
{
    int cant = 0;
    while (lista != NULL)
    {
        if (lista -> hab.cedulaMago == cedula)
            cant++;
        lista = lista -> sig;
    }
    return cant;
}

//precond: lista no nula con al menos un mago con su cedula cargada
int cedulaMagoPoderoso(ListaHab l)
{
    int cantMayor=0;
    int auxCont=0;
    int ciMayor=0;
    while(l!=NULL)
    {
        auxCont=contarCedulaLista( darCedulaMago(l->hab), l);
        if(cantMayor<auxCont)
        {
            cantMayor=auxCont;
            ciMayor= darCedulaMago( l->hab);
        }
        l=l->sig;
    }

    return ciMayor;
}
