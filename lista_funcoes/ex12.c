#include <stdio.h>

void ordem_crescente (int a, int b, int c) {

  if (a > b && b > c){
    printf("\nc = %d b = %d a = %d", c, b, a);
  } else if(a > c && c > b ){
    printf("\nb = %d c = %d a = %d", b, c, a);
  } else if (b > a && a > c){
    printf("\nc = %d a = %d b = %d", c, a, b);
  } else if (b > c && c > a) {
    printf("\na = %d c = %d b = %d", a, c, b);
  } else if (c > a && a > b){
    printf("\nb = %d a = %d c = %d", b, a, c);
  } else if (c > b && b > a){
    printf("\nc = %d b = %d a = %d", a, b, c);
  } 

}

int main () {

  int a, b, c;
  printf("Digite um valor para a: ");
  scanf("%d", &a); 
  printf("Digite um valor para b: "); 
  scanf("%d", &b);
  printf("Digite um valor para c: "); 
  scanf("%d", &c);
  
  ordem_crescente(a, b, c);


  return (0);
}
