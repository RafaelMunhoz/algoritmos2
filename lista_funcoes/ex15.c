#include <stdio.h>

int calcular_potencia (int x, int y) {
  int potencia = 1;	
  for(int i = 0; i < y; i++){
    potencia = potencia * x;
  }

  return potencia;
}


int main () {

  int x, y;
  
  printf("\nDigite um valor para x: ");
  scanf("%d", &x);
  printf("\nDigite um valor para y: ");
  scanf("%d", &y);

  int potencia =  calcular_potencia(x, y);
  
  printf("\nX elevado a y = %d \n", potencia);

  return (0);
}
