#ifndef STRINGDINAMICO_H_INCLUDED
#define STRINGDINAMICO_H_INCLUDED
#include "boolean.h"
const int MAX=80;
typedef char *StringDinamico;

//crea un string vacío (solo con el carácter ‘\0’)
void strcrear (StringDinamico &cadena);
//libera la memoria ocupada por el string y lo deja nulo.
void strdestruir(StringDinamico &cadena);
//strlar que devuelva el largo de un string.
int strlar(StringDinamico cadena);
//strcop que reciba dos strings y copie el segundo en el primero.
void strcop(StringDinamico &cadenaUno, StringDinamico cadenaDos);
//scan que lea un string desde el teclado
void scan(StringDinamico &cadena);
//strcon que reciba dos strings y concatene el segundo string al final del primero
void strcon(StringDinamico &cadenaUno, StringDinamico cadenaDos);
//strswp que reciba dos strings y devuelva el primero en el segundo y viceversa.
void strswap(StringDinamico &cadenaUno, StringDinamico &cadenaDos);
//print que despliegue un string por pantalla.
void print(StringDinamico cadena);
//strmen que reciba dos strings y devuelva TRUE si el primero de ellos es menor (en orden alfabético) que el segundo, o FALSE en caso contrario.
boolean strmen(StringDinamico cadenaUno, StringDinamico cadenaDos);
//streq que reciba dos strings y devuelva TRUE si ambos strings son iguales o FALSE en caso contrario.
boolean streq(StringDinamico cadenaUno, StringDinamico cadenaDos);


#endif // STRINGDINAMICO_H_INCLUDED
