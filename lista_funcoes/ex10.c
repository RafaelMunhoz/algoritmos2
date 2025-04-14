#include <stdio.h>

int par_impar (int valor) {

  if(valor % 2 == 0){
    printf("\nValor é par: ");
    return valor;
  }else{
    printf("\nValor é impar: ");
    return valor;
  }
  

  return (0);
}

int main () {

  
  int valor;

  printf("\nDigite um valor: ");
  scanf("%d", &valor);

  valor = par_impar(valor);
  printf("%d\n", valor);



  return (0);
}
