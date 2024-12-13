#include "files.h"
#include "stringdinamico.h"
#include "fecha.h"
#include "categoriamagica.h"
#include "mago.h"
#include "habilidad.h"
#include "boolean.h"
#include "listahab.h"
#include <stdio.h>

//precond: archivo existente
void agregar (StringDinamico nomArch, int entero)
{
    FILE * f = fopen (nomArch, "ab");
    fwrite (&entero, sizeof(int), 1, f);
    fclose (f);
}
//precond: nombrearch no nulo y no debe tener caracteres especiales
boolean existe (StringDinamico nomArch)
{
    boolean existeArchivo = TRUE;
    FILE * f = fopen (nomArch, "rb");
    if (f == NULL)
        existeArchivo = FALSE;
    else
        fclose (f);
    return existeArchivo;
}
//precond: nomArch no nulo y archivo debe existir
boolean vacio (StringDinamico nomArch)
{
    boolean archivoVacio = FALSE;
    FILE * f = fopen (nomArch, "rb");
    fseek (f, 0, SEEK_END);
    if (ftell (f) == 0)
        archivoVacio = TRUE;
    return archivoVacio;
}
//precond: archivo existente y entero no nulo
boolean pertenece (StringDinamico nomArch, int entero)
{
    boolean esta = FALSE;
    FILE * f = fopen (nomArch, "rb");
    int buffer;
    fread (&buffer, sizeof(int), 1, f);
    while (!feof(f) && !esta)
    {
        if (buffer == entero)
            esta = TRUE;
        else
            fread (&buffer, sizeof(int), 1, f);
    }
    fclose (f);
    return esta;
}
//precond: nomarch debe existir
int largo (StringDinamico nomArch)
{
    int largoArchivo;
    FILE * f = fopen (nomArch, "rb");
    fseek (f, 0, SEEK_END);
    largoArchivo = ftell(f) / sizeof(int);
    fclose (f);
    return largoArchivo;
}
//precond: archivo abierto para escritura y string no vacia
void bajarString (StringDinamico s, FILE * f)
{
    int i=0;
    while (s[i] != '\0')
    {
        fwrite (&s[i], sizeof(char), 1, f);
        i++;
    }
    fwrite (&s[i], sizeof(char), 1, f);
}
//precond: archivo abierto para lectura
void levantarString (StringDinamico &s, FILE * f)
{
    int i=0;
    StringDinamico aux;
    aux = new char[MAX];
    fread (&aux[i], sizeof(char), 1, f);
    while (!feof(f) && (aux[i] != '\0'))
    {
        i++;
        fread (&aux[i], sizeof(char), 1, f);
    }
    strcop (s, aux);
    delete [] aux;
}
//precond: archivo abierto para lectura
void levantarFecha (Fecha &fec, FILE *f)
{
    int dia = 0;
    fread (&dia, sizeof(int), 1, f);
    setearDia(fec,dia);

    int mes = 0;
    fread (&mes, sizeof(int), 1, f);
    setearMes(fec,mes);

    int ano = 0;
    fread (&ano, sizeof(int), 1, f);
    setearAno(fec,ano);
}
//precond: archivo abierto para escritura y fecha no vacia
void bajarFecha (Fecha fec, FILE * f)
{
    int dia = darDia(fec);
    fwrite (& dia, sizeof(int), 1, f);

    int mes = darMes(fec);
    fwrite (& mes, sizeof(int), 1, f);

    int ano = darAno(fec);
    fwrite (& ano , sizeof(int), 1, f);
}
//precond:el nomArchSocios debe ser valido y permita su escritura
void bajarTodosMagos(ArbolMagos a)
{
    FILE *f = fopen(nomArchSocios,"wb");
    ordenArchivo(a, f);
    //cerrar arch
    fclose (f);
}
//precond: archivo abierto para escritura y mago no vacio
void bajarMago (Mago m, FILE * f)
{
    StringDinamico nom;
    strcrear(nom);
    darNombreMago(m,nom);
    bajarString (nom, f);

    StringDinamico ori;
    strcrear(ori);
    darOrigenMago(m,ori);
    bajarString (ori, f);

    Fecha fNac = darFechaNac(m);
    bajarFecha(fNac, f);

    int ced = darCedula(m);
    fwrite (&ced, sizeof(int), 1, f);

    CategoriaMagica cat = darCategoriaMagica(m) ;
    fwrite (&cat, sizeof(int), 1, f);
}
//precond: archivo abierto para escritura
void ordenArchivo (ArbolMagos a, FILE * f)
{
    if (a != NULL)
    {
        ordenArchivo (a -> hIzq, f);
        bajarMago(a->mago,f);
        ordenArchivo (a -> hDer, f);
    }
}
//precond: archivo abierto para lectura
void leerTodosMagos(ArbolMagos &a)
{
    if(vacio(nomArchSocios)== FALSE)
    {
        FILE *f = fopen(nomArchSocios,"rb");
        Mago m;
        levantarMago(m,f);
        while(!feof(f) )
        {
            insertar(a,m);
            levantarMago(m,f);
        }
        //cerrar arch
        fclose (f);
    }
}
//precond: archivo abierto para lectura
void levantarMago (Mago &m, FILE *f)
{

    StringDinamico nomb;
    strcrear(nomb);
    levantarString(nomb, f);
    setearNombreMago(m,nomb);

    StringDinamico ori;
    strcrear(ori);
    levantarString(ori, f);
    setearOrigenMago(m,ori);

    Fecha fNac;
    levantarFecha(fNac, f);
    setearFechaNac(m,fNac);

    int cedula = 0;
    fread (&cedula, sizeof(int), 1, f);
    setearCedula(m,cedula);

    CategoriaMagica cat;
    fread(&cat, sizeof(int), 1, f);
    setearCategoria(m,cat);
}

//precond: nomarchhabilidades valido y q permita su escritura
void bajarTodasHabilidades(ListaHab l)
{
    //abrir archivo
    FILE *f = fopen(nomArchHabilidades,"wb");
    while (l != NULL )
    {
        bajarHabilidad(l ->hab, f);
        l = l -> sig;
    }
    //cerrar arch
    fclose (f);
}
//precond: nomarchhabilidades valido y exista
void leerTodasHabilidades(ListaHab &l)
{
    if(vacio(nomArchHabilidades)== FALSE)
    {
        Habilidad habLeida;
        FILE *f = fopen(nomArchHabilidades,"rb");

        levantarHabilidad(habLeida, f);
        while ( !feof(f))
        {
            insBack(l,habLeida);
            levantarHabilidad(habLeida, f);
        }
        //cerrar arch
        fclose (f);
    }
}
//precond: archivo abierto para escritura y habilidad no vacia
void bajarHabilidad (Habilidad h, FILE * f)
{
    int cedula = darCedulaMago(h);
    fwrite (&cedula, sizeof(int), 1, f);

    StringDinamico nombre;
    strcrear(nombre);
    darNombreHab(h,nombre);
    bajarString(nombre,f);

    Fecha fManif =  darFechaManif(h);
    bajarFecha(fManif,f);

    TipoHabilidad tHab = darTipoHabilidad(h);
    fwrite (&tHab, sizeof(int), 1, f);
}
//precond: archivo abierto para lectura
void levantarHabilidad (Habilidad &h, FILE * f)
{
    int cedula = 0;
    fread (&cedula, sizeof(int), 1, f);
    setearCedulaHab(h,cedula);

    StringDinamico nomHab;
    strcrear(nomHab);
    levantarString(nomHab, f);
    setearNombreHab(h,nomHab);

    Fecha fMan;
    levantarFecha(fMan,f);
    setearFechaManif(h,fMan);

    TipoHabilidad tHab;
    fread (&tHab, sizeof(int), 1, f);
    setearTipoHabilidad(h,tHab);

}
//precond: nombres de archivo valudos sin caracteres especiales y permisos de ejecucion para leer y crear archivos
void crearArchivos( FILE * &fHabilidad, FILE * &fSocios)
{
    fHabilidad = fopen (nomArchHabilidades, "wb");
    fclose (fHabilidad);

    fSocios = fopen (nomArchSocios, "wb");
    fclose (fSocios);
}
//precond: archivos existentes y abiertos.
void cerrarArchivos( FILE * &fHabilidad, FILE * &fSocios)
{
    fclose (fHabilidad);
    fclose (fSocios);
}


