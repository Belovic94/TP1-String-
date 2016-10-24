#include "lib.h"


FILE *abrir_archivo(char *nom_arch){
  if(!nom_arch)
    return NULL;
  FILE *archivo = fopen(nom_arch, "r");
  if(!archivo){
    fprintf(stderr, "No se pudo abrir el archivo: %s\n", nom_arch);
    return NULL;
  }
  return archivo;
}

void modificar_caracter(char** cadena, char letra_ant, char letra_nueva){
  char *cadena_aux = strchr(*cadena, letra_ant);//encuentro la posicion de la letra a cambiar;
  (*cadena)[strlen(*cadena) - strlen(cadena_aux)] = letra_nueva;
}
