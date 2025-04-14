#include <stdio.h>

char* retornar_ok(char texto[100]){
  
  printf("\nTexto : %s \n", texto);


  return "Ok";
}


int main(){

  char texto[100];
  
  printf("Digite um texto: ");
  scanf(" %s", texto);
  
  char* ok =  retornar_ok(texto);
  printf("%s\n", ok);
 
  return (0);
}
