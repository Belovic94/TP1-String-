#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <string.h>
#define FALLO -1
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define SALIDA 'q'

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

char tecla_presionada(void){
  char tecla = getchar();
  while(tecla != '\n' && tecla != 'q'){
    fflush(stdin);
    tecla = getchar();
  }
  return tecla;
}

int main(int argc, char *argv[]){
  if(argc != 3){
    fprintf(stderr, "La funcion solo acepta 2 parametros \n");
    return EXIT_FAILURE;
  }
  cant_inicial = atoi(argv[2]);
  if(cant_inicial == 0)
    fprintf(stderr, "La cantidad de lineas iniciales a mostrar tiene que ser un numero entero\n");
  FILE *archivo = abrir_archivo(argv[1]);
  if(!archivo)//si no se puede abrir el archivo, termino el programa.
    return EXIT_FAILURE;
  size_t capacidad = 0, i;
  char* linea;
  for (i = 0; i < cant_inicial && getline(&linea, &capacidad, archivo) != FALLO); i++){
    printf("%s\n", linea);
    free(linea);
  }
  if(i < cant_inicial - 1)
    return EXIT_SUCCESS;
  char tecla;
  do{
    printf("Ingrese 'enter' para ver la siguiente linea o 'q' para salir \n", );
    tecla = tecla_presionada();
    if(tecla == '\n' && getline(&linea, &capacidad, archivo) != FALLO){
      printf("%s\n", linea);
      free(linea);
    }
  }while(tecla != SALIDA);
