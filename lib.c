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
