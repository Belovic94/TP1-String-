#include "lib.h"
#include <stdbool.h>
#include "pila.h"
#include "strutil.h"
#define NUM_PRUEBA_1 1
#define NUM_PRUEBA_2 3

bool es_numero(char* letras){
	char* ptr = NULL;
	double num = strtod(letras, &ptr);
	return strcmp(ptr, "") == 0 && num != 0;
}

double operar(int operador, double num1, double num2){
	double res = 0;
	switch(operador){
		case SUMA:
							res = num2 + num1;
							break;
		case RESTA:
								res = num2 - num1;
								break;
		case MULTIPLICACION:
												res = num2 * num1;
												break;
		case DIVISION:
										res = num2 / num1;
										break;

	}
	return res;
}

bool es_operador(char* letras){
	if(strlen(letras) != 1)
		return false;
	if(operar((int)*letras, NUM_PRUEBA_1, NUM_PRUEBA_2) == 0)
		return false;
	return true;
}


int main(void){
  size_t capacidad = 0;
  char *linea;
  if(getline(&linea, &capacidad, stdin) == FIN)
		return EXIT_FAILURE;
  pila_t* pila = pila_crear();
  if(!pila)
		return EXIT_FAILURE;
  modificar_caracter(&linea, '\n', '\0');//quito el '\n' al final.

	char **vector = split(linea, ' ');
	double *num1, *num2;
	double *vec_num = malloc(strlen(linea) * sizeof(double));

	for(int i = 0; vector[i]; i++){
		if(es_numero(vector[i])){
			vec_num[i] = strtod(vector[i], NULL);
			pila_apilar(pila, &vec_num[i]);
		}
		else{
			if(es_operador(vector[i])){
				num1 = (double*)pila_desapilar(pila);
				num2 = (double*)pila_desapilar(pila);
				if(!num1 || !num2){
					fprintf(stderr, "Faltan numeros \n" );
					return EXIT_FAILURE;
				}
				vec_num[i] = operar((int)*vector[i], *num1, *num2);
				pila_apilar(pila, &vec_num[i]);
			}
			else{
				fprintf(stderr, "Se deben ingresar numeros y operdadores separados por espacio\n");
				return EXIT_FAILURE;
			}

		}
	}
	num1 = (double*)pila_desapilar(pila);
	if(!pila_esta_vacia(pila)){
		fprintf(stderr, "Se ingresaron más numeros que operaciones \n");
		return EXIT_FAILURE;
	}
	printf("%f \n", *num1);
	pila_destruir(pila);
	free_strv(vector);
	free(vec_num);
	return EXIT_SUCCESS;
}
