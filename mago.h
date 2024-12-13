#ifndef MAGO_H_INCLUDED
#define MAGO_H_INCLUDED
#include "stringdinamico.h"
#include "fecha.h"
#include "categoriamagica.h"
#include "boolean.h"
typedef struct{
int cedula;
StringDinamico nombreMago;
Fecha fechaNac;
CategoriaMagica categoria;
StringDinamico origen;
}Mago;

void mostrarMago(Mago mago);
void cargarMago(Mago &mago);
int darCedula(Mago mago);
void setearCedula(Mago &mago, int ced );

void darNombreMago(Mago mago, StringDinamico &nombre);
void setearNombreMago(Mago &mago, StringDinamico nombre);


void darOrigenMago(Mago mago, StringDinamico &origen);
void setearOrigenMago(Mago &mago, StringDinamico origen);


Fecha darFechaNac(Mago mago);
void setearFechaNac(Mago &mago, Fecha fnac);

CategoriaMagica darCategoriaMagica(Mago mago);
void setearCategoria(Mago &mago, CategoriaMagica cat );

#endif // MAGO_H_INCLUDED
