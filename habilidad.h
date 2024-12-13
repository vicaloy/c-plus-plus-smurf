#ifndef HABILIDAD_H_INCLUDED
#define HABILIDAD_H_INCLUDED
#include "stringdinamico.h"
#include "fecha.h"
#include "tipohabilidad.h"
typedef struct{
int cedulaMago;
StringDinamico nombreHabilidad;
Fecha fechaManif;
TipoHabilidad tipoHabilidad;
}Habilidad;

void mostrarHabilidad(Habilidad h);
void cargarHabilidad(Habilidad &h);
int darCedulaMago(Habilidad h);
void setearCedulaHab(Habilidad &h, int ced);

void darNombreHab(Habilidad h, StringDinamico &nombre);
void setearNombreHab(Habilidad &h, StringDinamico &nombre);

Fecha darFechaManif(Habilidad h);
void setearFechaManif(Habilidad &h, Fecha fman);

TipoHabilidad darTipoHabilidad(Habilidad h);
void setearTipoHabilidad(Habilidad &h, TipoHabilidad tHab);


#endif // HABILIDAD_H_INCLUDED
