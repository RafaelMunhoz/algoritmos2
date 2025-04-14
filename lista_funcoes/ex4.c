#include <stdio.h>
#include <math.h>

void baskara (int a, int b, int c) {

  int delta; 
  int x1, x2;
  delta = (b * b) - ( 4 * a * c);
  x1 = (-b + sqrt(delta)) / (2 * a);
  x2 = (-b - sqrt(delta)) / (2 * a);
  
  printf("\n x1 = %d e x2 = %d \n", x1, x2);
}


int main(){

  int a, b, c;
  
  printf("Formula de baskara\n");
  printf("Digite um valor para a: ");
  scanf("%d", &a);
  printf("\nDigite um valor para b: ");
  scanf("%d", &b);
  printf("\nDigite um valor para c: ");
  scanf("%d", &c);

  baskara(a, b, c);



  return (0);
}
