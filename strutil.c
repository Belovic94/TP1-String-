#include "strutil.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char* agregar_cadena(const char* str, size_t indice){
  printf("%ld\n", indice );
  char* str_aux =  malloc(indice + 1);
  if(!str_aux)
    return NULL;
  strncpy(str_aux, str, indice);
  str_aux[indice] = '\0';
  printf("%s\n",str_aux );
  return str_aux;
}

char** split(const char* str, char sep){
  char* vector[strlen(str)];
  char *pal_aux = strchr(str, sep);
  size_t i = 0;
  while(pal_aux != NULL){
    printf("PAL_AUX %s\n", pal_aux);
    printf("STR %s\n", str);
    printf("Indice %ld\n", strlen(str));
    printf("%ld\n",strlen(pal_aux) );
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
  if(!strv || sep == '\0')
    return NULL;
  size_t i = 0;
  char *str_aux = strv[i];
  for(i = 1; strv[i] != NULL; i++){
    str_aux[strlen(str_aux) - 1] = sep;
    strcat(str_aux, strv[i]);
    i++;
  }
  if(i == 0)
    str_aux = '\0';
  char *str = malloc(strlen(str_aux) + 1);
  if(!str)
    return NULL;
  sprintf(str, "%s", str_aux);
  return str;
}

void free_strv(char* strv[]){
  if(!strv)
    return;
  for(int i = 0; strv[i] != NULL; i++){
    free(strv[i]);
  }
  free(strv);
}
