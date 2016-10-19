#include "strutil.c"
#include <stdio.h>

int main(void){
  char* str = "abc,,def";
  char ** vector = split(str, ',');
  /*for(int i = 0; vector[i] != NULL ; i++ ){
    printf("%s\n", vector[i]);
  }*/
  free_strv(vector);
  return 0;
}
