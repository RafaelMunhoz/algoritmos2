#include <stdio.h>
#include <stdbool.h>

bool numero_perfeito (int valor) {
  
  int soma_divisores = 0;
  int i = 0;
  for(int j = 1; j < valor; j++){
    if(valor % j == 0){
      printf("\n j = %d", j);
      soma_divisores += j;
    }
    i++;
  }

  if(valor == soma_divisores){
    return 1;
  } else {
    printf("\n %d \n ", soma_divisores);
    return 0;
  }

}


int main () {

  int valor;

  printf("\nDigite um valor: ");
  scanf("%d", &valor);

  bool verdadeiro_falso = numero_perfeito(valor);
  
  printf("\n %d \n", verdadeiro_falso);

  return (0);
}
