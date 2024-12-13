#include "stringdinamico.h"
#include <stdio.h>
//crea un string vacío (solo con el carácter ‘\0’)
void strcrear (StringDinamico &cadena)
{
    cadena=new char[1];
    cadena[0]='\0';
}
//libera la memoria ocupada por el string y lo deja nulo.
void strdestruir(StringDinamico &cadena)
{
    delete[]cadena;
    cadena=NULL;
}
//strlar que devuelva el largo de un string.
//precond: cadena no vacia
int strlar(StringDinamico cadena)
{
    int i=0;
    while(cadena[i]!='\0')
    {
        i++;
    }

    return i;
}
//strcop que reciba dos strings y copie el segundo en el primero.
//precond: cadenas no vacias
void strcop (StringDinamico &s1,StringDinamico s2)
{
    int i = 0;
    int largo = strlar(s2) + 1;
    delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}
//scan que lea un string desde el teclado
//precond:que se ingresen valores por la entrada estandar
void scan (StringDinamico &s)
{
    StringDinamico aux = new char[MAX];
    int i=0;
    char c;
    scanf ("%c", &c);
    while (c!= '\n' && i < MAX-1)
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    strcop (s,aux);
    strdestruir (aux);
}
//strcon que reciba dos strings y concatene el segundo string al final del primero
//precond: cadenas no vacias
void strcon(StringDinamico &cadenaUno, StringDinamico cadenaDos)
{
    int i=0;
    int j=0;

    j=strlar(cadenaUno);
    while(j<MAX-1 && cadenaDos[i]!='\0')
    {
        cadenaUno[j]=cadenaDos[i];
        i++;
        j++;
    }
    cadenaUno[j]='\0';
}
//strswp que reciba dos strings y devuelva el primero en el segundo y viceversa.
//precond: cadenas no vacias
void strswap(StringDinamico &cadenaUno, StringDinamico &cadenaDos)
{
    int i=0;
    int j=0;
    int k=0;
    StringDinamico cadenaAux = new char;

    while(cadenaUno[i]!='\0')
    {
        cadenaAux[i]=cadenaUno[i];
        i++;
    }
    cadenaAux[i]='\0';

    while(cadenaDos[j]!='\0')
    {
        cadenaUno[j]=cadenaDos[j];
        j++;
    }
    cadenaUno[j]='\0';

    while(cadenaAux[k]!='\0')
    {
        cadenaDos[k]=cadenaAux[k];
        k++;
    }
    cadenaDos[k]='\0';
}
//print que despliegue un string por pantalla.
//precond: cadena no vacia
void print(StringDinamico cadena)
{
    int i=0;
    while(cadena[i]!='\0')
    {
        printf("%c", cadena[i]);
        i++;
    }
}
//strmen que reciba dos strings y devuelva TRUE si el primero de ellos es menor (en orden alfabético) que el segundo, o FALSE en caso contrario.
//precond: cadena no vacia
boolean strmen(StringDinamico cadenaUno, StringDinamico cadenaDos)
{
    boolean retorno=TRUE;
    int i=0;
    while(cadenaUno[i]!='\0' && cadenaDos[i]!='\0')
    {
        if(cadenaUno[i]>cadenaDos[i])
        {
            retorno=FALSE;
        }
        i++;
    }
    return retorno;
}
//streq que reciba dos strings y devuelva TRUE si ambos strings son iguales o FALSE en caso contrario.
//precond: cadena no vacia
boolean streq(StringDinamico cadenaUno, StringDinamico cadenaDos)
{
    boolean retorno=TRUE;
    int i=0;
    while(cadenaUno[i]!='\0' && cadenaDos[i]!='\0')
    {
        if(cadenaUno[i]!=cadenaDos[i])
        {
            retorno=FALSE;
        }
        i++;
    }
    return retorno;
}
