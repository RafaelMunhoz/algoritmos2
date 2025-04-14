#include <stdio.h>

void escrever_na_tela (char **texto){

  printf("\nTexto : %s\n", *texto);

}





int main(){

  char *texto;
  
  printf("Digite um texto: ");
  scanf(" %s", texto);

  escrever_na_tela(&texto);


  return (0);
}
