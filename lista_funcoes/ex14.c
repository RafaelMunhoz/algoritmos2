#include <stdio.h>

int media_aritmetica (int n) {

  int vet[100000];
  int media = 0;
  int soma = 0;
  for(int i = 0; i < n; i++){
    printf("\nDigite um numero: ");
    scanf("%d", &vet[i]);
  }
  
  for(int i = 0; i < n; i++){
    soma += vet[i];
  }
  media = soma / n;
  return media;
}

int main () {
  
  int n;
  
  printf("\nDigite um valor para a quantidade de numeros a ser inseridos: ");
  scanf("%d", &n);

  int media = media_aritmetica(n);
  printf("\nMedia = %d\n", media);

  return (0);
}
