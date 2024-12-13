#ifndef FILES_H_INCLUDED
#define FILES_H_INCLUDED
#include "stringdinamico.h"
#include "fecha.h"
#include "categoriamagica.h"
#include "boolean.h"
#include "mago.h"
#include "habilidad.h"
#include "listahab.h"
#include "arbolmagos.h"
#include <stdio.h>

const StringDinamico nomArchSocios = "Socios.txt";
const StringDinamico nomArchHabilidades = "Habilidades.txt";

void agregar (StringDinamico nomArch, int entero);
boolean existe (StringDinamico nomArch);

boolean vacio (StringDinamico nomArch);
boolean pertenece (StringDinamico nomArch, int entero);
int largo (StringDinamico nomArch);

void bajarString (StringDinamico s, FILE * f);
void levantarString (StringDinamico &s, FILE * f);

void levantarFecha (Fecha &fec, FILE *f);

void bajarFecha (Fecha fec, FILE * f);

void bajarMago (Mago m, FILE * f);

void levantarMago (Mago &m, FILE *f);


void bajarHabilidad (Habilidad h, FILE * f);

void levantarHabilidad (Habilidad &h, FILE * f);

void bajarTodasHabilidades(ListaHab l);
void leerTodasHabilidades(ListaHab &l);

void bajarTodosMagos(ArbolMagos a);
void ordenArchivo (ArbolMagos a, FILE *f);
void leerTodosMagos(ArbolMagos &a);


void crearArchivos( FILE * &fHabilidad, FILE * &fSocios);
void cerrarArchivos( FILE * &fHabilidad, FILE * &fSocios);




#endif // FILES_H_INCLUDED
