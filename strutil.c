#include "strutil.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* agregar_cadena(const char* str, size_t indice){
  char* str_aux =  malloc(indice + 1);
  if(!str_aux)
    return NULL;
  strncpy(str_aux, str, indice);
  str_aux[indice] = '\0';
  return str_aux;
}

char** split(const char* str, char sep){
  char* vector[strlen(str)];
  char *pal_aux = strchr(str, sep);
  size_t i = 0;
  while(pal_aux != NULL){
    vector[i] = agregar_cadena(str, strlen(str) - strlen(pal_aux));
    str = pal_aux + 1;
    pal_aux = strchr(pal_aux + 1, sep);
    i++;
  }
  vector[i] = agregar_cadena(str, strlen(str));
  i++;
  vector[i] = NULL;
  //paso claves del vector local al vector hecho con malloc
  char **strv = malloc((i + 1) * sizeof(char*));
  if(!strv)
    return NULL;
  for(int j = 0; j < i; j++){
    strv[j] = vector[j];
  }
  return strv;

}

char* join(char** strv, char sep){
  
}
