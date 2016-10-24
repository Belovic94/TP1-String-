#include"lib.h"

int main(int argc, char *argv[]){
  if(argc != 3){
    fprintf(stderr, "La funcion solo acepta 2 archivos\n");
    return EXIT_FAILURE;
  }

  char *linea1 = NULL, *linea2 = NULL; //*linea_aux;
  size_t capacidad1 = 0, capacidad2 = 0;

  FILE *arch_1 = abrir_archivo(argv[1]);
  if(!arch_1)//si no se puede abrir el primer archivo, termino el programa.
    return EXIT_FAILURE;

  FILE *arch_2 = abrir_archivo(argv[2]);
  if(!arch_2){//si no se puede abrir el segundo archivo, termino el programa.
    fclose(arch_1);
    return EXIT_FAILURE;
  }

  ssize_t long1 = getline(&linea1, &capacidad1, arch_1);
  ssize_t long2 = getline(&linea2, &capacidad2, arch_2);
  while( long1 != FIN && long2 != FIN){//me fijo que se puede leer en ambos archivos.
    modificar_caracter(&linea1, '\n', TABULACION);//saco el \n de la primera linea y coloco una tabulacion;
    //linea_aux = strchr(linea1, '\n');
    //linea1[strlen(linea1) - strlen(linea_aux)] = TABULACION;
    fprintf(stdout, "%s%s", linea1, linea2);
    long1 = getline(&linea1, &capacidad1, arch_1);//leo una linea de ambos archivos.
	  long2 = getline(&linea2, &capacidad2, arch_2);
  }

  free(linea1);
  free(linea2);

  if((long1 == FIN) ^ (long2 == FIN)){//me fijo si se puede seguir leyendo alguno de los archivos.
    fclose(arch_1);
    fclose(arch_2);
    fprintf(stderr, "Los archivos deben tener la misma cantidad de lineas\n");
    return EXIT_FAILURE;
  }

  fclose(arch_1);
  fclose(arch_2);
  return EXIT_SUCCESS;
}
