#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#define TABULACION '\t'
#define FALLO -1
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0

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

int main(int argc, char *argv[]){
  if(argc != 3){
    fprintf(stderr, "La funcion solo acepta 2 archivos\n");
    return EXIT_FAILURE;
  }

  char *linea1, *linea2;
  size_t capacidad1 = 0, capacidad2 = 0;
  FILE *arch_1 = abrir_archivo(argv[1]);
  if(!arch_1)//si no se puede abrir el primer archivo, termino el programa.
    return EXIT_FAILURE;
  FILE *arch_2 = abrir_archivo(argv[2]);
  if(!arch_2)//si no se puede abrir el segundo archivo, termino el programa.
    return EXIT_FAILURE;
  
  while(getline(&linea1, &capacidad1, arch_1) != FALLO//leo una linea de ambos archivos.
          && getline(&linea2, &capacidad2, arch_2) != FALLO){
    fprintf(stdout, "%s\t%s\n", linea1, linea2);
    free(linea1);
    free(linea2);
  }
  if(getline(&linea1, &capacidad1, arch_1) != FALLO//me fijo si se puede seguir leyendo
      || getline(&linea2, &capacidad2, arch_2) != FALLO){//alguno de los archivos.
    fprintf(stderr, "Los archivos deben tener la misma cantidad de lineas\n");
    return EXIT_FAILURE;
  }

  fclose(arch_1);
  fclose(arch_2);
  return EXIT_SUCCESS;
}
