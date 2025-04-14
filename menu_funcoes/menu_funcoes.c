#include <stdio.h>
#include "minha_biblioteca.h"

int main () {
  int valor;
  int sair = 1;
  
  while(sair == 1){
  
  printf ("\n\n\t***Digite 1 para escrever Oi na tela***");
  printf("\n***Digite 2 para funcao que receba um texto por parâmetro e escreva-o na tela***");
  printf("\n***Digite 3 para funcao que receba um texto por parâmetro e escreva-o na tela em seguida retorne “Ok”.");
  printf("\n***Digite 4 para funcao de calcular baskara***");
  printf("\n***Digite 5 para funcao de conversao de tempo***");
  printf("\n***Digite 6 para funcao de coversao de idade com ano/mes/dias para dias***");
  printf("\n***Digite 7 para funcao do numero perfeito***");
  printf("\n***Digite 8 para funcao que recebe a idade de um nadador por parâmetro e retorna, também por parâmetro***");
  printf("\n***Digite 9 para funcao que verifica se valor e positivo ou negativo***");
  printf("\n***Digite 10 para funcao que recebe um valor inteiro e verifica se o valor é par ou ímpar***");
  printf("\n***Digite 11 para funcao que recebe a média final de um aluno por parâmetro e retorna o seu conceito***");
  printf("\n***Digite 12 para funcao que ecebe 3 valores inteiros por parâmetro e imprima-os ordenados em ordem crescente***");
  printf("\n***Digite 13 para funcao que verifica triangulo***");
  printf("\n***Digite 14 para funcao que leia um número não determinado de valores positivos e retorna a média aritmética dos mesmos***");
  printf("\n***Digite 15 para funcao que recebe, por parâmetro, dois valores X e Z e calcula e retorna x elevado a z***\n");
  scanf("%d", &valor);
  
  switch ( valor )
  {
    case 1 :
      
    escrever_oi();
      
    break;
    
    case 2 :
    char *texto;
  
    printf("Digite um texto: ");
    scanf(" %s", texto);

    escrever_na_tela(&texto);
    break;
    
    case 3 :
    
    char texto2[100];
  
    printf("Digite um texto: ");
    scanf(" %s", texto2);
  
    char* ok =  retornar_ok(texto2);
    printf("%s\n", ok);
    break;
    
    case 4 :
    
    int a, b, c;
  
    printf("Formula de baskara\n");
    printf("Digite um valor para a: ");
    scanf("%d", &a);
    printf("\nDigite um valor para b: ");
    scanf("%d", &b);
    printf("\nDigite um valor para c: ");
    scanf("%d", &c);
    
    baskara(a, b, c);
    
    break;
    
    case 5 :
    
    int tempo;
    printf("\nDigite um tempo em segundos: ");
    scanf("%d", &tempo);

    conversao_tempo(tempo);

    break;
    
    case 6 :
    
    float ano, mes, dia;
    printf("\nDigite seu ano de nascimento: ");
    scanf("%f", &ano);
    printf("\nDigite seu mes de nascimento: ");
    scanf("%f", &mes);
    printf("\nDigite seu dia de nascimento: ");
    scanf("%f", &dia);   

    conversao_dias(ano, mes, dia);
    
    break;
    
    case 7 :
    
    int numero;

    printf("\nDigite um valor: ");
    scanf("%d", &numero);

    bool verdadeiro_falso = numero_perfeito(numero);
  
    printf("\n %d \n", verdadeiro_falso);
    
    break;
    
    case 8 :
    
    char *categoria;
    int idade;
    printf("\nDigite uma idade: ");
    scanf("%d", &idade);

    categoria_nadador(idade, &categoria);
    printf("%s\n", categoria);
    
    break;
    
    case 9 :
    
    int numero2;
  
    printf("\nDigite um valor: ");
    scanf("%d", &numero2);

    numero2 = positivo_negativo(numero2);
    printf("%d \n", numero2);
    
    break;
    
    case 10:
    
    int numero3;

    printf("\nDigite um valor: ");
    scanf("%d", &numero3);

    numero3 = par_impar(numero3);
    printf("%d\n", numero3);

    
    break;
    
    case 11 :
    
    float valor_media;
  
    printf("\nDigite uma media: ");
    scanf("%f", &valor_media);

    char* conceito = media(valor_media);
    printf("\n%s\n", conceito);
    
    break;
    
    case 12 :
    
    int numero4, numero5, numero6;
    printf("Digite um valor para a: ");
    scanf("%d", &numero4); 
    printf("Digite um valor para b: "); 
    scanf("%d", &numero5);
    printf("Digite um valor para c: "); 
    scanf("%d", &numero6);
  
    ordem_crescente(numero4, numero5, numero6);
    
    break;
    
    case 13 :
    
    int lado_a, lado_b, lado_c;

    printf("Digite os tres lados do triangulo: ");

    printf("\nLado a: ");
    scanf("%d", &lado_a);

    printf("\nLado b: ");
    scanf("%d", &lado_b);

    printf("\nLado c: ");
    scanf("%d", &lado_c);



  verificar_triangulo(lado_a, lado_b, lado_c);
    
    break;
    
    case 14 :
    
    int n;
  
    printf("\nDigite um valor para a quantidade de numeros a ser inseridos: ");
    scanf("%d", &n);

    int media = media_aritmetica(n);
    printf("\nMedia = %d\n", media);
    
    break;
    
    case 15 : 
    
    int base, expoente;
  
    printf("\nDigite um valor para x: ");
    scanf("%d", &base);
    printf("\nDigite um valor para y: ");
    scanf("%d", &expoente);

    int potencia =  calcular_potencia(base, expoente);
  
    printf("\nBase %d elevado a %d = %d \n", base, expoente, potencia);
    
    break;
    
    default :
    printf ("Valor invalido!\n");
  }
  printf("\nSe deseja continuar no programa digite 1.");
  printf("\nSe deseja sair do programa digite 0.");
  printf("\nDeseja continuar no programa? : ");
  scanf("%d", &sair);

}

  return (0);
}
