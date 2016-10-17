#include "strutil.c"
#include <stdio.h>

int main(void){
  char* str = "Hola palabras";
  char ** vector = split(str, 'l');
  for(int i = 0; i < 3; i++ ){
      free(vector[i]);
  }
  free(vector);
  return 0;
}
