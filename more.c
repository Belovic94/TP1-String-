#include "lib.h"


int tecla_presionada(void){
  int tecla = getchar();
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
  long cant_inicial = strtol(argv[2], &ptr, 10);//verifico que el segundo parametro sea un numero entero.
  if(ptr || cant_inicial == 0){
    fprintf(stderr, "La cantidad de lineas iniciales a mostrar tiene que ser un numero entero\n");
    return EXIT_FAILURE;
  }
  FILE *archivo = abrir_archivo(argv[1]);
  if(!archivo)//si no se puede abrir el archivo, termino el programa.
    return EXIT_FAILURE;

  size_t capacidad = 0;
  char* linea = NULL;
  for (long i = 0; i < cant_inicial && getline(&linea, &capacidad, archivo) != FIN; i++){
    printf("%s", linea);
  }

  int tecla = 0;
  while(getline(&linea, &capacidad, archivo) != FIN && tecla != SALIDA){
    printf("Ingrese 'enter' para ver la siguiente linea o 'q' para salir \n");
    tecla = tecla_presionada();
    if(tecla == '\n'){
	  fprintf(stdout, "%s", linea);
    }
  }
  free(linea);
  fclose(archivo);
  return EXIT_SUCCESS;
}
