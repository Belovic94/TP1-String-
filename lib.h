#ifndef LIB_H
#define LIB_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Constantes a utilizar*/
#define FIN -1
#define SALIDA 'q'
#define TABULACION '\t'

typedef enum{SUMA = 43, RESTA = 45, MULTIPLICACION = 42, DIVISION = 47}operador_t;
FILE *abrir_archivo(char *);
void modificar_caracter(char**, char, char);

#endif //LIB_H
