#include "strutil.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
  //char str[] = ;
  char** vector = split("1,,2,3,,", ',');
  char *palabra = join(vector, '@');
  printf("LA PALABRA : %s\n", palabra );
  free(palabra);
  free_strv(vector);
  return 0;
}
