#include <stdio.h>
#include <stdlib.h>

void verificar_triangulo(int a, int b, int c){

// Verificar se � um tri�ngulo

  if((((a + b > c) && (abs(a-b) < c)) && ((b + c > a) && (abs(b-c) < a))) && (((c + a > b) && (abs(c-a) < b))))

    {

    printf("E um triangulo");

    if((((a==b) && (a!=c)) || ((a==c) && (a!=b))) || (((b==c) && (b!=a))))

      {

      printf(" Isosceles\n");

      }

    if(((a!=b) && (b!=c)) && ((a!=c)))

      {

      printf(" Escaleno\n");

      }

    if((a==b && b==c) && (a==c))

      {

      printf(" Equilatero\n");

      }

    }

  else

    {

    printf("Nao e um trinagulo");

    }


}




int main()

  {

  int a, b, c;



  // Entrada dos lados do tri�ngulo

  printf("Digite os tres lados do triangulo: ");



  printf("\nLado a: ");

  scanf("%d", &a);

  printf("\nLado b: ");

  scanf("%d", &b);

  printf("\nLado c: ");

  scanf("%d", &c);



  verificar_triangulo(a, b, c);

  

  return(0);

}

