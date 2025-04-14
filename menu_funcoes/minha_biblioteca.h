#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

void escrever_oi (){

  printf("Oi");

}

void escrever_na_tela (char **texto){

  printf("\nTexto : %s\n", *texto);

}

char* retornar_ok(char texto[100]){
  
  printf("\nTexto : %s \n", texto);


  return "Ok";
}

void baskara (int a, int b, int c) {

  int delta; 
  float x1, x2;
  delta = (b * b) - ( 4 * a * c);
  if(delta < 0){
    printf("\n Delta  = %d, não é possível calcular a raiz pois eh negativo", delta);
  } else {
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);
    printf("\n x1 = %.2f e x2 = %.2f \n", x1, x2);
  }
}

void conversao_tempo (int tempo) {

  int horas, minutos, segundos;

  horas = tempo / 3600;
  minutos = (tempo % 3600) / 60;
  segundos = tempo % 60;
  
  printf("\n Valor em HH:MM:SS %02dh:%02dm:%02ds\n", horas, minutos, segundos);

}

void conversao_dias (int ano, int mes, int dia) {

  float dias_anos = 365 * ano;
  float dias_meses =  30 * mes;
  float dias_total = (dias_anos + dias_meses) - (30-dia);

  printf("\n Total em dias : %2.f\n", dias_total);
}

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
  
}int positivo_negativo (int valor) {

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

char* media (float media) {
  
  if(media <= 4.9){
    return "D";
  } else if(media >= 5.0 && media <= 6.9){
    return "C";
  } else if(media >= 7.0 && media <= 8.9){
    return "B";
  } else {
    return "A";
  }
  
}

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

int calcular_potencia (int x, int y) {
  int potencia = 1;	
  for(int i = 0; i < y; i++){
    potencia = potencia * x;
  }

  return potencia;
}
