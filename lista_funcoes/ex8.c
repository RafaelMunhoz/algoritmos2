#include <stdio.h>

void categoria_nadador (int idade, char **categoria){

  if(idade >= 5 && idade <= 7){
    *categoria = "Infantil A";
  }
  if(idade >= 8 && idade <= 10){
    *categoria = "Infantil B";
  }
  if(idade >= 11 && idade <= 13){
    *categoria = "Juvenil A";
  }
  if(idade >= 14 && idade <= 17){
    *categoria = "Juvenil B";
  }else{
    *categoria = "Adulto";
  }
  
}


int main () {
  char *categoria;
  int idade;
  printf("\nDigite uma idade: ");
  scanf("%d", &idade);

  categoria_nadador(idade, &categoria);
  printf("%s\n", categoria);

  return (0);
}
