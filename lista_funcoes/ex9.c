#include <stdio.h>

int positivo_negativo (int valor) {

  if(valor > 0){
    printf("\nValor postivo = ");
    return valor;
  }else if(valor < 0){
    printf("\nValor Negativo = ");
    return valor;
  } else {
    printf("\nValor = ");
    return valor;
  }

  return (0);
}

int main () {

  int valor;
  
  printf("\nDigite um valor: ");
  scanf("%d", &valor);

  valor = positivo_negativo(valor);
  printf("%d \n", valor);

  return (0);
}
