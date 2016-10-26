#include "lib.h"
#include <stdbool.h>
#include "pila.h"
#include "strutil.h"
#define NUM_PRUEBA_1 1//numeros utilizados en la funcion(es_operador).
#define NUM_PRUEBA_2 3


/* **************************************************************
 *                     FUNCIONES AUXILIARES                     *
 * **************************************************************/

/*Recibe una cadena.
 *Decice si la cadena recibida es un número.
 */
bool es_numero(char* letras){
	char* ptr = NULL;
	double num = strtod(letras, &ptr);
	return strcmp(ptr, "") == 0 && num != 0;
}
/*Recibe dos numeros double y un operador.
 *Realiza el calculo correspondiente al operador, si este es valido.
 *Devuelve el resultado entre los dos numeros o cero si lo ingresado no es un operador valido.
 */
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
/*Recibe una cadena.
 *Decice si la cadena recibida es un operador valido.
 */
bool es_operador(char* letras){
	if(strlen(letras) != 1)
		return false;
	//Mando 2 numeros eligidos de tal forma que se que no van a dar cero si la operacion es valida.
	if(operar((int)*letras, NUM_PRUEBA_1, NUM_PRUEBA_2) == 0)
		return false;
	return true;
}
/*Recibe una pila, un puntero a double y un operador
 *PRE: La pila fue creada
 *POST: devuelve un operador booleano, true si se pudo operar si no false.
 */
bool realizar_operacion(pila_t *pila, double *numero, int operador){
	double *num1 = (double*)pila_desapilar(pila);
	double *num2 = (double*)pila_desapilar(pila);
	if(!num1 || !num2){
		fprintf(stderr, "Faltan numeros para poder operar \n");
		return false;
	}
	*numero = operar(operador, *num1, *num2);
	pila_apilar(pila, numero);
	return true;
}
/*Recibe una pila, un vector de cadenas y un vector de doubles.
 *Destruye los tres parametros recibidos.
 */
void destruir_elementos(pila_t *pila, char **vec_palabras, double *vec_num){
	pila_destruir(pila);
	free_strv(vec_palabras);
	free(vec_num);
}

/* **************************************************************
 *                     FUNCION PRINCIPAL: DC                    *
 * **************************************************************/

int main(void){
  size_t capacidad = 0;
  char *linea = NULL;
	char ** vec_palabras;
	double *num, *vec_num;
	pila_t* pila;
	while(getline(&linea, &capacidad, stdin) != FIN){
		pila = pila_crear();
  	if(!pila)
			return EXIT_FAILURE;
  	modificar_caracter(&linea, '\n', '\0');//quito el '\n' al final.

		vec_palabras = split(linea, ' ');
		vec_num = malloc(strlen(linea) * sizeof(double));

		for(int i = 0; vec_palabras[i]; i++){//verifico que los datos ingresados sean validos y opero
			if(es_numero(vec_palabras[i])){//verifico que sea un número
				vec_num[i] = strtod(vec_palabras[i], NULL);
				pila_apilar(pila, &vec_num[i]);
			}
			else{
				if(es_operador(vec_palabras[i])){//verifico que sea un operador.
					if(!realizar_operacion(pila, &vec_num[i], (int)*vec_palabras[i])){
						destruir_elementos(pila, vec_palabras ,vec_num);
						free(linea);
						return EXIT_FAILURE;
					}
				}
				else{//si no es un numero ni un operador valido, salgo mediante un error.
					destruir_elementos(pila, vec_palabras ,vec_num);
					free(linea);
					fprintf(stderr, "Se deben ingresar numeros y operadadores separados por un espacio \n");
					return EXIT_FAILURE;
				}
			}
		}

		num = (double*)pila_desapilar(pila);
		if(!pila_esta_vacia(pila)){//si quedan numeros en la pila, faltan operadores.
			destruir_elementos(pila, vec_palabras ,vec_num);
			free(linea);
			fprintf(stderr, "Se ingresaron más numeros que operaciones \n");
			return EXIT_FAILURE;
		}
		printf("%f \n", *num);
		destruir_elementos(pila, vec_palabras ,vec_num);
	}
	free(linea);
	return EXIT_SUCCESS;
}
